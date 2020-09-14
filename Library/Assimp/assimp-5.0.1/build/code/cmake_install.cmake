# Install script for directory: D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/Assimp")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/build/code/Debug/assimp-vc141-mtd.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/build/code/Release/assimp-vc141-mt.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/build/code/MinSizeRel/assimp-vc141-mt.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/build/code/RelWithDebInfo/assimp-vc141-mt.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/build/code/Debug/assimp-vc141-mtd.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/build/code/Release/assimp-vc141-mt.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/build/code/MinSizeRel/assimp-vc141-mt.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/build/code/RelWithDebInfo/assimp-vc141-mt.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xassimp-devx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp" TYPE FILE FILES
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/anim.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/aabb.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/ai_assert.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/camera.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/color4.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/color4.inl"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/build/code/../include/assimp/config.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/defs.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/Defines.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/cfileio.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/light.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/material.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/material.inl"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/matrix3x3.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/matrix3x3.inl"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/matrix4x4.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/matrix4x4.inl"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/mesh.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/pbrmaterial.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/postprocess.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/quaternion.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/quaternion.inl"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/scene.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/metadata.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/texture.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/types.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/vector2.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/vector2.inl"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/vector3.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/vector3.inl"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/version.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/cimport.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/importerdesc.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/Importer.hpp"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/DefaultLogger.hpp"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/ProgressHandler.hpp"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/IOStream.hpp"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/IOSystem.hpp"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/Logger.hpp"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/LogStream.hpp"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/NullLogger.hpp"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/cexport.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/Exporter.hpp"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/DefaultIOStream.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/DefaultIOSystem.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/ZipArchiveIOSystem.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/SceneCombiner.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/fast_atof.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/qnan.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/BaseImporter.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/Hash.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/MemoryIOWrapper.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/ParsingUtils.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/StreamReader.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/StreamWriter.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/StringComparison.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/StringUtils.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/SGSpatialSort.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/GenericProperty.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/SpatialSort.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/SkeletonMeshBuilder.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/SmoothingGroups.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/SmoothingGroups.inl"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/StandardShapes.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/RemoveComments.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/Subdivision.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/Vertex.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/LineSplitter.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/TinyFormatter.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/Profiler.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/LogAux.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/Bitmap.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/XMLTools.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/IOStreamBuffer.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/CreateAnimMesh.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/irrXMLWrapper.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/BlobIOSystem.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/MathFunctions.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/Macros.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/Exceptional.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/ByteSwapper.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xassimp-devx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp/Compiler" TYPE FILE FILES
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/Compiler/pushpack1.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/Compiler/poppack1.h"
    "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/code/../include/assimp/Compiler/pstdint.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/build/code/Debug/assimp-vc141-mtd.pdb")
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "D:/WorkSpace/OpenGLWorkSpace/Library/Assimp/assimp-5.0.1/build/code/RelWithDebInfo/assimp-vc141-mt.pdb")
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
endif()

