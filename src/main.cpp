#include <iostream>	// Ïîòîê ââîäà-âûâîäà 
#include <string> // Ñòðîêè (èç íèõ áóäåì ïàðñèòü)
#include <vector> // Âåêòîð (çàìåíà ìàññèâó, êóäà ìû ñëîæèì ñïàðñåííûå äàííûå)
#include <cmath> // Ìàò. ôóíêöèè

using namespace std;

const double PI = atan(1) * 4; // Îïðåäåëèì pi

bool check(string& expression, string& type) // Ïåðâîíà÷àëüíàÿ ïðîâåðêà 
{
	string iscircle = "circle"; // Ïðîâåðêà, ÷òî íàì äàí êðóã
	int i = 0;
	for (; i < (int)iscircle.size() && i < (int)expression.size(); i++) {
		if (tolower(expression[i]) != iscircle[i]) { // Ïðèâîäèì íàøè áóêâû ê ìàëåíüêèì, ÷òîáû ñðàâíèòü èõ
			return 0;
		}
	}
	type = iscircle;
	if (i != 6) return 0; // Ïðîâåðêà òèïà ôèãóðû

	int count = 0;
	while (((expression[i]) == '(' && !isdigit(expression[i])) && i < (int)expression.size()) { // Ïðîâåðÿåì êîëè÷åñòâî ñêîáîê
		count++;
		++i;
	}

	if ((expression[i - 1]) != '(' && expression[i - 1] != ' ') { // Êàêîé-òî ãîâíîêîä, áåç íåãî íå ðàáîòàåò
		return 0;
	}

	bool digit = 0;
	for (;expression[i] != ')' && i < (int)expression.size(); i++) { // Ïðîâåðÿåì öèôðû, çàïÿòûå, òî÷êè (ôóíêöèÿ ïàðñåðà íå âîçüìåò äàííûå ñ çàïÿòîé, íóæíû ñ òî÷êîé)
		if (!isdigit(expression[i]) && expression[i] != '.' && expression[i] != ',' && expression[i] != ' ') {
			return 0;
		}
		else {
			if (isdigit(expression[i])) {
				digit = 1;
			}
			if (expression[i] == ',') {
				digit = 0;
			}
		}
	}
	if (!digit) return 0;

	while ((expression[i] != ' ' || !isdigit(expression[i])) && i < (int)expression.size()) { // Ïðîâåðÿåì ñêîáêè, íî óæå çàêðûâàþùèåñÿ
		if ((expression[i]) != ')') {
			return 0;
		}
		count--;
		++i;
	}
	if (count) return 0; // Åñëè ñêîáîê íå õâàòàåò
	return 1;
}

bool parse(string& expression, vector<double>& nums, string& type) 
{
	string num; // Ñþäà çàêèäûâàåì ÷èñëî ñî ñòðîêè
	int count = 0;
	for (int i = 0; i < (int)expression.size(); i++) {
		if (isdigit(expression[i]) || expression[i] == '.') {
			num.push_back(expression[i]); // Ïî ñèìâîëó äîáàâëÿåì íàøå ÷èñëî äî çàïÿòîé
		}
		if (expression[i] == ',' || expression[i] == ')' || expression[i] == ' ') {
			if (num.size() > 0) {
				nums.push_back(stod(num));
				num.clear();
				count++;
			}
			else {
				if (i + 1 == (int)expression.size() || expression[i] == ' ') continue; // Ñìîòðèì ïðîáåëû èëè êîíåö
				return 0;
			}
		}
		if (count == 2 && expression[i] == ',') { // Ïðîâåðêà íà êîëè÷åñòâî ÷èñëå ïîñëå çàïÿòîé (ó êðóãà äîëæíî îñòàòüñÿ îäíî ÷èñëî ïîñëå ïîñëåäíåé çàïÿòîé, ó îñòàëüíûõ 2
			count = 0;
		}
	}
	if ((count != 0 && type != "circle") || (count != 1 && type == "circle")) { // Ïðîâåðêà êðóãà èëè äðóãîé ôèãóðû
		return 0;
	}

	return 1;
}

bool calculate(const string& expression, const vector<double>& nums, string& type) // Ïðîèçâîäèì ðàññ÷åòû
{
	if (type == "circle" && nums.size() == 3) { // Ïðîâåðÿåì êîëè÷åñòâî äàííûõ è òèï, äàëüøå ðàññ÷åòû
		system("cls");
		cout << expression << endl;
		cout << "perimeter = " << 2 * PI * nums[2] << endl;
		cout << "area = " << PI * pow(nums[2], 2) << endl;
	}
	return 1;
}

int main()
{
	string expression; // Íàøå èñõîäíîå âûðàæåíèå
	getline(cin, expression);  // Âââîä âûðàæåíèÿ
	vector<double> v; // Ñþäà ïàðñÿòñÿ íàøè äàííûå
	string type; // Òèï ôèãóðû
	if (!(check(expression, type) && parse(expression, v, type) && calculate(expression, v, type))) { // Åñëè òðè ôóíêöèè âîçâðàùàþò 1, òî çàâåðøàåì ïðîãðàììó, èíà÷å èäåì â öèêë
		do {
			cout << "ERROR!" << endl;
			getline(cin, expression);
		} while (!(check(expression, type) && parse(expression, v, type) && calculate(expression, v, type))); // Ââîäèì âûðàæåíèå çàíîâî, ïîêà íå äîáüåìñÿ íóæíîãî ðåçóëüòàòà
	}

	return 0;
}