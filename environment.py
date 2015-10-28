

#
# Copyright 2015 Horde Software Inc. All rights reserved.
#

import os

# Load in the HApp environment
fabric2arnoldDir = os.path.dirname(os.path.realpath(__file__))

# Add Horde KL extensions
fabric2arnoldExtPaths = [os.path.join(fabric2arnoldDir, 'exts'), os.path.join(fabric2arnoldDir, 'asynctask', 'exts')]
if 'FABRIC_EXTS_PATH' in os.environ:
    fabric2arnoldExtPaths.append(os.environ['FABRIC_EXTS_PATH'])
os.environ['FABRIC_EXTS_PATH'] = os.pathsep.join(fabric2arnoldExtPaths)

