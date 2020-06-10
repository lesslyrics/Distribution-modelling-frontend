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
    std::vector<double> p; //- p-values distribution


    //Создаем выборку с гипергеометрическим распределением по методу Бернулли с параметрими (6, 5, 5) и объёма nt = 100
    HypogeomModel *model;
    model = new BernoulliMethodModel();
    //Создаем выборку с гипергеометрическим распределением по методу обратных функций с параметрими (6, 5, 5) и объёма nt = 100
    //model = new InverseFunctionMethodModel();

    std::vector<double> expected_freq; //- expected frequencies to be assigned
    std::vector<double> expected; //- expected frequencies in percentage to be assigned

    // столько раз, сколько понадобится для распределения p-values
    for (int l = 0; l < trials; l++) {

        //Создаем гипергеометрическое распределения dist с параметром 6, 5, 5 и объёмом nt = 100
        HyperGeomTheoretical dist;
        dist.setA(a);
        dist.setB(b);
        dist.setK(k);
        dist.modelTheoreticalDist(nt, expected_freq, expected);

        //Моделируем значения выборки
        model->createDist(a, b, k, nt, a);

        std::vector<double> act_freq_temp = model->getActualFreq();
        // "схлопываем" частоты для удовлетворения критериев применимости хи-квадрат
        // обновляем частоты в класс модели
        model->setActualFreq(act_freq_temp);

        //печатаем ожидаемые и реальные частоты
        // ищем статистику хи-квадрат по модели и ожидаемым частотам
        chiStat.computeStatistics(*model, nt, expected_freq, expected);

        std::cout << "Num" << std::setw(30) << "Expected frequencies" << std::setw(30) << "Actual frequencies"  << std::endl;
        for (int i = 0; i != a + 1; ++i){
            if (expected_freq[i] != -1 )
                std::cout  << i << std::setw(30) << expected_freq[i] << std::setw(30) <<  act_freq_temp[i] << '\n';
        }

        p = chiStat.getPDist();
        p.push_back(chiStat.getPValue());


        // печатаем значение статистики хи-квадрат
        std::cout << "Chi-squared: " << chiStat.getChiSq()<< std::endl;

    }

    // построим распределение p-values для статистики хи-квадрат, где  trials - число повторов
    auto hist_p = std::vector<int>(11, 0);
    build_p_dist(hist_p, p, trials);
    p.clear();
    for (int i = 1; i < hist_p.size(); i++){
        p.push_back(((double) hist_p[i - 1]) / trials);
    }

    //печатаем распределения p-values
    for (int i = 1; i < p.size() + 1; i++) {
        std::cout << "[" << (double) (i - 1) / 10 << "," << (double) i / 10 << "] : " << p[i - 1]<< std::endl;
    }

    delete (model);
    return 0;
}