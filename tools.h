using namespace std;


class ReadData
{
/*
* Objeto que manipula un archivo de
* texto, lo abre, y le cada 
* línea
*/
protected:
	string file_name;
	ifstream text_file;
public:
	ReadData(string name) : file_name(name) {
		cout << "Opening file: " << file_name << endl;
		text_file.open(file_name);
		cout << "Done!" << endl;
	} ;

	// Regresa una lína del'
	// archivo de texto
	string readLine(){
		string line;

		if (text_file.is_open()){
			getline(text_file, line);

			return line;
		}

		return "";
	}

	bool closeFile(){
		text_file.close();
	}
};

class Table
{

	typedef struct _cell
	{
		char symbol;
		int skip;
	} struct_table;

protected:
	struct_table* table;
	string pattern;
	int len;

public:
	// El constructo crea una instancia
	// de la tabla de saltos
	Table(string pattrn) : pattern(pattrn) {
		len = pattern.length();
	
		table = new struct_table[len-1];

		Table::preprocess();
	};
	
	int getValue (char symbol){
		for (int i = len - 2; i >= 0 ; --i){
			if (symbol == table[i].symbol)
				return table[i].skip;
		}

		return len;
	}

private:
	// llena la tabla de saltos
	void preprocess (){
		for (int i = 0; i < len - 1; ++i) {
			table[i].symbol = pattern[i];
			table[i].skip = len - 1 - i;
		}
	}
};