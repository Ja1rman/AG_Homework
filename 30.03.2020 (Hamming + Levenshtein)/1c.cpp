//Написать программу для нахождения
//расстояния Хэмминнга
//Расстояния Левенштейна
//Взвешенного расстояния Левенштейна

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

template<typename T>
typename T::size_type GeneralizedLevenshteinDistance(const T &source,
                                                     const T &target,
                                                     typename T::size_type insert_cost,
                                                     typename T::size_type delete_cost,
                                                     typename T::size_type replace_cost) 
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
    std::string target;
    std::string source;
    
    std::cout << "Enter cost of insert, delete and replace:" << '\n';
    int insert_cost, delete_cost, replace_cost;
    std::cin >> insert_cost >> delete_cost >> replace_cost;
    
    std::cin >> target;
    std::cin >> source;
    
    int res = GeneralizedLevenshteinDistance(target, source, insert_cost, delete_cost, replace_cost);
    
    std::cout << res;
    
    return 0;
}
