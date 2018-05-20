#include <crypto.hpp>



using namespace HWCrypto;

int main(int argc, char *argv[])
{
	Interface obj;
	if (argv[1] == 0)
	{
		std::cout << "Входных данных нет";
		return 0;
	}
	std::string word = argv[1];
	std::string alphabet = "abcdefghijklmnopqrstuvwxyz ";
	int chosenValue;
	if (CorrectInputData(word, alphabet) == 0)
	{
		std::cout << "Некорректный ввод данных. Вводите данные из следующего алфавита - 'abcdefghijklmnopqrstuvwxyz '. ";
		return 0;
	}
	
	Crypto crypto(word, alphabet);

	chosenValue = obj.ChosenFunction();

	obj.MakeDecision(chosenValue, &crypto);

	return 0;
}
