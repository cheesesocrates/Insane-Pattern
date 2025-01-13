#include <iostream>

using namespace std;

int center, pyramid1, spacesInside, spacesborder, columns, MaxNum, TotalLines, count = 0;
char first, second;
bool toggle = false, twochar = true;

int main()
{

    int lines, PeakSpace = 3;

    cout << "Enter lines: ";
    cin >> lines;

    if (lines < 5)
    {
        cout << "Invalid lines." << endl;
        return 0;
    }

    cout << "Enter first character: ";
    cin >> first;
    cout << "Enter second character: ";
    cin >> second;

    cout << endl;

    // So only one char and one space between them gets printed
    if (lines < 15)
    {
        twochar = 0;
        PeakSpace = 1;
    }

    // Max num in inner pyramid
    MaxNum = ((lines / 5) - 1);

    // inner Center box formula
    center = 2 * MaxNum - 1;
    if (center < 0)
        center = 0;

    // borders between characters
    spacesborder = ((lines - 1) / 20);

    // Spaces inside the pyramid. 2 at the very least
    spacesInside = (center != 0 && spacesborder != 0) ? lines / 10 : 2;

    // Columns formula (depends on spacesborder and spacesInside)
    columns = (center != 0 && lines >= 15) ? (4 + (2 * spacesborder) + (2 * spacesInside) + center) : (lines < 15) ? (2 + (2 * spacesInside) + center)
                                                                                                                   : 3;

    // Pyramid formula (depends on columns)
    pyramid1 = (columns / 2) + 1;

    // if lines are 5, pyramid is 2
    if (lines == 5)
        pyramid1 = 2;

    // if lines less than 15, spaces between inside figure formula
    if (lines < 15)
    {
        pyramid1 = ((lines - center) / 2);
        spacesInside = pyramid1 - 2;
    }

    // Total lines formula
    TotalLines = (pyramid1 * 2) + center;

    // loop for total lines rather lines
    for (int i = 0; i < TotalLines; i++)
    {
        // changes toggle every iteration
        toggle = !toggle;

        // case for lines above 15
        if (lines >= 15)
        {
            // first pyramid
            if (i < pyramid1)
            {
                // tip of pyramid
                if (i < spacesborder + 1)
                {
                    // spaces loop
                    for (int j = i; j < pyramid1 - 1; j++)
                    {
                        cout << ' ';
                    }

                    // first row has first char only
                    if (i == 0)
                    {
                        cout << first;
                        toggle = !toggle;
                    }

                    // next row either has 2 or 3 chars
                    else if (i == 1)
                    {
                        cout << first;

                        cout << ' ';

                        cout << second;
                    }
                    // rows before 2nd top pyramid layer
                    else
                    {
                        if (toggle)
                            cout << first;
                        else
                            cout << second;

                        toggle = !toggle;

                        for (int j = 0; j < PeakSpace; j++)
                            cout << ' ';

                        if (toggle)
                            cout << first;
                        else
                            cout << second;

                        toggle = !toggle;

                        PeakSpace += 2;
                    }
                }

                // the tip of second top pyramid
                else if (i == spacesborder + 1)
                {
                    for (int j = i; j < pyramid1 - 1; j++)
                    {
                        cout << ' ';
                    }

                    if (toggle)
                        cout << first;
                    else
                        cout << second;

                    toggle = !toggle;

                    for (int j = 0; j < spacesborder; j++)
                        cout << ' ';

                    if (twochar)
                        if (toggle)
                            cout << first;
                        else
                            cout << second;

                    toggle = !toggle;

                    for (int j = 0; j < spacesborder; j++)
                    {
                        cout << ' ';
                    }

                    if (toggle)
                        cout << first;
                    else
                        cout << second;

                    toggle = !toggle;
                }

                // pyramid except top peak
                else
                {
                    // k is initialise to 0 in first loop statement of this
                    int k = i - (spacesborder + 2);

                    for (int j = 0; j < (2 * (pyramid1 - 1)); j++)
                    {
                        //       ----X--|--X----
                        //       ---X---|---X---  and so on
                        if (j == pyramid1 - k - (spacesborder + 3) || j == pyramid1 + k - (spacesborder + 1))
                        {
                            if (toggle)
                                cout << first;
                            else
                                cout << second;

                            toggle = !toggle;

                            for (int j = 0; j < spacesborder; j++)
                                cout << ' ';

                            if (twochar)
                                if (toggle)
                                    cout << first;
                                else
                                    cout << second;

                            toggle = !toggle;
                        }
                        else
                            cout << ' ';
                    }
                }
            }

            // center body
            else if (i < center + pyramid1)
            {
                // to initialise loop variable to 1
                int k = i - pyramid1 + 1;

                // left border
                if (toggle)
                    cout << first;
                else
                    cout << second;

                toggle = !toggle;

                for (int j = 0; j < spacesborder; j++)
                    cout << ' ';

                if (twochar)
                    if (toggle)
                        cout << first;
                    else
                        cout << second;

                toggle = !toggle;

                for (int j = 0; j < spacesInside; j++)
                    cout << ' ';

                // inner pyramids till maxnum row
                if (k <= MaxNum)
                {
                    for (int j = 1; j <= MaxNum - k; j++)
                        cout << first;

                    for (int j = 1; j < k + 1; j++)
                        cout << j;

                    for (int j = k - 1; j > 0; j--)
                        cout << j;

                    for (int j = 0; j < MaxNum - k; j++)
                        cout << first;
                }

                // lower half of the center pyramid
                else
                {
                    // so we dont exceed max num and start going in decreasing order
                    k = k - MaxNum;

                    for (int j = MaxNum; j > MaxNum - k; j--)
                        cout << first;

                    for (int j = 0; j <= MaxNum - k - 1; j++)
                        cout << j + 1;

                    for (int j = 0; j <= MaxNum - k - 2; j++)
                        cout << ' ';

                    for (int j = MaxNum; j > MaxNum - k; j--)
                        cout << first;
                }

                for (int j = 0; j < spacesInside; j++)
                    cout << ' ';

                // right borders
                if (toggle)
                    cout << first;
                else
                    cout << second;

                toggle = !toggle;

                for (int j = 0; j < spacesborder; j++)
                    cout << ' ';

                if (twochar)
                    if (toggle)
                        cout << first;
                    else
                        cout << second;

                toggle = !toggle;

                // in case total lines not reached, repeat center layer
                while (count < lines - TotalLines && i == pyramid1 + (center / 2))
                {
                    toggle = !toggle;
                    cout << endl;
                    int k = i - pyramid1 + 1;

                    if (toggle)
                        cout << first;
                    else
                        cout << second;

                    toggle = !toggle;

                    for (int j = 0; j < spacesborder; j++)
                        cout << ' ';

                    if (twochar)
                        if (toggle)
                            cout << first;
                        else
                            cout << second;

                    toggle = !toggle;

                    for (int j = 0; j < spacesInside; j++)
                        cout << ' ';

                    // inner pyramids
                    if (k <= MaxNum)
                    {
                        for (int j = 1; j <= MaxNum - k; j++)
                            cout << first;

                        for (int j = 1; j < k + 1; j++)
                            cout << j;

                        for (int j = k - 1; j > 0; j--)
                            cout << j;

                        for (int j = 0; j < MaxNum - k; j++)
                            cout << first;
                    }
                    else
                    {
                        k = k - MaxNum;

                        for (int j = MaxNum; j > MaxNum - k; j--)
                            cout << first;

                        for (int j = 0; j <= MaxNum - k - 1; j++)
                            cout << j + 1;

                        for (int j = 0; j <= MaxNum - k - 2; j++)
                            cout << ' ';

                        for (int j = MaxNum; j > MaxNum - k; j--)
                            cout << first;
                    }

                    for (int j = 0; j < spacesInside; j++)
                        cout << ' ';

                    if (toggle)
                        cout << first;
                    else
                        cout << second;

                    toggle = !toggle;

                    for (int j = 0; j < spacesborder; j++)
                        cout << ' ';

                    if (twochar)
                        if (toggle)
                            cout << first;
                        else
                            cout << second;

                    toggle = !toggle;

                    count++;
                }
            }
            // final triangle
            else
            {
                // same code as top pyramid, but mirror variable so reverse is printed
                int iMirror = TotalLines - i - 1;

                // Tip of pyramid
                if (iMirror < spacesborder + 1)
                {
                    for (int j = iMirror; j < pyramid1 - 1; j++)
                    {
                        cout << ' ';
                    }

                    if (iMirror == 0)
                    {
                        if (toggle)
                            cout << first;
                        else
                            cout << second;

                        toggle = !toggle;
                    }
                    else if (iMirror == 1)
                    {
                        cout << first;
                        cout << ' ';
                        cout << second;
                    }
                    else
                    {

                        PeakSpace -= 2;
                        if (toggle)
                            cout << first;
                        else
                            cout << second;

                        toggle = !toggle;

                        for (int j = 0; j < PeakSpace; j++)
                            cout << ' ';

                        if (toggle)
                            cout << first;
                        else
                            cout << second;

                        toggle = !toggle;
                    }
                }
                else if (iMirror == spacesborder + 1)
                {
                    for (int j = iMirror; j < pyramid1 - 1; j++)
                    {
                        cout << ' ';
                    }

                    if (toggle)
                        cout << first;
                    else
                        cout << second;

                    toggle = !toggle;

                    for (int j = 0; j < spacesborder; j++)
                        cout << ' ';

                    if (twochar)
                        if (toggle)
                            cout << first;
                        else
                            cout << second;

                    toggle = !toggle;

                    for (int j = 0; j < spacesborder; j++)
                    {
                        cout << ' ';
                    }

                    if (toggle)
                        cout << first;
                    else
                        cout << second;

                    toggle = !toggle;
                }
                // Pyramid except top peak
                else
                {
                    int k = iMirror - (spacesborder + 2);

                    for (int j = 0; j < (2 * (pyramid1 - 1)); j++)
                    {
                        if (j == pyramid1 - k - (spacesborder + 3) || j == pyramid1 + k - (spacesborder + 1))
                        {
                            if (toggle)
                                cout << first;
                            else
                                cout << second;

                            toggle = !toggle;

                            for (int j = 0; j < spacesborder; j++)
                                cout << ' ';

                            if (twochar)
                                if (toggle)
                                    cout << first;
                                else
                                    cout << second;

                            toggle = !toggle;
                        }
                        else
                            cout << ' ';
                    }
                }
            }
        }
        // for lines less than 15
        else
        {
            // top pyramid
            if (i < pyramid1)
            {
                for (int j = i + 1; j < pyramid1; j++)
                {
                    cout << ' ';
                }

                // tip of pyramid
                if (i == 0)
                {
                    if (toggle)
                        cout << first;
                    else
                        cout << second;

                    toggle = !toggle;
                }

                // else, pyramid forms without second character
                else
                {
                    if (toggle)
                        cout << first;
                    else
                        cout << second;

                    toggle = !toggle;

                    for (int j = 0; j < PeakSpace; j++)
                        cout << ' ';

                    if (toggle)
                        cout << first;
                    else
                        cout << second;

                    toggle = !toggle;

                    // peak space increases to make pyramid diverge
                    PeakSpace += 2;
                }
            }
            // center box
            else if (i < center + pyramid1 && center != 0)
            {
                int k = i - pyramid1;

                // left border
                if (toggle)
                    cout << first;
                else
                    cout << second;

                toggle = !toggle;

                // inner pyramid
                for (int j = 0; j < spacesInside; j++)
                    cout << ' ';

                for (int j = 1; j < MaxNum + 1; j++)
                    cout << j;

                for (int j = 0; j < spacesInside; j++)
                    cout << ' ';

                // right border
                if (toggle)
                    cout << first;
                else
                    cout << second;

                toggle = !toggle;

                // top make lines reach desired amount
                while (count < lines - TotalLines && i == pyramid1 + (center / 2))
                {
                    toggle = !toggle;
                    cout << endl;
                    if (toggle)
                        cout << first;
                    else
                        cout << second;

                    toggle = !toggle;

                    for (int j = 0; j < spacesInside; j++)
                        cout << ' ';

                    for (int j = 1; j < MaxNum + 1; j++)
                        cout << j;

                    for (int j = 0; j < spacesInside; j++)
                        cout << ' ';

                    if (toggle)
                        cout << first;
                    else
                        cout << second;

                    toggle = !toggle;
                    count++;
                }
            }
            // bottom pyramid
            else
            {
                // same as above pyramid but using mirrored i
                int iMirror = TotalLines - i - 1;

                for (int j = iMirror + 1; j < pyramid1; j++)
                {
                    cout << ' ';
                }

                if (iMirror == 0)
                {
                    if (toggle)
                        cout << first;
                    else
                        cout << second;

                    toggle = !toggle;
                }
                else
                {
                    PeakSpace -= 2;
                    if (toggle)
                        cout << first;
                    else
                        cout << second;

                    toggle = !toggle;

                    for (int j = 0; j < PeakSpace; j++)
                        cout << ' ';

                    if (toggle)
                        cout << first;
                    else
                        cout << second;

                    toggle = !toggle;
                }
            }
        }

        cout << endl;
    }
}
