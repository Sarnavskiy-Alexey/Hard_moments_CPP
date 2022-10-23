#include "pch.h"

class TestPerson : public testing::Test
{
protected:
	void SetUp() override
	{
		person = new Person;
	}
	void TearDown() override
	{
		delete person;
	}
	Person* person;
};

class TestPhoneNumber : public testing::Test
{
protected:
	void SetUp() override
	{
		phone_number = new PhoneNumber;
	}
	void TearDown() override
	{
		delete phone_number;
	}
	PhoneNumber* phone_number;
};

TEST_F(TestPerson, DZ1_operators)
{
	person->first_name = "Alexey";
	person->last_name = "Sarnavskiy";
	person->patronymic = "Olegovich";
	
	Person p1 = { "Sarnavskiy", "Alexey" , "Olegovich" };
	Person p2 = { "Pushkin", "Alexandr", "Sergeevich" };

	ASSERT_TRUE(p1 == *person);
	ASSERT_TRUE(p2 < *person);
}

TEST_F(TestPhoneNumber, DZ2_opertors)
{
	phone_number->country = 7;
	phone_number->city = 901;
	phone_number->number = "2345678";

	PhoneNumber pn_1 = { 7, 901, "2345678" };
	PhoneNumber pn_2 = { 7, 901, "2345677" };
	PhoneNumber pn_3 = { 7, 901, "2345678", 1 };

	ASSERT_TRUE(pn_1 == *phone_number);
	ASSERT_TRUE(pn_2 < *phone_number);
	ASSERT_TRUE(*phone_number < pn_3);
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");

	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
