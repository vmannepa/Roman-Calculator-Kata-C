#include<check.h>


#include<include/roman_to_decimal.h>
#include<include/decimal_to_roman.h>
#include<include/roman_calculator.h>


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

ck_assert_int_eq(romtodec("IX"),9);
ck_assert_int_eq(romtodec("CMCD"),1300);
ck_assert_int_eq(romtodec("IV"),4);
ck_assert_int_eq(romtodec("XL"),40);
ck_assert_int_eq(romtodec("XVII"),17);
ck_assert_int_eq(romtodec("XCIX"),99);
ck_assert_int_eq(romtodec("XLIV"),44);

}
END_TEST
START_TEST(test_roman_to_decimal_numbers_invalid)
{

ck_assert_int_eq(romtodec("IR"),0);
ck_assert_int_eq(romtodec("CMCRII"),0);


}
END_TEST
START_TEST(test_decimal_to_roman_numbers)
{

ck_assert_str_eq(dectorom(9),"IX");
ck_assert_str_eq(dectorom(400),"CD");
ck_assert_str_eq(dectorom(999),"CMXCIX");
ck_assert_str_eq(dectorom(10),"X");
ck_assert_str_eq(dectorom(14),"XIV");

}
END_TEST

START_TEST(test_roman_to_decimal_addition_valid)
{

ck_assert_str_eq(roman_calculator(1,2,'+'),"III");
ck_assert_str_eq(roman_calculator(1,20,'+'),"XXI");
ck_assert_str_eq(roman_calculator(1000,2,'+'),"MII");
ck_assert_str_eq(roman_calculator(900,99,'+'),"CMXCIX");
ck_assert_str_eq(roman_calculator(20,10,'+'),"XXX");
ck_assert_str_eq(roman_calculator(12,3,'+'),"XV");



}
END_TEST
START_TEST(test_roman_to_decimal_subtraction_valid)
{

ck_assert_str_eq(roman_calculator(1,2,'-'),"I");
ck_assert_str_eq(roman_calculator(1,20,'-'),"XIX");
ck_assert_str_eq(roman_calculator(1000,1,'-'),"CMXCIX");
ck_assert_str_eq(roman_calculator(900,99,'-'),"DCCCI");
ck_assert_str_eq(roman_calculator(20,10,'-'),"X");
ck_assert_str_eq(roman_calculator(12,3,'-'),"IX");
ck_assert_str_eq(roman_calculator(1994,1994,'-'),"INVALID");


}
END_TEST

START_TEST(test_roman_to_decimal_symbol_invalid)
{

ck_assert_str_eq(roman_calculator(1,2,'_'),"invalid symbol");
ck_assert_str_eq(roman_calculator(1,20,'='),"invalid symbol");



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
	tcase_add_test(tc_roman,test_roman_to_decimal_numbers_invalid);
	tcase_add_test(tc_roman,test_decimal_to_roman_numbers);
	tcase_add_test(tc_roman,test_roman_to_decimal_addition_valid);
	tcase_add_test(tc_roman,test_roman_to_decimal_subtraction_valid);
	tcase_add_test(tc_roman,test_roman_to_decimal_symbol_invalid);
																																	
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
