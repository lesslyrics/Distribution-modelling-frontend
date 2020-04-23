//
// Created by lesslyrics on 20.04.2020.
//

#ifndef DIALOGS_PLOT_H
#define DIALOGS_PLOT_H

void createPlot(int sample_size, std::vector<double> p_dist, std::vector<double> p_dist_alt,  int win_w, int win_h, int trials, QPainter &painter, PType p_type, QString color);
void drawMinors(int i,int win_w, int win_h, double step_x, double step_y, int length, QPainter &painter);
void drawForError(int i, int win_w, int win_h,  double step_x, double step_y, int length, double* p, QPainter &painter);
void drawForPower(int i, int win_w, int win_h,  double step_x, double step_y, int length, const double* p, QPainter &painter);

void drawParams(int sample_size, int win_w, int trials, QPainter &painter, PType p_type );
void createCustom(int sample_size, std::vector<double> p_dist, std::vector<double> p_dist_alt,
                  int win_w, int win_h, int trials, QPainter &painter, PType p_type,  QString color);
void drawParamsCustom(int a, int b, int k, int sample_size_min, int sample_size_med, int sample_size_max,
        int win_w, int trials, QPainter &painter);
void drawAlpha(double alpha, double win_w, double win_h, QPainter &painter);
#endif //DIALOGS_PLOT_H
