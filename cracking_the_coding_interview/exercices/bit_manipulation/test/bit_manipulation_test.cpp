#include <gtest/gtest.h>
#include <bit_manipulation.h>



TEST(bit_manipulation, sum_bit_difference_all_pairs_brute_force_1){
	std::vector<unsigned> V = {1,2};
	auto ans = ctci::sum_bit_difference_all_pairs_brute_force(V);
	ASSERT_EQ(ans , 4);
}


TEST(bit_manipulation, sum_bit_difference_all_pairs_brute_force_2){
	std::vector<unsigned> V = {1,3,5};
	auto ans = ctci::sum_bit_difference_all_pairs_brute_force(V);
	ASSERT_EQ(ans , 8);
}


int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}