#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



Mat get_histo(Mat& src){
    int bins = 256;
    int hist_size[] = {bins};
    float range[] = { 0, 256 };
    const float* ranges[] = { range};
    MatND hist_r,hist_g,hist_b;
    int channels_r[] = {0};

    calcHist( &src, 1, channels_r, Mat(), // do not use mask
        hist_r, 1, hist_size, ranges,
        true, // the histogram is uniform
        false );

    int channels_g[] = {1};
    calcHist( &src, 1, channels_g, Mat(), // do not use mask
        hist_g, 1, hist_size, ranges,
        true, // the histogram is uniform
        false );

    int channels_b[] = {2};
    calcHist( &src, 1, channels_b, Mat(), // do not use mask
        hist_b, 1, hist_size, ranges,
        true, // the histogram is uniform
        false );
    double max_val_r,max_val_g,max_val_b;
    minMaxLoc(hist_r, 0, &max_val_r, 0, 0);
    minMaxLoc(hist_g, 0, &max_val_g, 0, 0);
    minMaxLoc(hist_b, 0, &max_val_b, 0, 0);
    int scale = 1;
    int hist_height=256;
    Mat hist_img = Mat::zeros(hist_height,bins*3, CV_8UC3);
    for(int i=0;i<bins;i++)
    {
        float bin_val_r = hist_r.at<float>(i);
        float bin_val_g = hist_g.at<float>(i);
        float bin_val_b = hist_b.at<float>(i);
        int intensity_r = cvRound(bin_val_r*hist_height/max_val_r);
        int intensity_g = cvRound(bin_val_g*hist_height/max_val_g);
        int intensity_b = cvRound(bin_val_b*hist_height/max_val_b);
        rectangle(hist_img,Point(i*scale,hist_height-1),
            Point((i+1)*scale - 1, hist_height - intensity_r),
            CV_RGB(255,0,0));

        rectangle(hist_img,Point((i+bins)*scale,hist_height-1),
            Point((i+bins+1)*scale - 1, hist_height - intensity_g),
            CV_RGB(0,255,0));

        rectangle(hist_img,Point((i+bins*2)*scale,hist_height-1),
            Point((i+bins*2+1)*scale - 1, hist_height - intensity_b),
            CV_RGB(0,0,255));
    }
    return hist_img;
}


void operacionAritmetica(Mat& imagen , int val,  int ope){
     if ( !imagen.data )
    {
        printf("No image data \n");
        return ;
    }
    int f = imagen.rows;
    int c = imagen.cols;
//    cout<<"\nfila: "<<f<<"\ncol: "<<c<<endl;
    Vec3b* imgrow;
    if(ope == 0) {//sumar
        for(int i = 0; i< f; i++){
            imgrow= imagen.ptr<Vec3b>(i);
            for(int j = 0; j < c ; j++){
                imgrow[j][0] = saturate_cast<uchar>(imgrow[j][0] + val);
                imgrow[j][1] = saturate_cast<uchar>(imgrow[j][1] + val);
                imgrow[j][2] = saturate_cast<uchar>(imgrow[j][2] + val);

            }
        }
    }
    else if(ope == 1){//restar
        for(int i = 0; i< f; i++){
            imgrow= imagen.ptr<Vec3b>(i);
            for(int j = 0; j < c ; j++){
                imgrow[j][0] = saturate_cast<uchar>(imgrow[j][0] - val);
                imgrow[j][1] = saturate_cast<uchar>(imgrow[j][1] - val);
                imgrow[j][2] = saturate_cast<uchar>(imgrow[j][2] - val);
            }
        }
    }
    else if(ope == 2){//multiplicar
         float value = ((val)/200.0);//0.0-2.0
        for(int i = 0; i< f; i++){
            imgrow= imagen.ptr<Vec3b>(i);
            for(int j = 0; j < c ; j++){
                imgrow[j][0] = saturate_cast<uchar>(imgrow[j][0] * value);
                imgrow[j][1] = saturate_cast<uchar>(imgrow[j][1] * value);
                imgrow[j][2] = saturate_cast<uchar>(imgrow[j][2] * value);
            }
        }
    }
    else if(ope == 3){//dividir
        float value2 = ((val)/200.0);//0.0-2.0
        for(int i = 0; i< f; i++){
            imgrow= imagen.ptr<Vec3b>(i);
            for(int j = 0; j < c ; j++){
                imgrow[j][0] = saturate_cast<uchar>(imgrow[j][0] / value2);
                imgrow[j][1] = saturate_cast<uchar>(imgrow[j][1] / value2);
                imgrow[j][2] = saturate_cast<uchar>(imgrow[j][2] / value2);
            }
        }
    }
    else{
        cout<<"\nOperacion no definida\n";
        return;
    }
//    cout<<"terminado";

    //namedWindow("OperacionAritmetica", WINDOW_AUTOSIZE );
//    imshow("Operacion", imagen);
//    waitKey(0);

}

void calcular_histograma(Mat his){


}
void MainWindow::on_Abrir_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("chose"), "", tr("Images (*.bmp)"));
    if(QString::compare(filename, QString() ) != 0){
       QImage image;
       bool valido = image.load(filename);

       if(valido){
           image = image.scaledToWidth( ui->imagen_ini->width() , Qt::SmoothTransformation );//para mostrar la imagen con tamanio
           ui->imagen_ini->setPixmap(QPixmap::fromImage(image));
           //copiando a Mat
           imagenCV = imread(filename.toUtf8().constData());

           imagenCV_alter = imagenCV;

           cv::Mat temp(imagenCV_alter.cols,imagenCV_alter.rows,imagenCV_alter.type()); // make the same cv::Mat
           cvtColor(imagenCV_alter,temp ,CV_BGR2RGB);
           QImage alter= QImage((uchar*) temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
           alter = alter.scaledToWidth( ui->imagen_fin->width() , Qt::SmoothTransformation );//para mostrar la imagen con tamanio
           ui->imagen_fin->setPixmap(QPixmap::fromImage(alter));

//           mostrar el histograma de  imagenCV_alter
           imagenCV_histo = get_histo(imagenCV_alter);
           cv::Mat temp_h(imagenCV_histo.cols,imagenCV_histo.rows,imagenCV_histo.type()); // make the same cv::Mat
           cvtColor(imagenCV_histo,temp_h ,CV_BGR2RGB);
           QImage hist= QImage((uchar*) temp_h.data, temp_h.cols, temp_h.rows, temp_h.step, QImage::Format_RGB888);
           hist = hist.scaledToWidth( ui->histograma->width() , Qt::SmoothTransformation );//para mostrar la imagen con tamanio
           ui->histograma->setPixmap(QPixmap::fromImage(hist));
       }
       else {
           //erro de abrir
       }
    }
}

void MainWindow::on_Restaurar_clicked()
{
//    imagenCV_alter = imagenCV;
    imagenCV_alter  =imagenCV.clone();
}



void MainWindow::on_Scroll_sliderMoved(int position)
{
    imagenCV_alter = imagenCV;
    cout <<"**___"<< position<<endl;
     operacionAritmetica(imagenCV_alter, position, opcionB);

    cv::Mat temp(imagenCV_alter.cols,imagenCV_alter.rows,imagenCV_alter.type()); // make the same cv::Mat
    cvtColor(imagenCV_alter,temp ,CV_BGR2RGB);

    QImage alter= QImage((uchar*) temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
    alter = alter.scaledToWidth( ui->imagen_fin->width() , Qt::SmoothTransformation );//para mostrar la imagen con tamanio
    ui->imagen_fin->setPixmap(QPixmap::fromImage(alter));

    //mostrar histograma
    imagenCV_histo = get_histo(imagenCV_alter);
    cv::Mat temp_h(imagenCV_histo.cols,imagenCV_histo.rows,imagenCV_histo.type()); // make the same cv::Mat
    cvtColor(imagenCV_histo,temp_h ,CV_BGR2RGB);
    QImage hist= QImage((uchar*) temp_h.data, temp_h.cols, temp_h.rows, temp_h.step, QImage::Format_RGB888);
    hist = hist.scaledToWidth( ui->histograma->width() , Qt::SmoothTransformation );//para mostrar la imagen con tamanio
    ui->histograma->setPixmap(QPixmap::fromImage(hist));


}

void MainWindow::on_Opcion_activated(int index)
{
    opcionB = index;
    ui->Scroll->scroll(0,0); // = 0;

}






void MainWindow::on_abrir1_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("chose"), "", tr("Images (*.bmp)"));
    if(QString::compare(filename, QString() ) != 0){
       QImage image;
       bool valido = image.load(filename);

       if(valido){
           image = image.scaledToWidth( ui->imagen1->width() , Qt::SmoothTransformation );//para mostrar la imagen con tamanio
           ui->imagen1->setPixmap(QPixmap::fromImage(image));
           //copiando a Mat
           imagenCV1 = imread(filename.toUtf8().constData());
       }
       else {
           //erro de abrir
       }
    }
}

void MainWindow::on_abrir2_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("chose"), "", tr("Images (*.bmp)"));
    if(QString::compare(filename, QString() ) != 0){
       QImage image;
       bool valido = image.load(filename);

       if(valido){
           image = image.scaledToWidth( ui->imagen2->width() , Qt::SmoothTransformation );//para mostrar la imagen con tamanio
           ui->imagen2->setPixmap(QPixmap::fromImage(image));
           //copiando a Mat
           imagenCV2 = imread(filename.toUtf8().constData());
       }
       else {
           //erro de abrir
       }
    }
}

void MainWindow::on_comboBox_activated(int index)
{
    if(index == 0){//sumar
        add(imagenCV1, imagenCV2, imagenCV12, noArray(), -1);
    }
    else if(index == 1){//restar
        subtract(imagenCV1, imagenCV2, imagenCV12, noArray(), -1);
    }
    else if(index == 2){//multiplicar
        multiply(imagenCV1, imagenCV2, imagenCV12, 1.0f, -1);
    }
    else if(index == 3){//dividir
        divide(imagenCV1, imagenCV2, imagenCV12, 1.0f, -1);
    }
    cv::Mat temp(imagenCV12.cols,imagenCV12.rows,imagenCV12.type()); // make the same cv::Mat
    cvtColor(imagenCV12,temp ,CV_BGR2RGB);
    QImage alter= QImage((uchar*) temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
    alter = alter.scaledToWidth( ui->imagen12->width() , Qt::SmoothTransformation );//para mostrar la imagen con tamanio
    ui->imagen12->setPixmap(QPixmap::fromImage(alter));
}

void MainWindow::on_Abrirfc_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("chose"), "", tr("Images (*.bmp)"));
    if(QString::compare(filename, QString() ) != 0){
       QImage image;
       bool valido = image.load(filename);

       if(valido){
           image = image.scaledToWidth( ui->imagenfc->width() , Qt::SmoothTransformation );//para mostrar la imagen con tamanio
           ui->imagenfc->setPixmap(QPixmap::fromImage(image));
           //copiando a Mat
           imagenCVfc = imread(filename.toUtf8().constData());

           imagenCVfcres = imagenCVfc;
           cv::Mat temp(imagenCVfcres.cols,imagenCVfcres.rows,imagenCVfcres.type()); // make the same cv::Mat
           cvtColor(imagenCVfcres,temp ,CV_BGR2RGB);
           QImage alter= QImage((uchar*) temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
           alter = alter.scaledToWidth( ui->imagenfcres->width() , Qt::SmoothTransformation );//para mostrar la imagen con tamanio
           ui->imagenfcres->setPixmap(QPixmap::fromImage(alter));

       }
       else {
           //erro de abrir
       }
    }
}

void MainWindow::on_pushButton_clicked()
{
    Mat kernel = (Mat_<char>(3,3) <<
                                    0, -1, 0,
                                    -1, 5, -1,
                                    0, -1, 0);
       filter2D(imagenCVfc, imagenCVfcres, -1, kernel, Point(-1, -1), 0, BORDER_DEFAULT);
       cv::Mat temp(imagenCVfcres.cols,imagenCVfcres.rows,imagenCVfcres.type()); // make the same cv::Mat
       cvtColor(imagenCVfcres,temp ,CV_BGR2RGB);
       QImage alter= QImage((uchar*) temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
       alter = alter.scaledToWidth( ui->imagenfcres->width() , Qt::SmoothTransformation );//para mostrar la imagen con tamanio
       ui->imagenfcres->setPixmap(QPixmap::fromImage(alter));
}

void MainWindow::on_abrirTransHis_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("chose"), "", tr("Images (*.bmp)"));
    if(QString::compare(filename, QString() ) != 0){
       QImage image;
       bool valido = image.load(filename);

       if(valido){
           image = image.scaledToWidth( ui->transHisto_ini->width() , Qt::SmoothTransformation );//para mostrar la imagen con tamanio
           ui->transHisto_ini->setPixmap(QPixmap::fromImage(image));
           //copiando a Mat
           imagenCVHisto_ini = imread(filename.toUtf8().constData());

           imagenCVHisto_fin = imagenCVHisto_ini;
           cv::Mat temp(imagenCVHisto_fin.cols,imagenCVHisto_fin.rows,imagenCVHisto_fin.type()); // make the same cv::Mat
           cvtColor(imagenCVHisto_fin,temp ,CV_BGR2RGB);
           QImage alter= QImage((uchar*) temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
           alter = alter.scaledToWidth( ui->transHisto_fin->width() , Qt::SmoothTransformation );//para mostrar la imagen con tamanio
           ui->transHisto_fin->setPixmap(QPixmap::fromImage(alter));

       }
       else {
           //erro de abrir
       }
    }
}


void MainWindow::on_Ecualizar_clicked()
{
    Mat src = imagenCVHisto_ini;
    Mat dst;
    cvtColor( src, src, CV_BGR2GRAY );

    /// Apply Histogram Equalization
    equalizeHist( src, dst);

    cv::Mat temp(dst.cols,dst.rows,dst.type()); // make the same cv::Mat
//    cvtColor(dst,temp ,CV_BGR2RGB);
    QImage alter= QImage((uchar*) temp.data, temp.cols, temp.rows, temp.step, QImage::Format_BGR30);
    alter = alter.scaledToWidth( ui->transHisto_fin->width() , Qt::SmoothTransformation );//para mostrar la imagen con tamanio
    ui->transHisto_fin->setPixmap(QPixmap::fromImage(alter));

}
