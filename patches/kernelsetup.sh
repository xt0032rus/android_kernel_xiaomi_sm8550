#!/bin/bash

# Exit immediately if a command exits with a non-zero status.
set -e

# --- Resolve the ROOT directory ---
SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &> /dev/null && pwd)"
ROOT_DIR="$(cd "$SCRIPT_DIR/.." &> /dev/null && pwd)"
echo "--- Running script from: $SCRIPT_DIR"
echo "--- Kernel root directory: $ROOT_DIR"

# Define paths and the specific commit target
KSU_NEXT_DIR="$ROOT_DIR/KernelSU-Next"
KERNEL_DIR="$ROOT_DIR"
PATCH_FILE="$SCRIPT_DIR/latest_ksu.patch"
SUSFS_PATCH_FILE="$SCRIPT_DIR/susfs_1.5.12_kernel.patch"
# TARGET_COMMIT is the specific hash you requested
TARGET_COMMIT="cc10d0429e29a6128a40b86fb69edbc0b70ae643"

# --- Function to patch the local kernel with susfs ---
patch_kernel() {
    echo "--- Option 1: Patching kernel with susfs..."
    cd "$KERNEL_DIR"
    
    if [ ! -f "$SUSFS_PATCH_FILE" ]; then
        echo "ERROR: Susfs patch file not found at '$SUSFS_PATCH_FILE'. Aborting."
        exit 1
    fi
    
    echo "--- Applying 3-way patch: $SUSFS_PATCH_FILE"
    git apply --3way "$SUSFS_PATCH_FILE"
    
    echo ""
    echo "Kernel patched with susfs successfully."
}

# --- Function to download, patch and pin KernelSU-Next to a specific commit ---
setup_ksu_next() {
    echo "--- Option 2: Downloading and patching KernelSU-Next at specific commit ---"

    cd "$ROOT_DIR"

    # Step 1: Manual Clone (Checking if directory exists first)
    if [ -d "$KSU_NEXT_DIR" ]; then
        echo "--- Directory $KSU_NEXT_DIR exists. Cleaning up for a fresh clone..."
        rm -rf "$KSU_NEXT_DIR"
    fi

    echo "--- Cloning KernelSU-Next..."
    git clone https://github.com/KernelSU-Next/KernelSU-Next.git "$KSU_NEXT_DIR"
    
    cd "$KSU_NEXT_DIR"

    # Step 2: Fetch and Reset to the specific commit (cc10d04)
    echo "--- Pinning repository to commit: $TARGET_COMMIT"
    git fetch origin
    git checkout "$TARGET_COMMIT"
    
    # Optional: Verify you are at the right spot
    CURRENT_COMMIT=$(git rev-parse HEAD)
    echo "--- Currently at commit: $CURRENT_COMMIT"

    # Step 3: Apply custom patch from patches/ folder
    if [ ! -f "$PATCH_FILE" ]; then
        echo "ERROR: KSU-Next patch file not found at '$PATCH_FILE'. Skipping patch application."
    else
        echo "--- Applying 3-way patch: $PATCH_FILE"
        git apply "$PATCH_FILE"
        echo "Patch applied successfully."
    fi

    echo ""
    echo "KernelSU-Next is now ready at the requested commit."
}

# --- Main menu ---
echo ""
echo "Please choose an option:"
echo "1) Patch current kernel with susfs"
echo "2) Download and patch KernelSU-Next (Commit cc10d04)"
echo "3) Exit"
echo ""

read -p "Enter your choice [1-3]: " choice

case "$choice" in
  1)
    patch_kernel
    ;;
  2)
    setup_ksu_next
    ;;
  3)
    echo "Exiting."
    exit 0
    ;;
  *)
    echo "Invalid option."
    exit 1
    ;;
esac