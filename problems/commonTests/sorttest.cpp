
#include <gtest/gtest.h>
#include<common.h>

using ::testing::TestWithParam;
using ::testing::Values;

typedef int TYPE;



class SortVector : public ::testing::TestWithParam<int> {

protected:
 int SIZE = 1000 ;
public:
std::vector<TYPE> v;

void SetUp(){
    srand(time(0));
    SIZE=GetParam();
    int i=1;
    while(i++ <= SIZE)
        v.push_back(rand()%(SIZE*2)+1);
    }

};

INSTANTIATE_TEST_CASE_P(
    size_list,
    SortVector,
    Values(1 , 2 , 3 , 5 , 10 , 100,1000,10000 ,50000  )
//Values( 0 , 1 , 2, 3, 6 )
    );

template<class Container>
bool checksorting(Container& v, bool incremental){
    int prev = v[0];
    auto cmp = incremental ? DS::gt<TYPE> : DS::lt<TYPE>;
    for(int i=1;i<v.size();i++){
        if(cmp(prev,v[i])){
            std::cout<<"error on "<<prev<<" "<<v[i]<<std::endl;
            return false;
        }
        prev = v[i];
    }
    return true;
}

TEST_P(SortVector, quicksort){
    ASSERT_EQ(v.size(),SIZE);

    DS::quicksort(v,0,v.size(),DS::lt<TYPE>);

    ASSERT_EQ(checksorting(v,true),true);
}

TEST_P(SortVector, quicksort_decremental){
    ASSERT_EQ(v.size(),SIZE);
    //DS::print(ALL(v));
    DS::quicksort(v,0,v.size(),DS::gt<TYPE>);
    //DS::print(ALL(v));
    ASSERT_EQ(checksorting(v,false),true);
}


TEST_P(SortVector, mergesort){
    ASSERT_EQ(v.size(),SIZE);
    //DS::print(ALL(v));
    DS::mergesort(v,0,v.size()-1,DS::lt<TYPE>);
    //DS::print(ALL(v));
    ASSERT_EQ(checksorting(v,true),true);
}

TEST_P(SortVector, mergesort_decremental){
    ASSERT_EQ(v.size(),SIZE);
    //DS::print(ALL(v));
    DS::mergesort(v,0,v.size()-1,DS::gt<TYPE>);
    //DS::print(ALL(v));
    ASSERT_EQ(checksorting(v,false),true);
}


TEST_P(SortVector, insertionsort){
    ASSERT_EQ(v.size(),SIZE);
    //DS::print(ALL(v));
    DS::insertionsort(v,0,v.size(),DS::lt<TYPE>);
    //DS::print(ALL(v));
    ASSERT_EQ(checksorting(v,true),true);
}


TEST_P(SortVector, insertionsort_decremental){
    ASSERT_EQ(v.size(),SIZE);
    //DS::print(ALL(v));
    DS::insertionsort(v,0,v.size(),DS::gt<TYPE>);
    //DS::print(ALL(v));
    ASSERT_EQ(checksorting(v,false),true);
}

TEST_P(SortVector, bubblesort){
    ASSERT_EQ(v.size(),SIZE);
    //DS::print(ALL(v));
    DS::bubblesort(ALL(v),DS::lt<TYPE>);
    //DS::print(ALL(v));
    ASSERT_EQ(checksorting(v,true),true);
}


TEST_P(SortVector, bubblesort_decremental){
    ASSERT_EQ(v.size(),SIZE);
    //DS::print(ALL(v));
    DS::bubblesort(ALL(v),DS::gt<TYPE>);
    //DS::print(ALL(v));
    ASSERT_EQ(checksorting(v,false),true);
}



int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

}
