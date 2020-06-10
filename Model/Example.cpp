#include "BernoulliMethodModel.h"
#include "HyperGeomTheoretical.h"
#include "probdist.h"
#include "ChiSquared.h"


/** \file Example.cpp
 * \brief Example file to test essential methods
**/

int main(){

    int nt = 100; //- number of trials for distribution/model
    int a = 6; // - number of white balls
    int b = 5; // - number of black balls
    int k = 5; // - number of taken balls

    ChiSquared chiStat; // -  chi-statistics class member

    int trials = 100; // - number of trials for p-values distribution
    std::vector<double> p_dist; //- p_values distribution

    //Создаем выборку с гипергеометрическим распределением по методу Бернулли с параметрими (6, 5, 5) и объёма nt = 100
    HypogeomModel *model;
    model = new BernoulliMethodModel();
    //Создаем выборку с гипергеометрическим распределением по методу обратных функций с параметрими (6, 5, 5) и объёма nt = 100
    //model = new InverseFunctionMethodModel();

    // столько раз, сколько понадобится для распределения p-values
    for (int l = 0; l < trials; l++) {

        //Создаем гипергеометрическое распределения dist с параметром 6, 5, 5 и объёмом nt = 100
        HyperGeomTheoretical dist;
        dist.setA(a);
        dist.setB(b);
        dist.setK(k);

        //Моделируем значения выборки
        model->createDist(a, b, k, nt, a);

        // ищем статистику хи-квадрат по модели и распределению
        chiStat.computeStatistics(*model, dist, nt);

        // реальная и ожидаемая  частоты
        std::vector<double> actual_freq = chiStat.getActFreq();
        std::vector<double> expected_freq = chiStat.getExpFreq();

        //печатаем ожидаемые и реальные частоты
        std::cout << "Num" << std::setw(30) << "Expected frequencies" << std::setw(30) << "Actual frequencies"  << std::endl;
        for (int i = 0; i < expected_freq.size(); ++i){
                std::cout << i << std::setw(30) << expected_freq[i] << std::setw(30) << actual_freq[i] << '\n';
        }

        p_dist = chiStat.getPDist();
        p_dist.push_back(chiStat.getPValue());

        // печатаем значение статистики хи-квадрат
        std::cout << "Chi-squared: " << chiStat.getChiSq()<< std::endl;

    }

    // построим распределение p-values для статистики хи-квадрат, где  trials - число повторов
    auto hist_p = std::vector<int>(11, 0);
    build_p_dist(hist_p, p_dist, trials);
    p_dist.clear();
    for (int i = 1; i < hist_p.size(); i++){
        p_dist.push_back(((double) hist_p[i - 1]) / trials);
    }

    //печатаем распределения p-values
    for (int i = 1; i < p_dist.size() + 1; i++) {
        std::cout << "[" << (double) (i - 1) / 10 << "," << (double) i / 10 << "] : " << p_dist[i - 1] << std::endl;
    }

    delete (model);
    return 0;
}