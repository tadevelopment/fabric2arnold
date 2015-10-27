F2A_DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
FABRIC_EXTS_PATH=$FABRIC_EXTS_PATH:$F2A_DIR/stage:$F2A_DIR/asynctask/exts
export FABRIC_EXTS_PATH
