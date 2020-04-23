//
// Created by lesslyrics on 20.04.2020.
//

#ifndef DIALOGS_PLOT_H
#define DIALOGS_PLOT_H

void createPlot(int sample_size, std::vector<double> p_dist, std::vector<double> p_dist_alt,  int win_w, int win_h, int trials, QPainter &painter, PType p_type);
void drawMinors(int i,int win_w, int win_h, double step_x, double step_y, int length, QPainter &painter);
void drawForError(int i, int win_w, int win_h,  double step_x, double step_y, int length, double* p, QPainter &painter);
void drawForPower(int i, int win_w, int win_h,  double step_x, double step_y, int length, const double* p, QPainter &painter);


#endif //DIALOGS_PLOT_H
