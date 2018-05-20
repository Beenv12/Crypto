#include <string>
#include <iostream>

namespace HWCrypto
	{
	class Crypto
	{
		public:
		Crypto();
		Crypto(std::string word, std::string alphabet);
		void MethodCaesar();
		void MethodSlogan();
		~Crypto();
		private:
		std::string cryptoword;
		std::string cryptoalphabet;
	};

	class Interface
	{
		public:
		int ChosenFunction();
		void MakeDecision(int chosenValue, Crypto *crypto);
	};
	bool  CorrectInputData(std::string word, std::string alphabet);

}
