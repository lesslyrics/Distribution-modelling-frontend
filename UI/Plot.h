//
// Created by lesslyrics on 20.04.2020.
//

#pragma once
void createCustom_tester(int sample_size, std::vector<double> p_dist, std::vector<double> p_dist_alt,
                         int win_w, int win_h, int trials, QPainter &painter, PType p_type,  QString color);
void createPlot_tester(int sample_size, std::vector<double> p_dist,
                       int win_w, int win_h, int trials, QPainter &painter, PType p_type, QString color);
/**
 * Draw Plot
 **/
void createPlot(int sample_size, std::vector<double> p_dist, std::vector<double> p_dist_alt,  int win_w, int win_h, int trials, QPainter &painter, PType p_type, QString color);

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
 * Draw plot with distributions for 3 sample_sizes
 **/
void createCustom(int sample_size, std::vector<double> p_dist, std::vector<double> p_dist_alt,
                  int win_w, int win_h, int trials, QPainter &painter, PType p_type,  QString color);

/**
 * Draw parameters for the plot with distributions for 3 sample_sizes
 **/
void drawParamsCustom(int a, int b, int k, int sample_size_min, int sample_size_med, int sample_size_max,
        int win_w, int trials, QPainter &painter);

/**
 * Draw alpha level
 **/
void drawAlpha(double alpha, double win_w, double win_h, QPainter &painter);
