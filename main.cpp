#include <windows.h>
#include <commctrl.h>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include "resource.h"

HINSTANCE hInst;
HWND h_dccao, h_cpcao, h_pvivo, h_gord1, h_check1, h_check2, h_dccao2, h_cpcao2, h_gord2, h_pcao, h_estat, h_imc;

BOOL CALLBACK DlgMain(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
    case WM_INITDIALOG:
    {
        h_dccao = GetDlgItem(hwndDlg, DCCAO);
        h_cpcao = GetDlgItem(hwndDlg, CPCAO);
        h_pvivo = GetDlgItem(hwndDlg, PVIVO);
        h_gord1 = GetDlgItem(hwndDlg, GORD1);
        h_check1 = GetDlgItem(hwndDlg, CHECK1);
        h_check2 = GetDlgItem(hwndDlg, CHECK2);
        h_dccao2 = GetDlgItem(hwndDlg, DCCAO2);
        h_cpcao2 = GetDlgItem(hwndDlg, CPCAO2);
        h_gord2 = GetDlgItem(hwndDlg, GORD2);
        h_pcao = GetDlgItem(hwndDlg, PCAO);
        h_estat = GetDlgItem(hwndDlg, ESTAT);
        h_imc = GetDlgItem(hwndDlg, IMC);
    }
    return TRUE;

    case WM_CLOSE:
    {
        EndDialog(hwndDlg, 0);
    }
    return TRUE;

    case WM_COMMAND:
    {
        switch(LOWORD(wParam))
        {
        case CALC1:
            char c_dccao[10], c_cpcao[10], c_pvivo[10];
            GetWindowText(h_dccao, c_dccao, 10);
            GetWindowText(h_cpcao, c_cpcao, 10);
            GetWindowText(h_pvivo, c_pvivo, 10);

            float f_dccao, f_cpcao, f_pvivo, f_resultado;
            f_dccao = atof(c_dccao);
            f_cpcao = atof(c_cpcao);
            f_pvivo = atof(c_pvivo);

            f_resultado = (-0.0034*(pow(f_dccao,2))+0.0027*(pow(f_cpcao,2))-1.9)/f_pvivo;

            char c_resultado[15];

            sprintf(c_resultado, "%.2f", f_resultado);
            SetWindowText(h_gord1, c_resultado);
            break;

        case CALC3:
            char c_pcao[10], c_estat[10];
            GetWindowText(h_pcao, c_pcao, 10);
            GetWindowText(h_estat, c_estat, 10);

            float f_pcao, f_estat, f_resultado3;
            f_pcao = atof(c_pcao);
            f_estat = atof(c_estat);

            f_resultado3 = f_pcao/(pow(f_estat,2));

            char c_resultado3[15];

            sprintf(c_resultado3, "%.2f", f_resultado3);
            SetWindowText(h_imc, c_resultado3);
            break;

        case CALC2:
            char c_dccao2[10], c_cpcao2[10];
            GetWindowText(h_dccao2, c_dccao2, 10);
            GetWindowText(h_cpcao2, c_cpcao2, 10);

            int i_check1 = SendMessage(h_check1, BM_GETCHECK, 0, 0);
            int i_check2 = SendMessage(h_check2, BM_GETCHECK, 0, 0);

            if(i_check1 == BST_CHECKED){
                float f_dccao2, f_cpcao2, f_resultado2;
                f_dccao2 = atof(c_dccao2);
                f_cpcao2 = atof(c_cpcao2);

                f_resultado2 = (-1.7*f_dccao2)+(0.93*f_cpcao2)+5;
                //f_resultado2 = (-1.4*f_dccao2)+(0.77*f_cpcao2)+4;

                char c_resultado2[15];
                sprintf(c_resultado2, "%.2f", f_resultado2);

                SetWindowText(h_gord2, c_resultado2);

            }else if(i_check2 == BST_CHECKED){
                float f_dccao2, f_cpcao2, f_resultado2;
                f_dccao2 = atof(c_dccao2);
                f_cpcao2 = atof(c_cpcao2);

                //f_resultado2 = (-1.7*f_dccao2)+(0.93*f_cpcao2)+5;
                f_resultado2 = (-1.4*f_dccao2)+(0.77*f_cpcao2)+4;

                char c_resultado2[15];
                sprintf(c_resultado2, "%.2f", f_resultado2);

                SetWindowText(h_gord2, c_resultado2);
            }
            break;
        }
    }
    return TRUE;
    }
    return FALSE;
}


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    hInst=hInstance;
    InitCommonControls();
    return DialogBox(hInst, MAKEINTRESOURCE(DLG_MAIN), NULL, (DLGPROC)DlgMain);
}
