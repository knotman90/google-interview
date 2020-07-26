#include<iostream>
#include<algorithm>
#include<vector>
#include<random>

using namespace std;

template<class It, class CmpFn>
void quick_sort(const It start, const It end, CmpFn cmp)
{
	if(distance(start, end) <= 1)
		return;

	auto pivot = end-1;
	auto pos_pivot = start;
	for(auto j = start ; j != end ; j++)
	{
		if(cmp(*j, *pivot))
		{
			if(j!= pos_pivot)
				swap(*j, *pos_pivot);
			pos_pivot++;
			
		}
	}
	swap(*pos_pivot, *pivot);

	quick_sort(start, pos_pivot, cmp);
	quick_sort(pos_pivot+1, end, cmp);

}

int main()
{

	const int D = 50000;
	
	vector<int> v(D);
	std::iota(v.begin(), v.end(), 0);
    std::shuffle(v.begin(), v.end(), std::mt19937{std::random_device{}()}); 

    quick_sort(v.begin(), v.end(), std::less<int>());

    if(!is_sorted(v.begin(), v.end()))
    {
    	cout<<"ERROR!"<<endl;
    }else{
    	cout<<"PASS!"<<endl;
    }



	return 0;
}