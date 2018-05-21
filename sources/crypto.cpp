#include <crypto.hpp>
 
namespace HWCrypto
{
	Crypto::Crypto(){};
	Crypto::Crypto(std::string word, std::string alphabet)
	{
		cryptoword = word;
		cryptoalphabet = alphabet;
	};
	Crypto::~Crypto(){};
	void Crypto::MethodCaesar()
	{
		int select = 0;
		int key = 0;
		int correct=0;
		std::cout << "1. Шифрование" << std::endl;
		std::cout << "2. Дешифрование" << std::endl;
		std::cin >> select;
		while (select < 1 || select > 2)
		{
			std::cout << "Error: некорректное значение." << std::endl;
			std::cin >> select;
		}
		// Ввод ключа. Если введен не корректно, то завершаем программу.
		std::cout << "Введите ключ" << std::endl;
		if (std::cin >> key)
			std::cout << "Ключ - ";
		else
		{
			std::cout << "Error: некорректное значение. Ключ состоит из целых чисел.";
			exit(0);
		}
		// Шифр Цезаря.
		switch (select)
		{
			case 1:
			{
				for (int i = 0; i < cryptoword.size(); ++i)
					for (int j = 0; j < cryptoalphabet.size(); ++j)
						if (cryptoword[i] == cryptoalphabet[j])
						{
							cryptoword[i] = cryptoalphabet[(j + key) % cryptoalphabet.size()];
							break;
						}
				std::cout << "Зашифрованное сообщение - " << cryptoword<<std::endl;
				break;
			}
			case 2:
			{
				for (int i = 0; i < cryptoword.size(); ++i)
					for (int j = 0; j < cryptoalphabet.size(); ++j)
						if (cryptoword[i] == cryptoalphabet[j])
						{
							if (j-key<0)
								correct=cryptoalphabet.size();
							cryptoword[i] = cryptoalphabet[(j - key+correct) % cryptoalphabet.size()];
							correct=0;
							break;
						}
				std::cout << "Дешифрованное сообщение - " << cryptoword<<std::endl;
				break;
			}
		}
	}
	void Crypto::MethodSlogan()
	{
		int select = 0;
		std::string key = "";
		bool flag = 0;
		int keysymb = 0;
		int wordsymb = 0;
		int correct=0;
		std::cout << "1. Шифрование" << std::endl;
		std::cout << "2. Дешифрование" << std::endl;
		std::cin >> select;
		while (select < 1 || select > 2)
		{
			std::cout << "Error: некорректное значение." << std::endl;
			std::cin >> select;
		}
		// Ввод ключа. Если введен не корректно, то завершаем программу.
		std::cout << "Введите ключ" << std::endl;
		std::cin >> key;
		std::cout << key.size() << std::endl;
		if (CorrectInputData(key, cryptoalphabet) == 1)
			std::cout << "Введенный ключ - " << key << std::endl;
		else
		{
			std::cout << "Error: некорректное значение. Ключ состоит из символов алфавита." << std::endl;
			exit(0);
		}
		if (key.size() > cryptoword.size())
		{
			std::cout << "Error: некорректное значение. Ключ не может быть длинее слова." << std::endl;
			exit(0);
		}
 
		while (key.size() != cryptoword.size())
		{
			for (int i = 0; i < cryptoalphabet.size(); ++i)
			{
				flag = 0;
				for (int j = 0; j < key.size(); ++j)
					if (key[j] == cryptoalphabet[i])
					{
						flag = 1;
						break;
					}
				if (flag != 1)
				{
					key = key + cryptoalphabet[i];
					break;
				}
			}
		}
		std::cout << "Ключ лозунга - " << key << std::endl;
 
		// Лозунговый шифр.
		switch (select)
		{
			case 1:
			{
				for (int i = 0; i < cryptoword.size(); ++i)
				{
					for (int j = 0; j < cryptoalphabet.size(); ++j)
					{
						if (cryptoword[i] == cryptoalphabet[j])
							wordsymb = j;
						if (key[i] == cryptoalphabet[j])
							keysymb = j;
					}
					cryptoword[i] = cryptoalphabet[(wordsymb + keysymb) % cryptoalphabet.size()];
					wordsymb = 0;
					keysymb = 0;
				}
		
				std::cout << "Зашифрованное сообщение - " << cryptoword<<std::endl;
				break;
			}
			case 2:
			{
				for (int i = 0; i < cryptoword.size(); ++i)
        		        {
                		        for (int j = 0; j < cryptoalphabet.size(); ++j)
                		        {
                		                if (cryptoword[i] == cryptoalphabet[j])
                		                        wordsymb = j;
                		                if (key[i] == cryptoalphabet[j])
                		                        keysymb = j;
                		        }
					if (wordsymb-keysymb<0)
                                        	correct=cryptoalphabet.size();
                                        cryptoword[i] = cryptoalphabet[(wordsymb - keysymb+correct) % cryptoalphabet.size()];
                		        wordsymb = 0;
                		        keysymb = 0;
					correct=0;
             			}

				std::cout << "Дешифрованное сообщение - " << cryptoword<<std::endl;
				break;
			}
		}
	}

	void Crypto::MethodVizhiner ()
	{
		int select = 0;
		std::string key = "";
		int k=0;
		int keysymb = 0;
		int wordsymb = 0;
		int correct=0;
		std::cout << "1. Шифрование" << std::endl;
		std::cout << "2. Дешифрование" << std::endl;
		std::cin >> select;
		while (select < 1 || select > 2)
		{
			std::cout << "Error: некорректное значение." << std::endl;
			std::cin >> select;
		}
 
		// Ввод ключа. Если введен не корректно, то завершаем программу.
		std::cout << "Введите ключ" << std::endl;
		std::cin >> key;
		std::cout << key.size() << std::endl;
		if (CorrectInputData(key, cryptoalphabet) == 1)
			std::cout << "Введенный ключ - " << key << std::endl;
		else
		{
			std::cout << "Error: некорректное значение. Ключ состоит из символов алфавита." << std::endl;
			exit(0);
		}
		if (key.size() > cryptoword.size())
		{
			std::cout << "Error: некорректное значение. Ключ не может быть длинее слова." << std::endl;	
			exit(0);
		}
		while (key.size() != cryptoword.size())
		{
			key=key+cryptoword[k%cryptoword.size()];
			k=k+1;
		}
		switch (select)
		{
			case 1:
			{
				for (int i = 0; i < cryptoword.size(); ++i)
				{
					for (int j = 0; j < cryptoalphabet.size(); ++j)
					{
						if (cryptoword[i] == cryptoalphabet[j])
							wordsymb = j;
						if (key[i] == cryptoalphabet[j])
							keysymb = j;
					}
					cryptoword[i] = cryptoalphabet[(wordsymb + keysymb) % cryptoalphabet.size()];
					wordsymb = 0;
					keysymb = 0;
				}	
				std::cout << "Зашифрованное сообщение - " << cryptoword<<std::endl;
				break;
			}
			case 2:
			{
				for (int i = 0; i < cryptoword.size(); ++i)
        	        	{
        	                	for (int j = 0; j < cryptoalphabet.size(); ++j)
        	                	{
        	                        	if (cryptoword[i] == cryptoalphabet[j])
        	                                	wordsymb = j;
        	                        	if (key[i] == cryptoalphabet[j])
        	                                	keysymb = j;
        	                	}
					if (wordsymb-keysymb<0)
						correct= cryptoalphabet.size();
        	                	cryptoword[i] = cryptoalphabet[(wordsymb - keysymb+correct) % cryptoalphabet.size()];
        	                	wordsymb = 0;
        	                	keysymb = 0;
					correct=0;
        	        	}
				std::cout << "Дешифрованное сообщение - " << cryptoword<<std::endl;
				break;
			}
		}
	}
	void Crypto::MethodGamma()
	{
		int select = 0;
		int key=0;
		int correct=0;
		std::vector<int> keyvector;
		std::cout << "1. Шифрование" << std::endl;
		std::cout << "2. Дешифрование" << std::endl;
		std::cin >> select;
		while (select < 1 || select > 2)
		{
			std::cout << "Error: некорректное значение." << std::endl;
			std::cin >> select;
		}
		std::cout << "Введите ключ" << std::endl;
		if (std::cin >> key)
			std::cout << "Ключ - "<<key<<std::endl;
		else
		{
			std::cout << "Error: некорректное значение. Ключ состоит из целых чисел."<<std::endl;
			exit(0);
		}
		//Генерация ключа
		keyvector.push_back(key);
		while (keyvector.size()!=cryptoword.size())
			keyvector.push_back((7*keyvector[keyvector.size()-1]+1)%30);
		switch (select)
		{
			case 1:
			{
				for (int i = 0; i < cryptoword.size(); ++i)
					for (int j = 0; j < cryptoalphabet.size(); ++j)
						if (cryptoword[i] == cryptoalphabet[j])
						{
							cryptoword[i] = cryptoalphabet[(j + keyvector[i]) % cryptoalphabet.size()];
							break;
						}
				std::cout << "Зашифрованное сообщение - " << cryptoword<<std::endl;
				break;	
			}
			case 2:
			{
				for (int i = 0; i < cryptoword.size(); ++i)
                                        for (int j = 0; j < cryptoalphabet.size(); ++j)
                                                if (cryptoword[i] == cryptoalphabet[j])
                                                {
							if (j-keyvector[i]<0)
								correct=cryptoalphabet.size();
                                                        cryptoword[i] = cryptoalphabet[(j - keyvector[i]+correct) % cryptoalphabet.size()];
                					correct=0; 
		                                       break;
                                                }
                                std::cout << "Дешифрованное сообщение - " << cryptoword<<std::endl;
                                break;
			}
		}
	}
	
	void Crypto::save()
	{
		std::cout<<"Введите путь к файлу"<<std::endl;
		std::string path;
		std::string answer;
		std::cin>>path;
		std::ofstream file;
		std::ifstream filecheck;
		filecheck.open(path);
;
		if(!filecheck)
		{
			file.open(path);	
			file<<cryptoword;
			file.close();
                        std::cout<<"Сообщение было успешно сохранено"<<std::endl;
		}	
		else
		{
			std::cout<<"Файл уже существует, перезаписать ? (yes/no)"<<std::endl;
			std::cin>>answer;
			if (answer=="yes")
			{
				file.open(path);
				file<<cryptoword;
				file.close();
				std::cout<<"Сообщение было успешно сохранено"<<std::endl;
			}
			filecheck.close();
		}	
	}
	void Crypto::load()
	{
		std::cout<<"Введите путь к файлу"<<std::endl;
                std::string path;
		std::cin>>path;
		std::ifstream file;
		file.open(path);
		if(!file)
			std::cout<<"Файл c заданным путем не существует"<<std::endl;
		else
		{
			cryptoword="";
			file>>cryptoword;
			std::cout<<"Файл успешно считан"<<std::endl;
		}
	}


	bool CorrectInputData(std::string word, std::string alphabet)
	{
		bool correct = 0;
		for (int i = 0; i < word.size(); ++i)
		{
			correct = 0;
			for (int j = 0; j < alphabet.size(); ++j)
			{
				if (alphabet[j] == word[i])
				{
					correct = 1;
					break;
				}
			}
			if (correct == 0)
			{
				return 0;
			}
		}
		return 1;
	}
 
	int Interface::ChosenFunction()
	{
		int chosenValue;
		std::cout << "Выберите одну из операций:" << std::endl;
		std::cout << "1. Шифр Цезаря" << std::endl;
		std::cout << "2. Лозунговый шифр" << std::endl;
		std::cout << "3. Шифр Виженера" << std::endl;
		std::cout << "4. Шифр модульного гаммирования" << std::endl;
		std::cout << "5. Сохранить данные в файл" << std::endl;
		std::cout << "6. Загрузить данные из файла" << std::endl;
		std::cout << "7. Завершить работу программы" << std::endl;
		std::cin >> chosenValue;
		return chosenValue;
	}
 
	void Interface::MakeDecision(int chosenValue, Crypto *crypto)
	{
		switch (chosenValue)
		{
			case 1:
			{
				crypto->MethodCaesar();
				int chosenValue =ChosenFunction();
				MakeDecision(chosenValue, crypto);
				break;
			}
			case 2:
			{
				crypto->MethodSlogan();
				int chosenValue =ChosenFunction();
               		        MakeDecision(chosenValue, crypto);
				break;
			}
			case 3:
			{
				crypto->MethodVizhiner();
				int chosenValue =ChosenFunction();
                	        MakeDecision(chosenValue, crypto);
                	        break;
			}
			case 4:
			{
				crypto->MethodGamma();
                                int chosenValue =ChosenFunction();
                                MakeDecision(chosenValue, crypto);
                                break;
			}
			case 5:
			{
				crypto->save();
                                int chosenValue =ChosenFunction();
                                MakeDecision(chosenValue, crypto);
                                break;
			}
			case 6:
                        {
                                crypto->load();
                                int chosenValue =ChosenFunction();
                                MakeDecision(chosenValue, crypto);
                                break;
                        }

			case 7:
			{
				std::cout<< "Вы уверены, что хотите выйти из программы? (yes/no)"<<std::endl;
				std::string answer;
				std::cin>>answer;
				if (answer=="yes")
					exit(0);
				else 
				{
					int chosenValue =ChosenFunction();
                                	MakeDecision(chosenValue, crypto);
				}
				break;
			}
		}
	}

}
