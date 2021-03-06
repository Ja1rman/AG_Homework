//Считаем стоимость операции добавления буквы - 15, удаления - 20, замены буквы на другую - 12. 
//Вычислить минимальную стоимость преобразования первого предложения 1 главы романа "Война и Мир" во второе и обратно.
//(можно и нужно делать с помощью реализованного алгоритма Вагнера-Фишера из задачи 1)
  
//Ответ: 1485


#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

template<typename T>
typename T::size_type GeneralizedLevenshteinDistance(const T &source,
                                                     const T &target,
                                                     typename T::size_type insert_cost = 15,
                                                     typename T::size_type delete_cost = 20,
                                                     typename T::size_type replace_cost = 12) 
{
    if (source.size() > target.size()) return GeneralizedLevenshteinDistance(target, source, delete_cost, insert_cost, replace_cost);

    using TSizeType = typename T::size_type;
    const TSizeType min_size = source.size(), max_size = target.size();
    std::vector<TSizeType> lev_dist(min_size + 1);

    lev_dist[0] = 0;
    for (TSizeType i = 1; i <= min_size; ++i) lev_dist[i] = lev_dist[i - 1] + delete_cost;

    for (TSizeType j = 1; j <= max_size; ++j) 
    {
        TSizeType previous_diagonal = lev_dist[0], previous_diagonal_save;
        lev_dist[0] += insert_cost;

        for (TSizeType i = 1; i <= min_size; ++i) 
        {
            previous_diagonal_save = lev_dist[i];
            
            if (source[i - 1] == target[j - 1]) lev_dist[i] = previous_diagonal;
            else lev_dist[i] = std::min(std::min(lev_dist[i - 1] + delete_cost, lev_dist[i] + insert_cost), previous_diagonal + replace_cost);
            
            previous_diagonal = previous_diagonal_save;
        }
    }

    return lev_dist[min_size];
}

int main()
{
    std::string target = "Well, Prince, so Genoa and Lucca are now just family estates of the Buonapartes.";
    std::string source = "But I warn you, if you don’t tell me that this means war, if you still try to defend the infamies and horrors perpetrated by that Antichrist.";
    
    //std::cin >> target;
    //std::cin >> source;
    
    int res = GeneralizedLevenshteinDistance(target, source);
    
    std::cout << res;
    
    return 0;
}
