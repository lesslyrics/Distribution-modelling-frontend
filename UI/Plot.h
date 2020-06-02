//
// Created by lesslyrics on 20.04.2020.
//

#pragma once


/**
 * Draw Plot
 **/
void createPlot(std::vector<double> p_dist, int win_w, int win_h, QPainter &painter, PType p_type, QString color);
/**
 * Draw minor details
 **/
void drawMinors(int i,int win_w, int win_h, double step_x, double step_y, int length, QPainter &painter);

/**
 * Draw specifications for type 1 error
 **/
void drawForError(int i, int win_w, int win_h,  double step_x, double step_y, int length, double* p, QPainter &painter);

/**
 * Draw specifications for power
 **/
void drawForPower(int i, int win_w, int win_h,  double step_x, double step_y, int length, const double* p, QPainter &painter);

/**
 * Draw parameters
 **/
void drawParams(int sample_size, int win_w, int trials, QPainter &painter, PType p_type );


/**
 * Draw parameters for the plot with distributions for 3 sample_sizes
 **/
void drawParamsCustom(int a, int b, int k, int sample_size_min, int win_w, int trials, QPainter &painter);
/**
 * Draw alpha level
 **/
void drawAlpha(double alpha, double win_w, double win_h, QPainter &painter);

/**
 * Draw minor details different sample_sizes
 **/
void drawMinorsCustom(int i,int win_w, int win_h, double step_x, double step_y, int length, QPainter &painter, int sample_size);
/**
 * Draw plot with distributions for different sample_sizes
 **/
void createCustomPlot(std::vector<double> p_dist, int win_w, int win_h, QPainter &painter, PType p_type, QString color, int sample_size);
