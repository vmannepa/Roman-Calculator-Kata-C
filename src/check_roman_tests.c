#include<check.h>


#include<include/roman_to_decimal.h>


START_TEST(test_roman_to_decimal)
{
ck_assert_int_eq(romtodec_convert('I'),1);
}
END_TEST



Suite *roman_suite(void){

	Suite *s;
	TCase *tc_roman;
	s=suite_create("Roman");
	tc_roman = tcase_create("Roman_test_case");
	tcase_add_test(tc_roman,test_roman_to_decimal);
	suite_add_tcase(s,tc_roman);
	return s;
}

int main(void){
	int number_failed;
	Suite *s;
	SRunner *sr;
	s=roman_suite();
	sr=srunner_create(s);
	
	srunner_run_all(sr,CK_NORMAL);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0)? EXIT_SUCCESS:EXIT_FAILURE;

																													
}
