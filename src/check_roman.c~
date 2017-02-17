#include<check.h>


#include<include/roman_to_decimal.h>


START_TEST(test_roman_to_decimal)
{
ck_assert_int_eq(romtodec_convert('I'),1);
ck_assert_int_eq(romtodec_convert('V'),5);
ck_assert_int_eq(romtodec_convert('X'),10);
ck_assert_int_eq(romtodec_convert('L'),50);
ck_assert_int_eq(romtodec_convert('C'),100);
ck_assert_int_eq(romtodec_convert('D'),500);
ck_assert_int_eq(romtodec_convert('M'),1000);
}
END_TEST

START_TEST(test_roman_to_decimal_invalid)
{
ck_assert_int_eq(romtodec_convert('Q'),INVALID_NUMERAL);
ck_assert_int_eq(romtodec_convert('W'),INVALID_NUMERAL);
ck_assert_int_eq(romtodec_convert('E'),INVALID_NUMERAL);
}
END_TEST

START_TEST(test_roman_to_decimal_numbers)
{

ck_assert_int_eq(romtodec("IX\0"),9);
ck_assert_int_eq(romtodec("CMCD\0"),1300);
ck_assert_int_eq(romtodec("IV\0"),4);
ck_assert_int_eq(romtodec("XL\0"),40);
ck_assert_int_eq(romtodec("XVII\0"),17);
ck_assert_int_eq(romtodec("XCIX\0"),99);
ck_assert_int_eq(romtodec("XLIV\0"),44);

}
END_TEST

Suite *roman_suite(void){

	Suite *s;
	TCase *tc_roman;
	s=suite_create("Roman");
	tc_roman = tcase_create("Roman_test_case");
	tcase_add_test(tc_roman,test_roman_to_decimal);
	tcase_add_test(tc_roman,test_roman_to_decimal_invalid);
	tcase_add_test(tc_roman,test_roman_to_decimal_numbers);
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
