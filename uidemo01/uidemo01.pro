#-------------------------------------------------
#
# Project created by QtCreator 2017-05-24T18:38:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET      = uidemo01
TEMPLATE    = app
MOC_DIR     = temp/moc
RCC_DIR     = temp/rcc
UI_DIR      = temp/ui
OBJECTS_DIR = temp/obj
DESTDIR     = $$PWD/../bin

SOURCES     += main.cpp \
    pages.cpp
SOURCES     += iconhelper.cpp
SOURCES     += appinit.cpp
SOURCES     += uidemo01.cpp

HEADERS     += iconhelper.h \
    pages.h
HEADERS     += appinit.h
HEADERS     += uidemo01.h

FORMS       += uidemo01.ui

RESOURCES   += main.qrc
RESOURCES   += qss.qrc
CONFIG      += qt warn_off
INCLUDEPATH += $$PWD

INCLUDEPATH += "D:\VTK\vtk_install\include\vtk-8.2"
INCLUDEPATH += "D:\VTK\vtk_install\include\vtk-8.2\vtkhdf5"

win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkChartsCore-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkCommonColor-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkCommonComputationalGeometry-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkCommonCore-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkCommonDataModel-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkCommonExecutionModel-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkCommonMath-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkCommonMisc-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkCommonSystem-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkCommonTransforms-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkDICOMParser-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkDomainsChemistry-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkDomainsChemistryOpenGL2-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkdoubleconversion-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkexodusII-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkexpat-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkFiltersAMR-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkFiltersCore-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkFiltersExtraction-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkFiltersFlowPaths-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkFiltersGeneral-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkFiltersGeneric-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkFiltersGeometry-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkFiltersHybrid-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkFiltersHyperTree-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkFiltersImaging-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkFiltersModeling-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkFiltersParallel-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkFiltersParallelImaging-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkFiltersPoints-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkFiltersProgrammable-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkFiltersSelection-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkFiltersSMP-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkFiltersSources-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkFiltersStatistics-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkFiltersTexture-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkFiltersTopology-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkFiltersVerdict-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkfreetype-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkGeovisCore-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkgl2ps-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkglew-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkGUISupportQt-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkGUISupportQtSQL-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkhdf5-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkhdf5_hl-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkImagingColor-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkImagingCore-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkImagingFourier-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkImagingGeneral-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkImagingHybrid-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkImagingMath-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkImagingMorphological-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkImagingSources-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkImagingStatistics-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkImagingStencil-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkInfovisCore-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkInfovisLayout-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkInteractionImage-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkInteractionStyle-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkInteractionWidgets-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkIOAMR-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkIOAsynchronous-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkIOCityGML-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkIOCore-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkIOEnSight-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkIOExodus-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkIOExport-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkIOExportOpenGL2-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkIOExportPDF-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkIOGeometry-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkIOImage-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkIOImport-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkIOInfovis-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkIOLegacy-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkIOLSDyna-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkIOMINC-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkIOMovie-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkIONetCDF-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkIOParallel-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkIOParallelXML-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkIOPLY-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkIOSegY-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkIOSQL-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkIOTecplotTable-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkIOVeraOut-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkIOVideo-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkIOXML-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkIOXMLParser-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkjpeg-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkjsoncpp-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtklibharu-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtklibxml2-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtklz4-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtklzma-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkmetaio-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkNetCDF-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkogg-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkParallelCore-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkpng-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkproj-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkpugixml-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkRenderingAnnotation-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkRenderingContext2D-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkRenderingContextOpenGL2-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkRenderingCore-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkRenderingFreeType-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkRenderingGL2PSOpenGL2-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkRenderingImage-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkRenderingLabel-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkRenderingLOD-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkRenderingOpenGL2-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkRenderingQt-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkRenderingVolume-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkRenderingVolumeOpenGL2-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtksqlite-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtksys-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkTestingGenericBridge-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkTestingIOSQL-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkTestingRendering-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtktheora-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtktiff-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkverdict-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkViewsContext2D-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkViewsCore-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkViewsInfovis-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkViewsQt-8.2.lib)
win32:LIBS += $$quote(D:\VTK\vtk_install\lib\vtkzlib-8.2.lib)
