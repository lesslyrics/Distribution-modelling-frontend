/**
\file
\author @lesslyrics (Alina Boshchenko)
\brief UI header file for the histogram

Contains methods needed for the plot and custom plot with parameters construction
**/
#pragma once

 /**
  * Draw Plot
  * @param p_dist
  * @param win_w
  * @param win_h
  * @param painter
  * @param p_type
  * @param color
  */
void createPlot(std::vector<double> p_dist, int win_w, int win_h, QPainter &painter, PType p_type, QString color);

 /**
  * Draw minor details
  * @param i
  * @param win_w
  * @param win_h
  * @param step_x
  * @param step_y
  * @param length
  * @param painter
  */
void drawMinors(int i,int win_w, int win_h, double step_x, double step_y, int length, QPainter &painter);


 /**
  * Draw specifications for type 1 error
  * @param i
  * @param win_w
  * @param win_h
  * @param step_x
  * @param step_y
  * @param length
  * @param p
  * @param painter
  */
void drawForError(int i, int win_w, int win_h,  double step_x, double step_y, int length, double* p, QPainter &painter);

 /**
  * Draw specifications for power
  * @param i
  * @param win_w
  * @param win_h
  * @param step_x
  * @param step_y
  * @param length
  * @param p
  * @param painter
  */
void drawForPower(int i, int win_w, int win_h,  double step_x, double step_y, int length, const double* p, QPainter &painter);


 /**
  * Draw parameters
  * @param sample_size
  * @param win_w
  * @param trials
  * @param painter
  * @param p_type
  */
void drawParams(int sample_size, int win_w, int trials, QPainter &painter, PType p_type );


 /**
  * Draw parameters for the plot with distributions for 3 sample_sizes
  * @param a
  * @param b
  * @param k
  * @param sample_size_min
  * @param win_w
  * @param trials
  * @param painter
  */
void drawParamsCustom(int a, int b, int k, int sample_size_min, int win_w, int trials, QPainter &painter);

 /**
  * Draw alpha level
  * @param alpha
  * @param win_w
  * @param win_h
  * @param painter
  */
void drawAlpha(double alpha, double win_w, double win_h, QPainter &painter);

 /**
  *  Draw minor details different sample_sizes
  * @param i
  * @param win_w
  * @param win_h
  * @param step_x
  * @param step_y
  * @param length
  * @param painter
  * @param sample_size
  */
void drawMinorsCustom(int i,int win_w, int win_h, double step_x, double step_y, int length, QPainter &painter, int sample_size);

 /**
  * Draw plot with distributions for different sample_sizes
  * @param p_dist
  * @param win_w
  * @param win_h
  * @param painter
  * @param p_type
  * @param color
  * @param sample_size
  */
void createCustomPlot(std::vector<double> p_dist, int win_w, int win_h, QPainter &painter, PType p_type, QString color, int sample_size);
