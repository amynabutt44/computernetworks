#include<iostream>
#include <vector>
using namespace std;
void NRZ(string binaryData)
{
    cout << " -------------------------------------------------------------";
    cout << endl;
    cout << " binary data is " << endl;
    for (int i = 0; i < binaryData.length(); i++)
    {
        cout << " " << binaryData[i] << " ";

    }
    cout << endl;
    string upperLine = "|";
    cout << "|";
    string signallLine;
    for (int i = 0; i < binaryData.length(); i++) {
        if (binaryData[i] == '1')
        {
            signallLine += "___";
        }
        else if (binaryData[i] == '0')
        {
            signallLine += "   ";
        }
    }


    for (int i = 0; i < signallLine.length(); i++)
    {
        if (signallLine[i] == '_' && signallLine[i + 1] == ' ')
        {
            upperLine += "|";
        }
        else if (signallLine[i] == ' ' && signallLine[i + 1] == '_')
        {
            upperLine += "|";
        }
        else
        {
            upperLine += "_";
        }

    }
    cout << signallLine << endl;
    cout << upperLine + "----->time axis" << "\n|\n|\n";
    cout << endl;
    cout << " -------------------------------------------------------------";
}
void NRZ_L(string binaryData)
{
    cout << " -------------------------------------------------------------";
    cout << endl;
    for (int i = 0; i < binaryData.length(); i++)
    {
        cout << " " << binaryData[i] << " ";
    }
    cout << endl;
    string s;
    cout << "|";
    for (int i = 0; i < binaryData.length(); i++)
    {
        if (binaryData[i] == '0')
        {
            s += "___";

        }
        else if (binaryData[i] == '1')
        {
            s += "   ";
        }
    }
    cout << s;
    cout << endl;
    string downString;
    string upString = "|";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '_' && s[i + 1] == ' ')
        {
            upString += "|";
        }
        else if (s[i] == ' ' && s[i + 1] == '_')
        {
            upString += "|";
        }
        else {
            upString += "_";
        }
    }

    cout << upString + "------> time axis" << endl;
    for (int i = 0; i < binaryData.length(); i++)
    {
        if (binaryData[i] == '1')
        {
            downString += "___";

        }
        else if (binaryData[i] == '0')
        {
            downString += "   ";

        }
    }
    for (int i = 0; i < downString.length(); i++)
    {
        if (downString[i] == ' ' && downString[i + 1] == '_')
        {
            downString[i + 1] = '|';
        }
        else if (downString[i] == '_' && downString[i + 1] == ' ')
        {
            downString[i + 1] = '|';
        }
    }
    cout << downString;
    cout << endl;
    cout << endl;
    cout << " -------------------------------------------------------------";
}
void Manchester(string binaryData)
{

    cout << " -------------------------------------------------------------";
    cout << endl;
    for (int i = 0; i < binaryData.length(); i++)
    {
        cout << "  " << binaryData[i] << "  ";
    }
    cout << endl;
    string upSignal, downSignal;
    //cout<<"|";
    for (int i = 0; i < binaryData.length(); i++)
    {
        if (binaryData[i] == '0')
        {
            upSignal += "__   ";
            downSignal += "  |__";
        }
        else {
            upSignal += "   __";
            downSignal += "__|  ";

        }
    }

    string l = "_________________________________________________---->timeaxis";
    for (int i = 0; i < upSignal.length(); i++)
    {
        if (upSignal[i] == '_' && upSignal[i + 1] == ' ')
        {
            l[i + 1] = '|';
        }
        else if (upSignal[i] == ' ' && upSignal[i + 1] == '_')
        {
            l[i] = '|';
        }

    }
    for (int i = 0; i < downSignal.length(); i++)
    {
        if (downSignal[i] == '_' && downSignal[i + 1] == ' ')
        {
            downSignal[i] = '|';
        }
        else if (downSignal[i] == ' ' && downSignal[i + 1] == '_')
        {
            downSignal[i + 1] = '|';
        }
    }
    cout << upSignal << endl;
    cout << l << endl;
    cout << downSignal;
    cout << endl;
    cout << endl;
    cout << " -------------------------------------------------------------";
}
void DifferentialManchester(string b)
{
    cout << " -------------------------------------------------------------";
    cout << endl;
    for (int i = 0; i < b.length(); i++)
    {
        cout << "  " << b[i] << "  ";
    }
    cout << endl;
    bool flag = true;
    string up, down, l = "_____________________________________________________________";
    for (int i = 0; i < b.length(); i++)
    {
        if (i == 0 && b[i] == '0')
        {
            up += "   __";
            down += "__|  ";

        }
        if (b[i] == '0' && i != 0)
        {
            if (flag == false)
            {
                up += "   __";
                down += "__|  ";
            }
            if (flag == true)
            {
                up += "__   ";
                down += "  |__";
            }

        }
        else if (b[i] == '1')
        {
            if (flag == true)
            {
                if (i == 1)
                {
                    up += "__   ";
                    down += "  |__";

                }
                else {
                    up += "   __";
                    down += "__|  ";
                    flag = false;
                }

            }
            else {
                up += "__   ";
                down += "  |__";
                flag = true;
            }
        }
    }
    for (int i = 0; i < up.length(); i++)
    {
        if (up[i] == '_' && up[i + 1] == ' ')
        {
            l[i + 1] = '|';
        }
        else if (up[i] == ' ' && up[i + 1] == '_')
        {
            l[i] = '|';
        }
    }
    int dl = down.length();
    for (int i = 0; i < dl; i++)
    {
        if (down[i] == '_' && down[i + 1] == ' ')
        {
            down[i] = '|';
        }
        else if (down[i] == ' ' && down[i + 1] == '_')
        {
            down[i + 1] = '|';

        }
    }

    cout << up << endl;
    cout << l << "---->time axis" << endl;
    cout << down;
}
void AMI(string binaryData)
{
    cout << " -------------------------------------------------------------";
    cout << endl;
    for (int i = 0; i < binaryData.length(); i++)
    {
        cout << " " << binaryData[i] << " ";
    }
    cout << endl;
    string upSignal, downSignal;

    bool flag = true;
    for (int i = 0; i < binaryData.length(); i++)
    {
        if (binaryData[i] == '1')
        {
            if (flag == true)
            {
                upSignal += "___";
                flag = false;
                downSignal += "   ";
            }
            else {
                downSignal += "|__|";
                upSignal += "   ";
                flag = true;
            }

        }
        else if (binaryData[i] == '0') {
            upSignal += "   ";
            downSignal += "   ";
        }

    }
    string midZone = "________________________________---->time axis";
    for (int i = 0; i < upSignal.length(); i++)
    {
        if (upSignal[i] == '_' && upSignal[i + 1] == ' ')
        {
            midZone[i] = '|';
        }

        else if (upSignal[i] == ' ' && upSignal[i + 1] == '_')
        {
            midZone[i] = '|';
        }
    }
    cout << upSignal << endl;
    cout << midZone << endl;
    cout << downSignal;
    cout << endl;
    cout << endl;
    cout << " -------------------------------------------------------------";

}
void  Pseudoternary(string binaryData)
{
    cout << " -------------------------------------------------------------";
    cout << endl;
    for (int i = 0; i < binaryData.length(); i++)
    {
        cout << " " << binaryData[i] << " ";
    }
    cout << endl;
    string upSignal, downSignal;

    bool flag = true;
    for (int i = 0; i < binaryData.length(); i++)
    {
        if (binaryData[i] == '0')
        {
            if (flag == true)
            {
                upSignal += "___";
                flag = false;
                downSignal += "   ";
            }
            else {
                downSignal += "|_|";
                upSignal += "   ";
                flag = true;
            }

        }
        else if (binaryData[i] == '1') {
            upSignal += "   ";
            downSignal += "   ";
        }

    }
    string midZone = "________________________________--->time axis";
    for (int i = 0; i < upSignal.length(); i++)
    {
        if (upSignal[i] == '_' && upSignal[i + 1] == ' ')
        {
            midZone[i] = '|';
        }

        else if (upSignal[i] == ' ' && upSignal[i + 1] == '_')
        {
            midZone[i] = '|';
        }
    }

    cout << upSignal << endl;
    cout << midZone << endl;
    cout << downSignal;
    cout << endl;
    cout << endl;
    cout << " -------------------------------------------------------------";
}
void TwoBOneQ_Encoding(string binary)
{

    cout << " -------------------------------------------------------------";
    cout << endl;
    if (binary.length() % 2 != 0)
        binary += "0";
    int len = binary.length();
    int rows = 7, cols = 10 + 3 * len;
    vector<vector<char>> graph(rows, vector<char>(cols, ' '));

    graph[0][0] = '^';
    int j = 4;

    for (int i = 0; i < len; i++)
    {
        graph[0][j] = binary[i];
        graph[0][++j] = binary[++i];
        j = j + 3;
    }


    graph[4][0] = graph[1][0] = graph[2][0] = graph[3][0] = graph[5][0] = graph[6][0] =
        graph[4][2] = graph[1][2] = graph[2][2] = graph[3][2] = graph[5][2] = graph[6][2] = '|';


    for (int j = 3; j < cols; j++)
        graph[3][j] = '_';

    j = 3;
    int previousRow, currentRow;
    for (int i = 0; i < len; i += 2)
    {
        if (binary[i] == '0' && binary[i + 1] == '0')
            currentRow = 5;
        else if (binary[i] == '0' && binary[i + 1] == '1')
            currentRow = 4;
        else if (binary[i] == '1' && binary[i + 1] == '1')
            currentRow = 2;
        else
            currentRow = 1;

        if (i > 1)
        {

            if (binary[i - 2] != binary[i] || binary[i - 1] != binary[i + 1])
            {
                if (currentRow > previousRow)
                {
                    for (int k = currentRow; k > previousRow; k--)
                        graph[k][j] = '|';
                }
                else
                    for (int k = previousRow; k > currentRow; k--)
                        graph[k][j] = '|';
            }
            j++;
        }

        graph[currentRow][j++] = graph[currentRow][j++] = graph[currentRow][j++] = '_';
        previousRow = currentRow;
    }

    j = j + 3;
    graph[1][j] = graph[2][j] = graph[4][j] = graph[5][j] = '_';
    j++;
    graph[1][j] = graph[2][j] = graph[4][j] = graph[5][j] = '_';
    j++;
    graph[1][j] = graph[2][j] = graph[4][j] = graph[5][j] = '_';
    j++;
    graph[1][j] = graph[2][j] = graph[4][j] = graph[5][j] = '_';
    j += 2;
    graph[1][j] = '+'; graph[2][j] = '+'; graph[4][j] = '-'; graph[5][j] = '-';
    j++;
    graph[1][j] = '3'; graph[2][j] = '1';  graph[4][j] = '1'; graph[5][j] = '3';
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << graph[i][j];
        cout << endl;
    }

    cout << "\n  ---->Time\n\n";
    cout << endl;
    cout << endl;
    cout << " -------------------------------------------------------------";
}
bool bin(string binary, int k) {
    int c = 0;
    for (int i = 0; i < k; i++) {
        if (binary[i] == '0') {
            c++;
        }
    }
    return c == 0;
}
void RZ(string b)
{
    cout << " -------------------------------------------------------------";
    cout << endl;
    int l = b.length();
    for (int i = 0; i < l; i++) {
        if (i == 0)
        {
            cout << " " << b[i] << "      ";
        }
        else
        {
            cout << b[i] << "      ";
        }

    }
    cout << endl;

    string s;
    cout << "|";

    for (int i = 0; i < l; i++) {
        if (b[i] == '0') {
            s += "       ";
        }
        else if (b[i] == '1') {
            s += "___    ";
        }
    }

    cout << s << endl;

    string down = "|";
    string up = "|";
    int sl = s.length();
    for (int i = 0; i < sl; i++) {
        if (s[i] == '_' && s[i + 1] == ' ') {
            up += '|';
        }
        else if (s[i] == ' ' && s[i + 1] == '_') {
            up += '|';
        }
        else {
            up += '_';
        }

        if (i == sl - 1) {
            up += "_____________";
        }
    }

    cout << up << endl;

    for (int i = 0; i < l; i++) {
        if (b[i] == '0') {
            if (i == 0 || bin(b, i)) {
                down += "___|   ";
            }
            else {
                if (b[i - 1] == '0')
                {
                    down += "|___   ";
                }
                else if (b[i - 1] == '1' && b[i - 2] == '1')
                {
                    down += " |___   ";
                }
                else
                {
                    down += "|___   ";
                }

            }
        }
        else if (b[i] == '1') {
            down += "      ";
        }
    }
    int dl = down.length();
    for (int i = 0; i < dl; i++) {
        if (down[i] == ' ' && down[i + 1] == '_') {
            down[i] = '|';
        }
        else if (down[i] == '_' && down[i + 1] == ' ') {
            down[i + 1] = '|';
        }
    }

    down += "\n|";
    cout << down << endl;
    cout << endl;
    cout << endl;
    cout << " -------------------------------------------------------------";
}
void NRZ_I(string b)
{
    cout << " -------------------------------------------------------------";
    cout << endl;

    string l = "|_";
    string up;
    string down = "|";
    int lb = b.length();
    for (int i = 0; i < lb; i++)
    {
        cout << " " << b[i] << " ";
    }
    cout << endl;
    cout << "|";
    bool flag = false;
    int i;


    if (b[0] == '0')
    {
        flag = false;
    }
    else
    {
        flag = true;
    }
    for (i = 0; i < lb; i)
    {
        if (flag == false)
        {
            up += "___";
            down += "   ";
            while (b[i] == '1')
            {
                if (b[i + 1] == '1')
                {
                    break;
                }
                down += "   ";
                up += "___";
                i++;

            }
            while (b[i] == '0')
            {
                if (b[i + 1] == '1')
                {
                    break;
                }
                down += "   ";
                up += "___";
                i++;
            }
            i++;
            if (flag == true)
            {
                flag = false;
            }
            else
            {
                flag = true;
            }
        }
        else {
            up += "   ";
            down += "___";
            if (flag == true)
            {
                flag = false;
            }
            else
            {
                flag = true;
            }
            i++;
            while (b[i] == '0')
            {
                down += "___";
                up += "   ";
                i++;
            }
        }
    }

    for (int i = 0; i < up.length(); i++)
    {
        if (up[i] == '_' && up[i + 1] == ' ')
        {
            l += "|";
        }
        else if (up[i] == ' ' && up[i + 1] == '_')
        {
            l += "|";
        }
        else {
            l += "_";
        }
    }
    for (int i = 0; i < down.length(); i++)
    {
        if (down[i] == ' ' && down[i + 1] == '_')
        {
            down[i + 1] = '|';
        }
        else if (down[i] == '_' && down[i + 1] == ' ')
        {
            down[i + 1] = '|';
        }
    }
    cout << up << endl;
    cout << l << "----->time axis" << endl;
    cout << down;
    cout << endl;
    cout << endl;
    cout << " -------------------------------------------------------------";
}
int main()
{
    int userchoice;
    string binary;

    do {
        do {

            cout << " enter binary  :";
            cin >> binary;
            bool validbinary = true;

            for (int i = 0; i < binary.length(); i++)
            {
                if (binary[i] != '0' && binary[i] != '1')
                {
                    validbinary = false;
                    break;
                }

            }
            if (validbinary)
            {
                break;
            }


        } while (true);
        do {

            cout << " enter your choice ";
            cout << endl;
            cout << " 0 for exit";
            cout << endl;
            cout << " 1 NRZ";
            cout << endl;
            cout << " 2 NRZ-L";
            cout << endl;
            cout << " 3 NRZ-I";
            cout << endl;
            cout << " 4 RZ";
            cout << endl;
            cout << " 5 MANCHESTAR";
            cout << endl;
            cout << " 6  Differential Manchester";
            cout << endl;
            cout << " 7 AMI";
            cout << endl;
            cout << " 8  Pseudoternary";
            cout << endl;
            cout << " 9 2B1Q";
            cout << endl;

            cin >> userchoice;

        } while (userchoice < 0 && userchoice >9);

        if (userchoice == 1)
        {
            NRZ(binary);
        }
        else if (userchoice == 2)
        {
            NRZ_L(binary);
        }
        else if (userchoice == 3)
        {
            NRZ_I(binary);

        }
        else if (userchoice == 4)
        {

            RZ(binary);

        }
        else if (userchoice == 5)
        {
            Manchester(binary);
        }
        else if (userchoice == 6)
        {
            DifferentialManchester(binary);
        }
        else if (userchoice == 7)
        {
            AMI(binary);

        }
        else if (userchoice == 8)
        {
            Pseudoternary(binary);
        }
        else if (userchoice == 9)
        {
            TwoBOneQ_Encoding(binary);

        }
        cout << endl;

    } while (userchoice != 0);



}
