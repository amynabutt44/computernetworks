#include <iostream>
#include <string>
#include <vector>
# include <algorithm>
using namespace std;
bool binarychecker(string input)
{
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] != '0' && input[i] != '1')
        {
            return false;
        }
    }
    return true;

}
// task 1
bool oneBiterrorUisngParityBit(string input, int choice)
{
    cout << "                                          one bit parity dedection                     ";
    cout << endl;
    int count = 0;
    if (choice == 1)
    {
        cout << "                             even parity                    ";
        cout << endl;
        for (int i = 0; i < input.size() - 1; i++)
        {
            if (input[i] == '1')
            {
                count++;
            }

        }
        if (count % 2 == 0 && input[input.size() - 1] == '0')
        {
            return true;
        }
        else if (count % 2 != 0 && input[input.size() - 1] == '1')
        {
            return true;
        }
        else return false;


    }
    else if(choice ==2)
    {
        cout << "                                       odd parity                                    ";
        cout << endl;
        for (int i = 0; i < input.size() - 1; i++)
        {
            if (input[i] == '1')
            {
                count++;
            }

        }
        if (count % 2 == 0 && input[input.size() - 1] == '1')
        {
            return true;
        }
        else if (count % 2 != 0 && input[input.size() - 1] == '0')
        {
            return true;
        }
        else return false;

    }
}







// task 2 
 int calculatingParity(string input)
{
    int count = 0;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '1')
        {
            count++;
        }


    }
    return count % 2 == 0 ? 0 : 1;
}


void parityAdding(vector<string>& matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        int paritybit = calculatingParity(matrix[i]);
        matrix[i] += to_string(paritybit);
    }
    string columnParity;
    for (int j = 0; j < matrix[0].size(); j++)
    {
        string columnsvalue;
        for (int i = 0; i < matrix.size(); i++)
        {
            columnsvalue += matrix[i][j];
        }
        int parityBit = calculatingParity(columnsvalue);
        columnParity += to_string(parityBit);
    }
    matrix.push_back(columnParity);
}
void printMatrix(vector<string>& matrix)
{
    cout << " ------------------------------------------------2d even parity bit ";
    cout << endl;
    cout << "--------------------------------------------" << endl;
    for (int i = 0; i < matrix.size(); i++)
    {

            for (int j = 0; j < matrix[i].size(); j++)
            {
                cout << matrix[i][j] << "  ";
            }
            cout << endl;
        
    }
    cout << "--------------------------------------------" << endl;
}

void evenParityBit2DMatrix() {
    vector<string> matrix;
    int rows;
    int cols;
    cout << " enter the number of rows";
    cin >> rows;
    cout << "enter the number of columns";
    cin >> cols;

    for (int i = 0; i < rows; i++)
    {
        cout << " enter the row " << i << endl;
        string row;
        cin >> row;
        if (!(binarychecker(row)))
        {
            return;
        }
        if (row.size() != cols)
        {
            cout << " kindly error correct amount of entries in col  " << endl;
            return;
        }
        matrix.push_back(row);
    }

    parityAdding(matrix);

    cout << "Bits to be transmitted (with even parity bits):" << endl;
    printMatrix(matrix);
}









//task2 b part 
void twoDErrordedection()
{
    cout << endl;
    cout << " -------------------------------------------error decdection using 2 d ---------------------------";
    cout << endl;
    int r;
    int c;
    cout << " enter  number of rows";
    cin >> r;
    cout << " enter number of cols";
    cin >> c;
    vector<string> matrix;
    for (int i = 0; i < r; i++)
    {
        cout << " enter the row " << i << endl;
        string row;
        cin >> row;
        if (!(binarychecker(row)))
        {
            return;
        }
        if (row.size() != c)
        {
            cout << " kindly error correct amount of entries in col  " << endl;
            return;
        }
        matrix.push_back(row);
    }
    vector<int> rows;
    vector<int> cols;
    for (int i = 0; i < matrix.size()-1; i++)
    {
        int count = 0;
        for (int j = 0; j < matrix[i].size()-1; j++)
        {
            if (matrix[i][j] == '1')
            {
                count++;
            }
        }
        if (count % 2 == 0 && matrix[i][matrix[i].size()-1] == '0')
        {

        }
        else if (count % 2 != 0 && matrix[i][matrix[i].size() - 1] == '1')
        {

        }
        else
        {
            rows.push_back(i);
        }
    }


    vector<string> colMAtrix;
    string columnParity;
    for (int j = 0; j < matrix[0].size() - 1; j++)
    {
        string columnsvalue;
        for (int i = 0; i < matrix.size(); i++)
        {
            columnsvalue += matrix[i][j];
        }

        colMAtrix.push_back(columnsvalue);
    }

    for (int i = 0; i < colMAtrix.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < colMAtrix[i].size() - 1; j++)
        {
            if (colMAtrix[i][j] == '1')
            {
                count++;
            }
        }
        if (count % 2 == 0 && colMAtrix[i][colMAtrix[i].size() - 1] == '0')
        {

        }
        else if (count % 2 != 0 && colMAtrix[i][colMAtrix[i].size() - 1] == '1')
        {

        }
        else
        {
            cols.push_back(i);
        }
    }


    cout << "--------------------------------------------" << endl;

    for (int i = 0; i < rows.size(); i++)
    {
        for (int j = 0; j < cols.size(); j++)
        {
            cout << " bit position which contains errors are  : " << rows[i] << cols[j];
            cout << endl;
        }

    }
    cout << "--------------------------------------------" << endl;

}
// task 3 


string hammingencoding(string input)
{
    cout << endl;
    cout << " --------------------hamming encoding ---------------------------------";
    cout << endl;
    int r = 1;
    while (pow(2, r) < input.size() + r + 1)
    {
        r++;
    }

    string ans(input.size() + r, ' ');

    int j = 0;
    for (int i = 0; i < input.size() + r; i++)
    {
        if ((i + 1) & ((i + 1) - 1))
        {
            ans[i] = input[j];
            j++;
        }
    }


    cout << " the value of rundant bits are " << r << endl;


    for (int i = 0; i < r; i++)
    {
        int p = 0;
        int index = pow(2, i) - 1;
        cout << " redundant bits are at position " << index +1<< endl;
        for (int j = index; j < input.size() + r; j += pow(2, i + 1))
        {
        
            for (int k = j;k< min(j + static_cast<int> (pow(2, i)), static_cast<int>(input.size() + r)); k++)
            {
                if (ans[k] == '1')
                {
                    p++;
                }
            }
        }
        if (p % 2 == 0)
        {
            ans[index] = '0';
        }
        else
        {
            ans[index] = '1';
        }

    }
    return ans;
}

  
void hammingErRORDedection(string input)
{
    string ans = input;
    cout << endl << "---------------------------------hamming error finding -----------------------" << endl;
    int r = 1;
    while (pow(2, r) < input.size() + r + 1)
    {
        r++;
    }
    int error = 0;
    for (int i = 0; i < r; i++)
    {
        int index = pow(2, i) - 1;
        int p = 0;
        for (int j = index; j < input.length(); j += pow(2, i + 1))
        {
            for (int k = j; k < min(j + static_cast<int> (pow(2, i)), static_cast<int>(input.size())); k++)
            {
                if (input[k] == '1')
                {
                    p++;
                }
            }
        }


        if (p % 2 != 0)
        {
            error += index + 1;
        }
    }

    if (error == 0)
    {
        cout << "--------------------------------------------" << endl;
        cout << " no error dedected"<< endl;
        cout << "--------------------------------------------" << endl;

    }
    else
    {
        if (ans[error] == '1')
        {
            ans[error] = '0';
        }
        else
        {
            ans[error] = '1';
        }
        cout << "--------------------------------------------" << endl;
        cout << " error dedected at bit " << error << endl;
        cout << " the corrext msg is " << ans << endl;
        cout << "--------------------------------------------" << endl;
    }

}



//task 4
void crc(string input, string divior) 
{
    cout << endl << " -----------------------------CRC --------------------------" << endl;
    string crc = "";
    string msg = input;
    msg.append(divior.length() - 1, '0');
    for (int i = 0; i <= msg.size() - divior.size(); i++)
    {
        if (msg[i] == '1')
        {
            for (int j = 0; j < divior.length(); j++)
            {
                if (msg[i + j] == divior[j])
                {
                    msg[i + j] = '0';
                }
                else
                {
                    msg[i + j] = '1';
                }
            }
        }
    }
    cout <<endl << " --------------------------------------------------------------------------" << endl;

    crc = msg.substr(msg.length() - (divior.length() - 1));
    
    cout << " crc is : "<<crc;
    cout << " msg after adding crc is " << input + crc;
    cout << endl << " --------------------------------------------------------------------------" << endl;

}

void crcErrorDedection(string input, string divisor)
{
    cout << endl << " -----------------------------CRC error dedection--------------------------" << endl;
    string remainder = input;
    for (int i = 0; i < input.size() - (divisor.size() - 1); i++)
    {
        if (remainder[i] == '1')
        {
            for (int j = 0; j < divisor.size(); j++)
            {
                if ((remainder[i + j] == divisor[j]))
                {
                    remainder[i + j] = '0';
                }
                else
                {
                    remainder[i + j] = '1';
                }
            }
        }
    }
    int flag = 0;
    for (int i = 0; i < remainder.size(); i++)
    {
        if (remainder[i] != '0')
        {
            flag = 1;
        }
    }
    if (flag == 0)
    {
        cout << "--------------------------------------------" << endl;
        cout << " no error dedected" << endl;
        cout << "--------------------------------------------" << endl;


    }
    else
    {
        cout << "--------------------------------------------" << endl;
        cout << "  error detedectd"<<endl;
        cout << "--------------------------------------------" << endl;
    }
}
























// task 5 
string binaryAdd(string a, string b)
{
    string ans;
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;
    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;
        if (i >= 0)
        {
            sum += a[i] - '0';
            i--;

        }
        if (j >= 0)
        {
            sum += b[j] - '0';
            j--;
        }
        carry = sum / 2;
        ans += (sum % 2) + '0';

    }
    reverse(ans.begin(), ans.end());
    return ans;
}
void CHecksumError(string input)
{
    cout << endl << " ----------------------------CHECK SUM error dedection-------------------------" << endl;
    vector<string> chunk;
    for (int i = 0; i < input.size(); i += 8)
    {
        chunk.push_back(input.substr(i, 8));
    }
    string ans = "00000000";
    for (int i = 0; i < chunk.size(); i++)
    {
        ans = binaryAdd(ans, chunk[i]);
    }

    while (ans.size() > 8)
    {
        string leftBits = ans.substr(ans.size() - 8, 8);
        string rightBits = ans.substr(0, ans.size() - 8);
        ans = binaryAdd(leftBits, rightBits);

    }

    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] == '0')
        {
            ans[i] = '1';
        }
        else
        {
            ans[i] = '0';
        }
    }
    int falg = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] != '0')
        {
            falg = 1;
            break;
        }
    }
    if (falg == 1)
    {
        cout << endl;
        cout << "--------------------------------------------" << endl;
        cout << " error  detected ";
        cout << endl<<"--------------------------------------------" << endl;
    }
    else
    {
        cout << endl;
        cout << "--------------------------------------------" << endl;
        cout << " no error detected  ";
        cout << endl<<"--------------------------------------------" << endl;
    }
}

void checksum(string input)
{
    cout << endl << " ----------------------------CHECK SUM error encoding-------------------------" << endl;
    int remainder = 0;
    int zero;
    if (input.size() % 8 != 0)
    {
        remainder = input.size() % 8;
        zero = 8 - remainder;
        string zeros;
        for (int i = 0; i < zero; i++)
        {
            zeros += '0';
        }
        string newinput = zeros + input;
        input = newinput;
















    }


    vector<string> chunk;
    for (int i = 0; i < input.size(); i += 8)
    {
        chunk.push_back(input.substr(i, 8));
    }
    string ans = "00000000";
    for (int i = 0; i < chunk.size(); i++)
    {
        ans = binaryAdd(ans, chunk[i]);
    }

    while (ans.size() > 8)
    {
        string leftBits = ans.substr(ans.size() - 8, 8);
        string rightBits = ans.substr(0, ans.size() - 8);
        ans = binaryAdd(leftBits, rightBits);

    }

    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] == '0')
        {
            ans[i] = '1';
        }
        else
        {
            ans[i] = '0';
        }
    }
    cout << endl;
    cout << "--------------------------------------------" << endl;
    cout << "check sum is : " << ans;
    cout << endl;
    cout << " the msg after adding checksum is " << input + ans;
    cout << endl<<"--------------------------------------------" << endl;
    cout << endl;

    
}


int main()
{
	int choice;
	do {
        cout << endl;
		cout << " enter your choice ";
		cout << endl;
		cout << " enter 0 to   exit ";
		cout << endl;
		cout << " enter 1 for  task1 parity bit ";
		cout << endl;
		cout << " enter 2 for  task2 2d parity bit ";
		cout << endl;
		cout << " enter 3 for  task3 hamming error detection  ";
		cout << endl;
		cout << " enter 4 for  task4 CRC  ";
		cout << endl;
		cout << " enter 5 for  task5 checkSum ";
		cout << endl;
		cin >> choice;
		if (choice == 1)
		{
            string input;
            cout << " enter input in binary : ";
            cin >> input;
            if (!(binarychecker(input)))
            {
                cout << "  only binary numbers are executed ";
                cout << endl;

            }
            else
            {
                cout << " press 1 if u wanna  use even bit parity  and 2 for odd parity " << endl;
                int parity;
                cin >> parity;
                if (oneBiterrorUisngParityBit(input, parity))
                {
                    cout << "--------------------------------------------" << endl;
                    cout << " no error " << endl;
                    cout << "--------------------------------------------" << endl;
                }
                else
                {
                    cout << "--------------------------------------------" << endl;
                    cout << " error detected" << endl;
                    cout << "--------------------------------------------" << endl;
                }
            }
           

		}
		else if (choice == 2)
		{
            int choiceuser;
            cout << " enter your choice press 1 for  part  2d bit encoding and 2 for  error dededction";
            cin >> choiceuser;
            if (choiceuser == 1)
            {
                cout << endl;
                evenParityBit2DMatrix();
                cout << endl;
            }
            else if ( choiceuser==2)
            {
                cout << endl;
              
                twoDErrordedection();
       
               
            }
            else
            {

                cout << endl;
              
                cout << " no such a choice exsist";
               
                cout << endl;
            }
        
         
		}
		else if (choice == 3)
		{
            cout << endl;
            cout << " which part u wanna execute  press 1 for  hamming ecnoding  nd 2 for  hamming error dedection ";
            cout << endl;
            int c = 0;
            cin >> c;
            
            string input;

            cout<<" enter input ";
            cin >> input;
            string ans;
            if (binarychecker(input))
            {

                if (c == 1)
                {
                    cout << endl;
                    cout << "--------------------------------------------" << endl;
                     ans=hammingencoding(input);
                     cout <<"  bits to be transmitted after adding  rundant bits " << ans;
                     cout << endl;
                     cout << "--------------------------------------------" << endl;
                  
                    
                }
                else if (c == 2)
                {
                    cout << endl;
                    cout << endl;
                    cout << "--------------------------------------------" << endl;
                    hammingErRORDedection(input);
                    cout << endl;
                    cout << "--------------------------------------------" << endl;
                    cout << endl;
                }
                else
                {
                    cout << " no such chooise exsits";
                }

            }
            else
            {
                cout << " only binary values are exxecuted";
            }

           
		}
		else if (choice == 4)
		{
            string input;
            cout << " enter message ";
            cin >> input;
            cout << " enter divisor";
            string div;
            cin >> div;


            int userchoice;
            cout << " press 1 for crcc encoding  and 2 for error dedection";
            cin >> userchoice;

            if (binarychecker(input))
            {

                if (userchoice == 1)
                {
                    crc(input, div);
                }
                else if (userchoice == 2)
                {
                    cout << endl;
                    cout << "--------------------------------------------" << endl;
                    crcErrorDedection(input, div);
                    cout << endl;
                    cout << "--------------------------------------------" << endl;
                    
                }
                else
                {
                    cout << " no such a choice exsists";
                }

            }
            else
            {
                cout << " only binary values are executed";
            }

		}
		else if (choice == 5)
		{
            cout << " which part u wanna execute  press 1 for  check sum calculation  nd 2 for  check sum error dedection ";
            int c = 0;
            cin >> c;
            string input;
            cout << " enter input in binary : ";
            cin >> input;
            if (!(binarychecker(input)))
            {

                cout << "  only binary numbers are executed ";
                cout << endl;

            }
            else
            {
                if(c==1)
                checksum(input);
                else if (c==2)
                {
                    CHecksumError(input);
                }
                else
                {
                    cout << " no such a chooice exsist";
                }
            }
		}
		else
		{
			cout << " kindly enter   valid choice";
		}
	} while (choice != 0);
}