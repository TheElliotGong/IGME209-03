#include "pch.h"
#include "CppUnitTest.h"
#include "SoundLib.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestSoundFunction)
		{
			int originalValue = nSoundLib;
			fnSoundLib();
			Assert::AreEqual(originalValue - 1, nSoundLib);
		}

		TEST_METHOD(TestGetTeamBadCheck)
		{
			char* test = "Steve";
			char* ret = GetTeam();
			Assert::AreEqual(-1, strcmp(test, ret));
		}
		TEST_METHOD(TestGetTeamEqual)
		{
			char* test = "Steve and Adi";
			char* ret = GetTeam();
			Assert::AreEqual(0, strcmp(test, ret));
		}
	};
}
