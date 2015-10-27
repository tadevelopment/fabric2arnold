#
# Fabric Engine 2.1.0-alpha
# EDKObjects EDK Sample
#
# Copyright 2010-2015 Fabric Software Inc. All rights reserved.
#

import os, sys, glob, platform

try:
  fabricPath = os.environ['FABRIC_DIR']
except:
  print "You must set FABRIC_DIR in your environment."
  print "Refer to README.txt for more information."
  sys.exit(1)

try:
  arnoldPath = os.environ['ARNOLD_DIR']
except:
  print "You must set ARNOLD_DIR in your environment."
  print "Refer to README.txt for more information."
  sys.exit(1)


SConscript('SConscript')
Import('fabricBuildEnv')

fabricBuildEnv.Append(CPPPATH = [
  arnoldPath + '/include',
  'GenCPP/h'
  ])

if platform.system() == 'Windows':
  fabricBuildEnv.Append(LIBPATH = [
    arnoldPath + "/lib",
    ])
  fabricBuildEnv.Append(LIBS = [
    "ai.lib",
    ])
else:
  fabricBuildEnv.Append(LIBPATH = [
    arnoldPath + "/bin",
    ])
  fabricBuildEnv.Append(LIBS = [
    "libai.so",
    ])

  fabricBuildEnv.Append( RPATH = fabricBuildEnv.Literal('\\$$ORIGIN'))
  #fabricBuildEnv.Append(RPATH='$ORIGIN')

cppFiles = glob.glob('./GenCPP/cpp/*.cpp')
dll = fabricBuildEnv.Extension(
  'Fabric2Arnold',
  cppFiles
  )

# Copy relevant files into stage directory
stage_dir = './stage/Fabric2Arnold'
kl_files = glob.glob('./GenKL/*.kl')
fpm_file = glob.glob('./GenKL/Fabric2Arnold.fpm.json')

fabricBuildEnv.Install(stage_dir, dll)
fabricBuildEnv.Install(stage_dir, kl_files)
fabricBuildEnv.Install(stage_dir, fpm_file)
fabricBuildEnv.Install(stage_dir, arnoldPath + '/bin/ai.dll')

# set our file paths to be relative to the proj directory
hFiles = glob.glob('./GenCPP/h/*.h')
for i in range(len(cppFiles)):
  cppFiles[i] = cppFiles[i].replace('\\', '/')
  cppFiles[i] = os.path.relpath(cppFiles[i], './GenCPP')

for i in range(len(hFiles)):
  hFiles[i] = hFiles[i].replace('\\', '/')
  hFiles[i] = os.path.relpath(hFiles[i], './GenCPP')

# Build a VS project to go along with this dll
# We can use this for debugging the project later.
fabricBuildEnv.MSVSProject(target = './GenCPP/Fabric2Arnold' + fabricBuildEnv['MSVSPROJECTSUFFIX'],
                srcs = cppFiles,
                incs = hFiles,
                buildtarget = dll[0],
                variant = 'Debug|x64')

