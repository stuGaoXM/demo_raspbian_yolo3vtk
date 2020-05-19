#ifndef UIDEMO01_H
#define UIDEMO01_H
#include <vtkSmartPointer.h>
#include <vtkXMLPolyDataReader.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkInteractorStyle.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkMetaImageReader.h>
#include <vtkImageCast.h>
//#include <vtkVolumeRayCastCompositeFunction.h>
#include <vtkGPUVolumeRayCastMapper.h>
#include <vtkFixedPointVolumeRayCastMapper.h>
#include <vtkVolumeProperty.h>
#include <vtkPiecewiseFunction.h>
#include <vtkColorTransferFunction.h>
#include <vtkVolume.h>
#include <vtkProperty.h>
#include <vtkImageData.h>
#include <vtkTransform.h>
#include <vtkLinearTransform.h>
#include <vtkMatrix4x4.h>
#include <vtkImageReslice.h>
#include <vtkImageActor.h>
#include <vtkInteractorStyleImage.h>
#include <vtkPlane.h>
#include <vtkImagePlaneWidget.h>
#include <vtkCommand.h>
#include <vtkCamera.h>
#include <vtkWidgetEventTranslator.h>
#include <vtkCutter.h>
#include <vtkImageData.h>
#include<vtkPolyDataNormals.h>
#include<vtkImplicitPlaneWidget2.h>
//Qt

#include <QVTKOpenGLWidget.h>
#include <qfileinfo.h>
#include <qtimer.h>
#include <qevent.h>
#include <QDialog>
#include <QtWidgets>
#include <pages.h>

namespace Ui {
class UIDemo01;
}

class QVTKWidget;
class vtkPlaneCallback;
class UIDemo01 : public QDialog
{
    Q_OBJECT

public:
    explicit UIDemo01(QWidget *parent = 0);
    ~UIDemo01();

protected:
    bool eventFilter(QObject *watched, QEvent *event);
    void resizeEvent(QResizeEvent * event);
private:
    Ui::UIDemo01 *ui;
    QStackedWidget stackedWidget;
    Page1 *page1;//OPEN
    Page2 *page2;//PRE
    Page3 *page3;//YOLO
    Page4 *page4;//VTK
    QImage image;
    //QLabel label2;
    vtkSmartPointer<vtkRenderer> m_Renderer;
    vtkSmartPointer<vtkMetaImageReader>m_pMetaImageReader;
    vtkSmartPointer<vtkRenderWindowInteractor> m_VolumeInteractor;
    //vtkSmartPointer<vtkImageReslice> m_vReslice;
    //vtkSmartPointer<vtkRenderWindowInteractor>m_vImageInteractor;
    vtkPlaneCallback *m_PlaneCallback;
    vtkSmartPointer<vtkImagePlaneWidget>m_pPlaneX;
    vtkSmartPointer<vtkImagePlaneWidget>m_pPlaneY;
    vtkSmartPointer<vtkImagePlaneWidget>m_pPlaneZ;
    QTimer *m_pTimer;
    vtkSmartPointer<vtkImageReslice>m_pImageReslice;
    vtkSmartPointer<vtkRenderer>m_pRenderer_1;
    std::vector<QVTKOpenGLWidget*> m_vQvtkWidget;
    bool m_bThreePlaneOn;
    std::vector<vtkSmartPointer<vtkImagePlaneWidget>> m_vPlaneWidget;


    std::vector<vtkSmartPointer<vtkPolyData>>m_vVtpPolyData;
    std::vector<vtkSmartPointer<vtkActor>>m_vVTPActor;
    std::vector<vtkSmartPointer<vtkImageReslice>>m_vReslice;
    std::vector<vtkSmartPointer<vtkRenderWindowInteractor>> m_vImageInteractor;
    std::vector<vtkSmartPointer<vtkRenderer> >m_vImageRenderer;
    std::vector<vtkSmartPointer<vtkImageActor> >m_vImageActor;
    std::vector<vtkSmartPointer<vtkPlane>>m_vPlane;
    std::vector<vtkSmartPointer<vtkActor> >m_vCutterActor;
    std::string m_FileName;

private slots:
    void initForm();
    void buttonClick();
    void OpenImg();
    QImage* Erosiontiongary(QImage* image, int k);
    QImage* Erosiontionrgb(QImage* image);
    QImage* Dilationgary(QImage* image, int k);
    QImage* Dilationrgb(QImage* image);
    QImage*SideInner(QImage* image);
    QImage*SideOutter(QImage* image);
    QImage*SideIO(QImage* image);
    QImage* Opening(QImage* image);
    QImage* Closing(QImage* image);

private slots:
    void on_btnMenu_Min_clicked();
    void on_btnMenu_Max_clicked();
    void on_btnMenu_Close_clicked();
    void OnOpenButton2Clicked();
    void OnThreePlaneButtonClicked();
    void ReadVtkFile(char difsuff);
    void DisplaySlice(const std::vector<vtkSmartPointer<vtkImagePlaneWidget>>& vPlaneWidget);
    void DisplayContours(const std::vector<vtkSmartPointer<vtkImagePlaneWidget> >& vPlaneWidget);
    void SetCamera(vtkSmartPointer<vtkImageActor> actor, vtkSmartPointer<vtkRenderer> renderer);

};
class vtkPlaneCallback : public vtkCommand
{
public:
vtkPlaneCallback() {}
~vtkPlaneCallback(){}
static vtkPlaneCallback *New()
{
    return new vtkPlaneCallback;
}

void SetImageReslice(std::vector<vtkSmartPointer<vtkImageReslice> > reslice)
{
    this->m_vCbReslice = reslice;
}

void SetPlaneWidget(std::vector<vtkSmartPointer<vtkImagePlaneWidget> > planeZ)
{
    this->m_vCbPlaneWidget = planeZ;
}

void SetInteractor(std::vector<vtkSmartPointer<vtkRenderWindowInteractor> > interactor)
{
    this->m_vInteractor = interactor;
}

void SetPlane(std::vector<vtkSmartPointer<vtkPlane> > plane)
{
    this->m_vCbPlane = plane;
}

void SetvtpPolydata(std::vector<vtkSmartPointer<vtkPolyData> > vtpPolyData)
{
    this->m_vCbPolyData = vtpPolyData;
}

void SetActor(std::vector<vtkSmartPointer<vtkActor> > cutterActor)
{
    this->m_vCbCutterActor = cutterActor;
}

void SetRenderer(std::vector<vtkSmartPointer<vtkRenderer> > imageRenderer)
{
    this->m_vCbImageRenderer = imageRenderer;
}

void SetQvtkWidget(std::vector <QVTKOpenGLWidget* > qvtkwidget)
{
    this->m_vCbQvtkWidget = qvtkwidget;
}

void Execute(vtkObject *caller, unsigned long vtkNotUsed(event), void *callData) VTK_OVERRIDE
{
    for (int i = 0; i < m_vCbPlaneWidget.size(); ++i)
    {
        m_vCbReslice[i]->SetResliceAxesOrigin(m_vCbPlaneWidget[i]->GetCenter());//获取切片轴心
        m_vCbReslice[i]->Update();//缺少该句qvtkwidget将不能动态显示

        //m_vCbPlane[i]->GetOrigin(m_vCbPlaneWidget[i]->GetOrigin());
        //m_vCbPlane[i]->GetNormal(m_vCbPlaneWidget[i]->GetNormal());
        //m_vInteractor[i]->Render();
        //------------------------------------------------------------------------------------------------
        vtkSmartPointer <vtkPlane> plane = vtkSmartPointer <vtkPlane>::New();
        plane->SetOrigin(m_vCbPlaneWidget[i]->GetOrigin());
        plane->SetNormal(m_vCbPlaneWidget[i]->GetNormal());



        for (int j = 0; j < m_vCbPolyData.size(); ++j)
        {
            vtkSmartPointer<vtkCutter> cutter = vtkSmartPointer<vtkCutter>::New();
            cutter->SetCutFunction(plane);
            cutter->SetInputData(m_vCbPolyData[j]);
            cutter->Update();

            vtkSmartPointer<vtkPolyDataMapper> cutterMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
            cutterMapper->SetInputConnection(cutter->GetOutputPort());
            cutterMapper->Update();

            m_vCbCutterActor[i * m_vCbPolyData.size() + j]->SetMapper(cutterMapper);

            vtkSmartPointer<vtkTransform> transform = vtkSmartPointer<vtkTransform>::New();

            if (m_vCbPlaneWidget[i]->GetNormal()[2] == 1)
            {
                transform->Translate(m_vCbPlaneWidget[i]->GetCenter());
                transform->RotateX(180);
                transform->Translate(0, 0, -0.1);
                transform->Inverse();

                m_vCbCutterActor[i * m_vCbPolyData.size() + j]->SetUserMatrix(transform->GetMatrix());
            }
            else if (m_vCbPlaneWidget[i]->GetNormal()[0] == 1)
            {
                transform->Translate(m_vCbPlaneWidget[i]->GetCenter());
                transform->RotateY(90);
                transform->RotateZ(90);
                transform->Translate(0, 0, -0.1);
                transform->Inverse();

                m_vCbCutterActor[i * m_vCbPolyData.size() + j]->SetUserMatrix(transform->GetMatrix());
            }
            else if (m_vCbPlaneWidget[i]->GetNormal()[1] == 1)
            {
                transform->Translate(m_vCbPlaneWidget[i]->GetCenter());
                transform->RotateX(90);
                transform->Translate(0, 0, -0.1);
                transform->Inverse();

                m_vCbCutterActor[i * m_vCbPolyData.size() + j]->SetUserMatrix(transform->GetMatrix());
            }
            //------------------------------------------------------------------------------------------------
            //qDebug() << "m_vReslice size: " << m_vCbReslice.size();
            //qDebug() << "m_vCbPlane size: " << m_vCbPlane.size();
            //qDebug() << "m_vCbQvtkWidget size: " << m_vCbQvtkWidget.size();
        }
        m_vInteractor[i]->Render();
        //m_vCbImageRenderer[i]->Render();
    }
}

private:
 std::vector<vtkSmartPointer<vtkImageReslice>> m_vCbReslice;
 std::vector<vtkSmartPointer<vtkImagePlaneWidget>> m_vCbPlaneWidget;
 std::vector<vtkSmartPointer<vtkRenderWindowInteractor>> m_vInteractor;
 std::vector<vtkSmartPointer<vtkPlane>> m_vCbPlane;
 std::vector<vtkSmartPointer<vtkPolyData>> m_vCbPolyData;
 std::vector<vtkSmartPointer<vtkRenderer>> m_vCbImageRenderer;
 std::vector<vtkSmartPointer<vtkActor>> m_vCbCutterActor;
 std::vector <QVTKOpenGLWidget* > m_vCbQvtkWidget;
};

#endif // UIDEMO01_H
