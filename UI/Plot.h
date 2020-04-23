//
// Created by lesslyrics on 20.04.2020.
//

#ifndef DIALOGS_PLOT_H
#define DIALOGS_PLOT_H

void createPlot(int sample_size, std::vector<double> p_dist, int win_w, int win_h, int trials, QPainter &painter);
void drawMinors(int i,int win_w, int win_h, int trials, int step_x, int step_y, int length, QPainter &painter);
#endif //DIALOGS_PLOT_H
