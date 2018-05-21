#include <string>
#include <iostream>
#include <vector>
namespace HWCrypto
	{
	class Crypto
	{
		public:
		Crypto();
		Crypto(std::string word, std::string alphabet);
		void MethodCaesar();
		void MethodSlogan();
		void MethodVizhiner();
		void MethodGamma();
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
