/*
 * (c) Copyright IBM Corp., 2000, 2001
 * All Rights Reserved.
 */

/**
 * SWT OS natives implementation.
 */ 

#include "globals.h"
#include "structs.h"

/* export the dll version info call */

__declspec(dllexport) HRESULT DllGetVersion(DLLVERSIONINFO *dvi);

HRESULT DllGetVersion(DLLVERSIONINFO *dvi)
{
     dvi->dwMajorVersion = SWT_LIBRARY_MAJOR_VERSION;
     dvi->dwMinorVersion = SWT_LIBRARY_MINOR_VERSION;
     dvi->dwBuildNumber = SWT_LIBRARY_BUILD_NUM;
     dvi->dwPlatformID = DLLVER_PLATFORM_WINDOWS;
     return 1;
}

#ifdef _WIN32_WCE
#define ChooseColorA ChooseColor
#define ChooseColorW ChooseColor
#define CHOOSECOLORA CHOOSECOLOR
#define CHOOSECOLORW CHOOSECOLOR
#define LPCHOOSECOLORW LPCHOOSECOLOR
#define FONTENUMPROCW FONTENUMPROC
#define ImmGetCompositionFontA ImmGetCompositionFont
#define ImmSetCompositionFontA ImmSetCompositionFont
#define ImmGetCompositionStringA ImmGetCompositionString
#define CallWindowProcA CallWindowProc
#define CharLowerA CharLower
#define CharUpperA CharUpper
#define CreateAcceleratorTableA CreateAcceleratorTable
#define CreateDCA CreateDC 
#define CreateFontIndirectA CreateFontIndirect 
#define CreateWindowExA CreateWindowEx 
#define DefWindowProcA DefWindowProc 
#define DispatchMessageA DispatchMessage 
#define DrawTextA DrawText 
#define EnumFontFamiliesA EnumFontFamilies 
#define ExtractIconExA ExtractIconEx 
#define GetClassInfoA GetClassInfo 
#define GetMenuItemInfoA GetMenuItemInfo 
#define GetMessageA GetMessage 
#define GetModuleHandleA GetModuleHandle 
#define GetObjectA GetObject 
#define GetOpenFileNameA GetOpenFileName 
#define GetSaveFileNameA GetSaveFileName 
#define GetTextMetricsA GetTextMetrics 
#define GetWindowLongA GetWindowLong 
#define GetWindowTextA GetWindowText 
#define GetWindowTextLengthA GetWindowTextLength 
#define LoadBitmapA LoadBitmap 
#define LoadCursorA LoadCursor 
#define LoadIconA LoadIcon 
#define LoadLibraryA LoadLibrary 
#define MapVirtualKeyA MapVirtualKey 
#define MessageBoxA MessageBox 
#define PeekMessageA PeekMessage 
#define PostMessageA PostMessage 
#define PostThreadMessageA PostThreadMessage 
#define RegisterClassA RegisterClass 
#define RegEnumKeyExA RegEnumKeyEx 
#define RegOpenKeyExA RegOpenKeyEx 
#define RegQueryInfoKeyA RegQueryInfoKey 
#define RegQueryValueExA RegQueryValueEx 
#define SendMessageA SendMessage 
#define SetMenuItemInfoA SetMenuItemInfo 
#define SetWindowLongA SetWindowLong 
#define SetWindowTextA SetWindowText 
#define TranslateAcceleratorA TranslateAccelerator 
#define UnregisterClassA UnregisterClass 
#define GetTextExtentPoint32A GetTextExtentPoint32 
#define LoadImageA LoadImage 
#define ExtTextOutA ExtTextOut 
#define GetLocaleInfoA GetLocaleInfo 
#define EnumSystemLocalesA EnumSystemLocales 
#define SystemParametersInfoA SystemParametersInfo 
#define InsertMenuA InsertMenu 
#define GetVersionExA GetVersionEx 
#define ShellExecuteExA ShellExecuteEx
#define ShellExecuteExW ShellExecuteEx
#endif

#ifndef _WIN32_WCE

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetVersion
 * Signature: ()I
 */
 /*
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetVersion
  (JNIEnv *env, jclass that)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetVersion\n");
#endif

    return (jint) GetVersion();
}
*/

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    AbortDoc
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_AbortDoc
  (JNIEnv *env, jclass that, jint hdc)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "AbortDoc\n");
#endif
    return (jint) AbortDoc((HDC)hdc);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    OleInitialize
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_OleInitialize
  (JNIEnv *env, jclass that, jint pvReserved)
{
    return (jint) OleInitialize ((LPVOID)pvReserved);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    OleUninitialize
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_win32_OS_OleUninitialize
  (JNIEnv *env, jclass that)
{
   OleUninitialize (); 
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    Arc
 * Signature: (IIIIIIIII)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_Arc
  (JNIEnv *env, jclass that, jint hdc, jint nLeftRect, jint nTopRect, jint nRightRect, jint nBottomRect, jint nXStartArc,jint nYStartArc, jint nXEndArc, jint nYEndArc)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "Arc\n");
#endif

    return (jboolean) Arc((HDC)hdc, nLeftRect, nTopRect, nRightRect, nBottomRect, nXStartArc, nYStartArc, nXEndArc, nYEndArc);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ChooseFontA
 * Signature: (Lorg/eclipse/swt/internal/win32/CHOOSEFONT;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_ChooseFontA
  (JNIEnv *env, jclass that, jobject chooseFont)
{
	DECL_GLOB(pGlob)
    CHOOSEFONT choosefont, *chooseFont1=NULL;
    jboolean rc;
    
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "ChooseFont\n");
#endif

    if (chooseFont) {
        chooseFont1 = &choosefont;
        cacheChoosefontFids(env, chooseFont, &PGLOB(ChoosefontFc));
        getChoosefontFields(env, chooseFont, chooseFont1, &PGLOB(ChoosefontFc));
    }
    rc = (jboolean) ChooseFontA(chooseFont1);
    if (chooseFont) {
        setChoosefontFields(env, chooseFont, chooseFont1, &PGLOB(ChoosefontFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ChooseFontW
 * Signature: (Lorg/eclipse/swt/internal/win32/CHOOSEFONT;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_ChooseFontW
  (JNIEnv *env, jclass that, jobject chooseFont)
{
	DECL_GLOB(pGlob)
    CHOOSEFONT choosefont, *chooseFont1=NULL;
    jboolean rc;
    
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "ChooseFontW\n");
#endif

    if (chooseFont) {
        chooseFont1 = &choosefont;
        cacheChoosefontFids(env, chooseFont, &PGLOB(ChoosefontFc));
        getChoosefontFields(env, chooseFont, chooseFont1, &PGLOB(ChoosefontFc));
    }
    rc = (jboolean) ChooseFontW((LPCHOOSEFONTW) chooseFont1);
    if (chooseFont) {
        setChoosefontFields(env, chooseFont, chooseFont1, &PGLOB(ChoosefontFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    CopyImage
 * Signature: (IIIII)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_CopyImage
  (JNIEnv *env, jclass that, jint hImage, jint uType, jint cxDesired, jint cyDesired, jint fuFlags)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "CopyImage\n");
#endif

    return (jint)CopyImage((HANDLE)hImage, uType, cxDesired, cyDesired, fuFlags);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    CreateCursor
 * Signature: (IIIII[B[B)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_CreateCursor
  (JNIEnv *env, jclass that, jint hInst, jint xHotSpot, jint yHotSpot, jint nWidth, jint nHeight, jbyteArray pvANDPlane, jbyteArray pvXORPlane)
{
    CONST VOID *pvANDPlane1=NULL;
    CONST VOID *pvXORPlane1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "CreateCursor\n");
#endif

    if (pvANDPlane)
        pvANDPlane1 = (CONST VOID *)(*env)->GetByteArrayElements(env,pvANDPlane, NULL);

    if (pvXORPlane)
        pvXORPlane1 = (CONST VOID *)(*env)->GetByteArrayElements(env,pvXORPlane, NULL);

    rc = (jint)CreateCursor((HINSTANCE) hInst, xHotSpot, yHotSpot, nWidth, nHeight, pvANDPlane1, pvXORPlane1);

    if (pvANDPlane)
        (*env)->ReleaseByteArrayElements(env, pvANDPlane, (jbyte *)pvANDPlane1, 0);

    if (pvXORPlane)
        (*env)->ReleaseByteArrayElements(env, pvXORPlane, (jbyte *)pvXORPlane1, 0);

    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    CreateBitmapIndirect
 * Signature: (Lorg/eclipse/swt/internal/win32/BITMAP;)I
 */
 /*
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_CreateBitmapIndirect
  (JNIEnv *env, jclass that, jobject lpbm)
{
	DECL_GLOB(pGlob)
    BITMAP bm, *lpbm1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "CreateBitmapIndirect\n");
#endif

    if (lpbm) {
        lpbm1= &bm;
        cacheBitmapFids(env, lpbm, &PGLOB(BitmapFc));
        getBitmapFields(env, lpbm, lpbm1, &PGLOB(BitmapFc));
    }
    rc = (jint) CreateBitmapIndirect(lpbm1);
    if (lpbm) {
        setBitmapFields(env, lpbm, lpbm1, &PGLOB(BitmapFc));
    }
    return rc;

}
*/

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    DestroyCursor
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_DestroyCursor
  (JNIEnv *env, jclass that, jint hCursor)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "DestroyCursor\n");
#endif

    return (jboolean) DestroyCursor((HCURSOR)hCursor);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    DragDetect
 * Signature: (ILorg/eclipse/swt/internal/win32/POINT;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_DragDetect
  (JNIEnv *env, jclass that, jint hwnd, jobject pt)
{
	DECL_GLOB(pGlob)
    POINT point, *pt1=NULL;
    
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "DragDetect\n");
#endif

    if (pt) {
        pt1 = &point;
        cachePointFids(env, pt, &PGLOB(PointFc));
        getPointFields(env, pt, pt1, &PGLOB(PointFc));
    }
    return (jboolean) DragDetect((HWND)hwnd, *pt1);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    EnableScrollBar
 * Signature: (III)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_EnableScrollBar
  (JNIEnv *env, jclass that, jint hWnd, jint wSBflags, jint wArrows)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "EnableScrollBar\n");
#endif

    return (jboolean) EnableScrollBar((HWND)hWnd, wSBflags, wArrows);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    EndDoc
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_EndDoc
  (JNIEnv *env, jclass that, jint hdc)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "EndDoc\n");
#endif
    return (jint) EndDoc((HDC)hdc);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    EndPage
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_EndPage
  (JNIEnv *env, jclass that, jint hdc)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "EndPage\n");
#endif
    return (jint) EndPage((HDC)hdc);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ExpandEnvironmentStringsA
 * Signature: ([B[BI)I
 */
 /*
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_ExpandEnvironmentStringsA
  (JNIEnv *env, jclass that, jbyteArray lpSrc, jbyteArray lpDest, jint nSize)
{
    jbyte* lpSrc1=NULL, *lpDest1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "ExpandEnvironmentStringsA\n");
#endif

    if (lpSrc)
        lpSrc1 = (*env)->GetByteArrayElements(env, lpSrc, NULL);
    if (lpDest)
        lpDest1 = (*env)->GetByteArrayElements(env, lpDest, NULL);

    rc = (jint) ExpandEnvironmentStringsA((LPSTR)lpSrc1, (LPSTR)lpDest1, nSize);

    if (lpSrc)
        (*env)->ReleaseByteArrayElements(env, lpSrc, (jbyte *)lpSrc1, 0);
    if (lpDest)
        (*env)->ReleaseByteArrayElements(env, lpDest, (jbyte *)lpDest1, 0);

    return rc;
}
*/
/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ExpandEnvironmentStringsW
 * Signature: ([B[BI)I
 */
 /*
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_ExpandEnvironmentStringsW
  (JNIEnv *env, jclass that, jbyteArray lpSrc, jbyteArray lpDest, jint nSize)
{
    jchar* lpSrc1=NULL, *lpDest1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "ExpandEnvironmentStringsW\n");
#endif

    if (lpSrc)
        lpSrc1 = (*env)->GetCharArrayElements(env, lpSrc, NULL);
    if (lpDest)
        lpDest1 = (*env)->GetCharArrayElements(env, lpDest, NULL);

    rc = (jint) ExpandEnvironmentStringsW((LPWSTR)lpSrc1, (LPWSTR)lpDest1, nSize);

    if (lpSrc)
        (*env)->ReleaseCharArrayElements(env, lpSrc, lpSrc1, 0);
    if (lpDest)
        (*env)->ReleaseCharArrayElements(env, lpDest, lpDest1, 0);

    return rc;
}
*/
/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetCharABCWidthsA
 * Signature: (III[I)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_GetCharABCWidthsA
  (JNIEnv *env, jclass that, jint hdc, jint iFirstChar, jint iLastChar, jintArray lpabc)
{
    LPABC lpabc1=NULL;
    jboolean rc;
    
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetCharABCWidthsA\n");
#endif
    
    if (lpabc)
        lpabc1 = (LPABC)(*env)->GetIntArrayElements(env, lpabc, NULL);
        
    rc = (jboolean) GetCharABCWidthsA((HDC)hdc, iFirstChar, iLastChar, lpabc1);
    
    if (lpabc)
        (*env)->ReleaseIntArrayElements(env, lpabc, (jint *)lpabc1, 0);
        
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetCharABCWidthsW
 * Signature: (III[I)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_GetCharABCWidthsW
  (JNIEnv *env, jclass that, jint hdc, jint iFirstChar, jint iLastChar, jintArray lpabc)
{
    LPABC lpabc1=NULL;
    jboolean rc;
    
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetCharABCWidthsW\n");
#endif
    
    if (lpabc)
        lpabc1 = (LPABC)(*env)->GetIntArrayElements(env, lpabc, NULL);
        
    rc = (jboolean) GetCharABCWidthsW((HDC)hdc, iFirstChar, iLastChar, lpabc1);
    
    if (lpabc)
        (*env)->ReleaseIntArrayElements(env, lpabc, (jint *)lpabc1, 0);
        
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetCharWidthA
 * Signature: (III[I)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_GetCharWidthA
  (JNIEnv *env, jclass that, jint hdc, jint iFirstCharacter, jint iLastCharacter, jintArray lpBuffer)
{
    LPINT lpBuffer1=NULL;
    jboolean rc;
    
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetCharWidthA\n");
#endif
    
    if (lpBuffer)
        lpBuffer1 = (LPINT)(*env)->GetIntArrayElements(env, lpBuffer, NULL);
        
    rc = (jboolean) GetCharWidthA((HDC)hdc, iFirstCharacter, iLastCharacter, lpBuffer1);
    
    if (lpBuffer)
        (*env)->ReleaseIntArrayElements(env, lpBuffer, (jint *)lpBuffer1, 0);
        
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetCharWidthW
 * Signature: (III[I)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_GetCharWidthW
  (JNIEnv *env, jclass that, jint hdc, jint iFirstCharacter, jint iLastCharacter, jintArray lpBuffer)
{
    LPINT lpBuffer1=NULL;
    jboolean rc;
    
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetCharWidthW\n");
#endif
    
    if (lpBuffer)
        lpBuffer1 = (LPINT)(*env)->GetIntArrayElements(env, lpBuffer, NULL);
        
    rc = (jboolean) GetCharWidthW((HDC)hdc, iFirstCharacter, iLastCharacter, lpBuffer1);
    
    if (lpBuffer)
        (*env)->ReleaseIntArrayElements(env, lpBuffer, (jint *)lpBuffer1, 0);
        
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetDIBColorTable
 * Signature: (III[B)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetDIBColorTable
  (JNIEnv *env, jclass that, jint hdc, jint uStartIndex, jint cEntries, jbyteArray pColors)
{
    RGBQUAD *pColors1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetDIBColorTable\n");
#endif

    if (pColors)
        pColors1 = (RGBQUAD *)(*env)->GetByteArrayElements(env,pColors, NULL);

    rc = (jint)GetDIBColorTable((HDC)hdc, uStartIndex, cEntries, pColors1);

    if (pColors)
        (*env)->ReleaseByteArrayElements(env, pColors, (jbyte *)pColors1, 0);

    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetDIBits
 * Signature: (IIIII[BI)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetDIBits
  (JNIEnv *env, jclass that, jint hdc, jint hbmp, jint uStartScan, jint cScanLines, jint lpvBits, jbyteArray lpbi, jint uUsage)
{
    LPBITMAPINFO lpbi1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetDIBits\n");
#endif

    if (lpbi)
        lpbi1 = (LPBITMAPINFO)(*env)->GetByteArrayElements(env,lpbi, NULL);

    rc = (jint)GetDIBits((HDC)hdc, (HBITMAP)hbmp, uStartScan, cScanLines, (LPBITMAPINFO)lpvBits, lpbi1, uUsage);

    if (lpbi)
        (*env)->ReleaseByteArrayElements(env, lpbi, (jbyte *)lpbi1, 0);

    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetFileTitleA
 * Signature: ([B[BS)S
 */
JNIEXPORT jshort JNICALL Java_org_eclipse_swt_internal_win32_OS_GetFileTitleA
  (JNIEnv *env, jclass that, jbyteArray lpszFile, jbyteArray lpszTitle, jshort cbBuf)
{
    jbyte* lpszFile1=NULL, *lpszTitle1=NULL;
    jshort rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetFileTitleA\n");
#endif

    if (lpszFile)
        lpszFile1 = (*env)->GetByteArrayElements(env, lpszFile, NULL);
    if (lpszTitle)
        lpszTitle1 = (*env)->GetByteArrayElements(env, lpszTitle, NULL);

    rc = (jshort)GetFileTitleA((LPSTR)lpszFile1, (LPSTR)lpszTitle1, (WORD)cbBuf);

    if (lpszFile)
        (*env)->ReleaseByteArrayElements(env, lpszFile, lpszFile1, 0);
    if (lpszTitle)
        (*env)->ReleaseByteArrayElements(env, lpszTitle, lpszTitle1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetFileTitleW
 * Signature: ([C[CS)S
 */
JNIEXPORT jshort JNICALL Java_org_eclipse_swt_internal_win32_OS_GetFileTitleW
  (JNIEnv *env, jclass that, jcharArray lpszFile, jcharArray lpszTitle, jshort cbBuf)
{
    jchar* lpszFile1=NULL, *lpszTitle1=NULL;
    jshort rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetFileTitleW\n");
#endif

    if (lpszFile)
        lpszFile1 = (*env)->GetCharArrayElements(env, lpszFile, NULL);
    if (lpszTitle)
        lpszTitle1 = (*env)->GetCharArrayElements(env, lpszTitle, NULL);

    rc = (jshort)GetFileTitleW((LPWSTR)lpszFile1, (LPWSTR)lpszTitle1, (WORD)cbBuf);

    if (lpszFile)
        (*env)->ReleaseCharArrayElements(env, lpszFile, lpszFile1, 0);
    if (lpszTitle)
        (*env)->ReleaseCharArrayElements(env, lpszTitle, lpszTitle1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetIconInfo
 * Signature: (ILorg/eclipse/swt/internal/win32/ICONINFO;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_GetIconInfo
  (JNIEnv *env, jclass that, jint hIcon, jobject lpIconinfo)
{
	DECL_GLOB(pGlob)
    ICONINFO iconinfo, *lpIconinfo1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetIconInfo\n");
#endif

    if (lpIconinfo) {
        lpIconinfo1 = &iconinfo;
        cacheIconinfoFids(env, lpIconinfo, &PGLOB(IconinfoFc));
        getIconinfoFields(env, lpIconinfo, lpIconinfo1, &PGLOB(IconinfoFc));
    }
    rc = (jboolean) GetIconInfo((HICON)hIcon, lpIconinfo1);
    if (lpIconinfo) {
        setIconinfoFields(env, lpIconinfo, lpIconinfo1, &PGLOB(IconinfoFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetKeyboardState
 * Signature: ([B)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_GetKeyboardState
  (JNIEnv *env, jclass that, jbyteArray lpKeyState)
{
    PBYTE lpKeyState1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetKeyboardState\n");
#endif

    if (lpKeyState)
        lpKeyState1 = (*env)->GetByteArrayElements(env, lpKeyState, NULL);

    rc = (jboolean) GetKeyboardState(lpKeyState1);
    
    if (lpKeyState)
        (*env)->ReleaseByteArrayElements(env, lpKeyState, (jbyte *)lpKeyState1, 0);

    return rc;    
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetLastActivePopup
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetLastActivePopup
  (JNIEnv *env, jclass that, jint hWnd)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetLastActivePopup\n");
#endif

    return (jint) GetLastActivePopup((HWND) hWnd);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetMenu
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetMenu
  (JNIEnv *env, jclass that, jint hWnd)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetMenu\n");
#endif

    return (jint) GetMenu((HWND)hWnd);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetMenuDefaultItem
 * Signature: (III)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetMenuDefaultItem
  (JNIEnv *env, jclass that, jint hMenu, jint fByPos, jint gmdiFlags)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetMenuDefaultItem\n");
#endif

    return (jint) GetMenuDefaultItem((HMENU)hMenu, fByPos, gmdiFlags);
}

#ifdef USE_2000_CALLS
/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetMenuInfo
 * Signature: (ILorg/eclipse/swt/internal/win32/MENUINFO;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_GetMenuInfo
  (JNIEnv *env, jclass that, jint hmenu, jobject lpcmi)
{
	DECL_GLOB(pGlob)
    HMODULE hm;
    FARPROC fp;
    MENUINFO menuinfo, *lpcmi1=NULL;
    jboolean rc=FALSE;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetMenuInfo\n");
#endif

    /*
    **  GetMenuInfo is a Win2000 and Win98 specific call
    **  If you link it into swt.dll a system modal entry point not found dialog will
    **  appear as soon as swt.dll is loaded. Here we check for the entry point and
    **  only do the call if it exists.
    */
    if ((hm=GetModuleHandle("user32.dll")) && (fp=GetProcAddress(hm, "GetMenuInfo"))) {
        if (lpcmi) {
            lpcmi1 = &menuinfo;
            cacheMenuinfoFids(env, lpcmi, &PGLOB(MenuinfoFc));
            getMenuinfoFields(env, lpcmi, lpcmi1, &PGLOB(MenuinfoFc));
        }
        rc = (jboolean) (fp)((HMENU)hmenu, lpcmi1);
//        rc = (jboolean) GetMenuInfo((HMENU)hmenu, lpcmi1);
        if (lpcmi) {
            setMenuinfoFields(env, lpcmi, lpcmi1, &PGLOB(MenuinfoFc));
        }
    }
    return rc;
}
#endif

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetMenuItemCount
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetMenuItemCount
  (JNIEnv *env, jclass that, jint hMenu)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetMenuItemCount\n");
#endif

    return (jint) GetMenuItemCount((HMENU)hMenu);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetProfileStringA
 * Signature: ([B[B[B[BI)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetProfileStringA
  (JNIEnv *env, jclass that, jbyteArray lpAppName, jbyteArray lpKeyName, jbyteArray lpDefault, jbyteArray lpReturnedString, jint nSize)
{
    jbyte* lpAppName1=NULL, *lpKeyName1=NULL, *lpDefault1=NULL, *lpReturnedString1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetProfileStringA\n");
#endif
    if (lpAppName)
        lpAppName1 = (*env)->GetByteArrayElements(env,lpAppName, NULL);

    if (lpKeyName)
        lpKeyName1 = (*env)->GetByteArrayElements(env,lpKeyName, NULL);

    if (lpDefault)
        lpDefault1 = (*env)->GetByteArrayElements(env,lpDefault, NULL);

    if (lpReturnedString)
        lpReturnedString1 = (*env)->GetByteArrayElements(env,lpReturnedString, NULL);

    rc = (jint)GetProfileStringA((LPSTR)lpAppName1, (LPSTR)lpKeyName1, (LPSTR)lpDefault1, (LPSTR)lpReturnedString1, nSize);

    if (lpAppName)
        (*env)->ReleaseByteArrayElements(env, lpAppName, lpAppName1, 0);

    if (lpKeyName)
        (*env)->ReleaseByteArrayElements(env, lpKeyName, lpKeyName1, 0);

    if (lpDefault)
        (*env)->ReleaseByteArrayElements(env, lpDefault, lpDefault1, 0);

    if (lpReturnedString)
        (*env)->ReleaseByteArrayElements(env, lpReturnedString, lpReturnedString1, 0);

    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetProfileStringW
 * Signature: ([B[B[B[BI)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetProfileStringW
  (JNIEnv *env, jclass that, jcharArray lpAppName, jcharArray lpKeyName, jcharArray lpDefault, jcharArray lpReturnedString, jint nSize)
{
    jchar* lpAppName1=NULL, *lpKeyName1=NULL, *lpDefault1=NULL, *lpReturnedString1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetProfileStringW\n");
#endif
    if (lpAppName)
        lpAppName1 = (*env)->GetCharArrayElements(env,lpAppName, NULL);

    if (lpKeyName)
        lpKeyName1 = (*env)->GetCharArrayElements(env,lpKeyName, NULL);

    if (lpDefault)
        lpDefault1 = (*env)->GetCharArrayElements(env,lpDefault, NULL);

    if (lpReturnedString)
        lpReturnedString1 = (*env)->GetCharArrayElements(env,lpReturnedString, NULL);

    rc = (jint)GetProfileStringW((LPWSTR)lpAppName1, (LPWSTR)lpKeyName1, (LPWSTR)lpDefault1, (LPWSTR)lpReturnedString1, nSize);

    if (lpAppName)
        (*env)->ReleaseCharArrayElements(env, lpAppName, lpAppName1, 0);

    if (lpKeyName)
        (*env)->ReleaseCharArrayElements(env, lpKeyName, lpKeyName1, 0);

    if (lpDefault)
        (*env)->ReleaseCharArrayElements(env, lpDefault, lpDefault1, 0);

    if (lpReturnedString)
        (*env)->ReleaseCharArrayElements(env, lpReturnedString, lpReturnedString1, 0);

    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetROP2
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetROP2
  (JNIEnv *env, jclass that, jint hdc)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetROP2\n");
#endif

    return (jint) GetROP2((HDC)hdc);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetWindowPlacement
 * Signature: (ILorg/eclipse/swt/internal/win32/WINDOWPLACEMENT;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_GetWindowPlacement
  (JNIEnv *env, jclass that, jint hWnd, jobject lpwndpl)
{
	DECL_GLOB(pGlob)
    WINDOWPLACEMENT wndpl, *lpwndpl1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetWindowPlacement\n");
#endif

    if (lpwndpl) {
        lpwndpl1 = &wndpl;
        cacheWindowplacementFids(env, lpwndpl, &PGLOB(WindowplacementFc));
        getWindowplacementFields(env, lpwndpl, lpwndpl1, &PGLOB(WindowplacementFc));
    }
    rc = (jboolean) GetWindowPlacement((HWND)hWnd, lpwndpl1);
    if (lpwndpl) {
        setWindowplacementFields(env, lpwndpl, lpwndpl1, &PGLOB(WindowplacementFc));    }
    return rc;
}

#ifdef USE_2000_CALLS
/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GradientFill
 * Signature: (IIIIII)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_GradientFill
  (JNIEnv *env, jclass that, jint hdc, int pVertex, jint dwNumVertex, int pMesh, jint dwNumMesh, jint dwMode)
{
	DECL_GLOB(pGlob)
	BOOL rc = FALSE;
    HMODULE hm;
    FARPROC fp;
	
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GradientFill\n");
#endif
    /*
    **  GradientFill is a Win2000 and Win98 specific call
    **  If you link it into swt.dll, a system modal entry point not found dialog will
    **  appear as soon as swt.dll is loaded. Here we check for the entry point and
    **  only do the call if it exists.
    */
    if (! (hm = GetModuleHandle("msimg32.dll"))) hm = LoadLibrary("msimg32.dll");
    if (hm && (fp = GetProcAddress(hm, "GradientFill"))) {
		rc = fp((HDC)hdc, (PTRIVERTEX)pVertex, (ULONG)dwNumVertex, (PVOID)pMesh, (ULONG)dwNumMesh, (ULONG)dwMode);
//		rc = GradientFill((HDC)hdc, (PTRIVERTEX)pVertex, (ULONG)dwNumVertex, (PVOID)pMesh, (ULONG)dwNumMesh, (ULONG)dwMode);
    }
    return (jboolean) rc;
}
#endif

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    InsertMenuItemA
 * Signature: (IIZLorg/eclipse/swt/internal/win32/MENUITEMINFO;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_InsertMenuItemA
  (JNIEnv *env, jclass that, jint hMenu, jint uItem, jboolean fByPosition, jobject lpmii)
{
	DECL_GLOB(pGlob)
    MENUITEMINFO mii1, *lpmii1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "InsertMenuItemA\n");
#endif

    if (lpmii) {
        lpmii1 = &mii1;
        cacheMenuiteminfoFids(env, lpmii, &PGLOB(MenuiteminfoFc));
        getMenuiteminfoFields(env, lpmii, lpmii1, &PGLOB(MenuiteminfoFc));
    }
    rc = (jboolean) InsertMenuItemA((HMENU)hMenu, uItem, fByPosition, lpmii1);
    if (lpmii) {
        setMenuiteminfoFields(env, lpmii, lpmii1, &PGLOB(MenuiteminfoFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    InsertMenuItemW
 * Signature: (IIZLorg/eclipse/swt/internal/win32/MENUITEMINFO;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_InsertMenuItemW
  (JNIEnv *env, jclass that, jint hMenu, jint uItem, jboolean fByPosition, jobject lpmii)
{
	DECL_GLOB(pGlob)
    MENUITEMINFO mii1, *lpmii1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "InsertMenuItemW\n");
#endif

    if (lpmii) {
        lpmii1 = &mii1;
        cacheMenuiteminfoFids(env, lpmii, &PGLOB(MenuiteminfoFc));
        getMenuiteminfoFields(env, lpmii, lpmii1, &PGLOB(MenuiteminfoFc));
    }
    rc = (jboolean) InsertMenuItemW((HMENU)hMenu, uItem, fByPosition, (LPMENUITEMINFOW)lpmii1);
    if (lpmii) {
        setMenuiteminfoFields(env, lpmii, lpmii1, &PGLOB(MenuiteminfoFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    InvalidateRgn
 * Signature: (IIZ)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_InvalidateRgn
  (JNIEnv *env, jclass that, jint hWnd, jint hRgn, jboolean hErase)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "InvalidateRgn\n");
#endif

    return (jboolean) InvalidateRgn((HWND)hWnd, (HRGN)hRgn, hErase);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    IsIconic
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_IsIconic
  (JNIEnv *env, jclass that, jint hWnd)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "IsIconic\n");
#endif

    return (jboolean) IsIconic((HWND)hWnd);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    IsMenu
 * Signature: (I)Z
 */
 /*
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_IsMenu
  (JNIEnv *env, jclass that, jint hMenu)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "IsMenu\n");
#endif

    return (jboolean) IsMenu((HMENU)hMenu);
}
*/
/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    IsZoomed
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_IsZoomed
  (JNIEnv *env, jclass that, jint hWnd)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "IsZoomed\n");
#endif

    return (jboolean) IsZoomed((HWND)hWnd);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    LineTo
 * Signature: (III)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_LineTo
  (JNIEnv *env, jclass that, jint hdc, jint nXEnd, jint nYEnd)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "LineTo\n");
#endif

    return (jboolean) LineTo((HDC)hdc, nXEnd, nYEnd);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    MoveMemory
 * Signature: (Lorg/eclipse/swt/internal/win32/HELPINFO;II)V
 */
JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_win32_OS_MoveMemory__Lorg_eclipse_swt_internal_win32_HELPINFO_2II
  (JNIEnv *env, jclass that, jobject Destination, jint Source, jint Length)
{
	DECL_GLOB(pGlob)
    HELPINFO helpinfo, *lpDestination1=NULL;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "MoveMemory__Lorg_eclipse_swt_internal_win32_HELPINFO_2II\n");
#endif

    MoveMemory((PVOID)&helpinfo, (CONST VOID *)Source, Length);

    if (Destination) {
        lpDestination1 = &helpinfo;
        cacheHelpinfoFids(env, Destination, &PGLOB(HelpinfoFc));
        setHelpinfoFields(env, Destination, lpDestination1, &PGLOB(HelpinfoFc));
    }
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    MoveMemory
 * Signature: (ILorg/eclipse/swt/internal/win32/GRADIENT_RECT;I)V
 */
JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_win32_OS_MoveMemory__ILorg_eclipse_swt_internal_win32_GRADIENT_1RECT_2I
  (JNIEnv *env, jclass that, jint Destination, jobject Source, jint Length)
{
	DECL_GLOB(pGlob)
    GRADIENT_RECT gradientrect, *lpSource1=NULL;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "MoveMemory__ILorg_eclipse_swt_internal_win32_GRADIENT_1RECT_2I\n");
#endif

    if (Source) {
        lpSource1 = &gradientrect;
        cacheGradientrectFids(env, Source, &PGLOB(GradientrectFc));
        getGradientrectFields(env, Source, lpSource1, &PGLOB(GradientrectFc));
    }
    MoveMemory((PVOID)Destination, lpSource1, Length);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    MoveMemoryA
 * Signature: (ILorg/eclipse/swt/internal/win32/NMTTDISPINFO;I)V
 */
JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_win32_OS_MoveMemoryA__ILorg_eclipse_swt_internal_win32_NMTTDISPINFO_2I
  (JNIEnv * env, jclass that, jint Destination, jobject Source, jint Length)
{
	DECL_GLOB(pGlob)
    NMTTDISPINFO nmttdispinfo={0}, *lpSource1=NULL;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "MoveMemoryA__ILorg_eclipse_swt_internal_win32_NMTTDISPINFO_2I\n");
#endif

    if (Source) {
        lpSource1 = &nmttdispinfo;
        cacheNmttdispinfoFids(env, Source, &PGLOB(NmttdispinfoFc));
        getNmttdispinfoFieldsA(env, Source, lpSource1, &PGLOB(NmttdispinfoFc));
    }
    MoveMemory((PVOID)Destination, lpSource1, Length);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    MoveMemoryW
 * Signature: (ILorg/eclipse/swt/internal/win32/NMTTDISPINFO;I)V
 */
JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_win32_OS_MoveMemoryW__ILorg_eclipse_swt_internal_win32_NMTTDISPINFO_2I
  (JNIEnv * env, jclass that, jint Destination, jobject Source, jint Length)
{
	DECL_GLOB(pGlob)
    NMTTDISPINFOW nmttdispinfo={0}, *lpSource1=NULL;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "MoveMemoryW__ILorg_eclipse_swt_internal_win32_NMTTDISPINFO_2I\n");
#endif

    if (Source) {
        lpSource1 = &nmttdispinfo;
        cacheNmttdispinfoFids(env, Source, &PGLOB(NmttdispinfoFc));
        getNmttdispinfoFieldsW(env, Source, lpSource1, &PGLOB(NmttdispinfoFc));
    }
    MoveMemory((PVOID)Destination, lpSource1, Length);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    MoveMemory
 * Signature: (ILorg/eclipse/swt/internal/win32/TRIVERTEX;I)V
 */
JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_win32_OS_MoveMemory__ILorg_eclipse_swt_internal_win32_TRIVERTEX_2I
  (JNIEnv *env, jclass that, jint Destination, jobject Source, jint Length)
{
	DECL_GLOB(pGlob)
    TRIVERTEX trivertex, *lpSource1=NULL;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "MoveMemory__ILorg_eclipse_swt_internal_win32_TRIVERTEX_2I\n");
#endif

    if (Source) {
        lpSource1 = &trivertex;
        cacheTrivertexFids(env, Source, &PGLOB(TrivertexFc));
        getTrivertexFields(env, Source, lpSource1, &PGLOB(TrivertexFc));
    }
    MoveMemory((PVOID)Destination, lpSource1, Length);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    MoveMemoryA
 * Signature: (Lorg/eclipse/swt/internal/win32/NMTTDISPINFO;II)V
 */
JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_win32_OS_MoveMemoryA__Lorg_eclipse_swt_internal_win32_NMTTDISPINFO_2II
  (JNIEnv * env, jclass that, jobject Destination, jint Source, jint Length)
{
	DECL_GLOB(pGlob)
    NMTTDISPINFO nmttdispinfo={0}, *lpDestination1=NULL;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "MoveMemoryA__Lorg_eclipse_swt_internal_win32_NMTTDISPINFO_2II\n");
#endif

       MoveMemory((PVOID)&nmttdispinfo, (CONST VOID *)Source, Length);
    if (Destination) {
        lpDestination1 = &nmttdispinfo;
        cacheNmttdispinfoFids(env, Destination, &PGLOB(NmttdispinfoFc));
        setNmttdispinfoFieldsA(env, Destination, lpDestination1, &PGLOB(NmttdispinfoFc));
    }
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    MoveMemoryW
 * Signature: (Lorg/eclipse/swt/internal/win32/NMTTDISPINFO;II)V
 */
JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_win32_OS_MoveMemoryW__Lorg_eclipse_swt_internal_win32_NMTTDISPINFO_2II
  (JNIEnv * env, jclass that, jobject Destination, jint Source, jint Length)
{
	DECL_GLOB(pGlob)
    NMTTDISPINFOW nmttdispinfo={0}, *lpDestination1=NULL;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "MoveMemoryW__Lorg_eclipse_swt_internal_win32_NMTTDISPINFO_2II\n");
#endif

       MoveMemory((PVOID)&nmttdispinfo, (CONST VOID *)Source, Length);
    if (Destination) {
        lpDestination1 = &nmttdispinfo;
        cacheNmttdispinfoFids(env, Destination, &PGLOB(NmttdispinfoFc));
        setNmttdispinfoFieldsW(env, Destination, lpDestination1, &PGLOB(NmttdispinfoFc));
    }
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    MoveToEx
 * Signature: (IIII)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_MoveToEx
  (JNIEnv *env, jclass that, jint hdc, jint X, jint Y, jint lpPoint)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "MoveToEx\n");
#endif

    return (jboolean) MoveToEx((HDC)hdc, X, Y, (LPPOINT)lpPoint);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    Pie
 * Signature: (IIIIIIIII)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_Pie
  (JNIEnv *env, jclass that, jint hdc, jint nLeftRect, jint nTopRect, jint nRightRect, jint nBottomRect, jint nXStartArc, jint nYStartArc, jint nXEndArc, jint nYEndArc)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "Pie\n");
#endif

    return (jboolean) Pie((HDC)hdc, nLeftRect, nTopRect, nRightRect, nBottomRect, nXStartArc, nYStartArc, nXEndArc, nYEndArc);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    RedrawWindow
 * Signature: (ILorg/eclipse/swt/internal/win32/RECT;II)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_RedrawWindow
  (JNIEnv *env, jclass that, jint hWnd, jobject lprcUpdate, jint hrgnUpdate, jint flags)
{
	DECL_GLOB(pGlob)
    RECT rect, *lprcUpdate1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "RedrawWindow\n");
#endif

    if (lprcUpdate) {
        lprcUpdate1 = &rect;
        cacheRectFids(env, lprcUpdate, &PGLOB(RectFc));
        getRectFields(env, lprcUpdate, lprcUpdate1, &PGLOB(RectFc));
    }

    rc = (jboolean) RedrawWindow((HWND)hWnd, lprcUpdate1, (HRGN)hrgnUpdate, flags);

    if (lprcUpdate) {
        setRectFields(env, lprcUpdate, lprcUpdate1, &PGLOB(RectFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SendMessageA
 * Signature: (IIILorg/eclipse/swt/internal/win32/TOOLINFO;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SendMessageA__IIILorg_eclipse_swt_internal_win32_TOOLINFO_2
  (JNIEnv * env, jclass that, jint hWnd, jint Msg, jint wParam, jobject lParam)
{
	DECL_GLOB(pGlob)
    TOOLINFO toolinfo, *lpParam1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SendMessageA__IIILorg_eclipse_swt_internal_win32_TOOLINFO_2\n");
#endif

    if (lParam) {
        lpParam1 = &toolinfo;
        cacheToolinfoFids(env, lParam, &PGLOB(ToolinfoFc));
        getToolinfoFields(env, lParam, lpParam1, &PGLOB(ToolinfoFc));
    }
    rc = (jint) SendMessageA((HWND)hWnd, Msg, wParam, (LPARAM)lpParam1);
    if (lParam) {
        setToolinfoFields(env, lParam, lpParam1, &PGLOB(ToolinfoFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SendMessageW
 * Signature: (IIILorg/eclipse/swt/internal/win32/TOOLINFO;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SendMessageW__IIILorg_eclipse_swt_internal_win32_TOOLINFO_2
  (JNIEnv * env, jclass that, jint hWnd, jint Msg, jint wParam, jobject lParam)
{
	DECL_GLOB(pGlob)
    TOOLINFO toolinfo, *lpParam1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SendMessageW__IIILorg_eclipse_swt_internal_win32_TOOLINFO_2\n");
#endif

    if (lParam) {
        lpParam1 = &toolinfo;
        cacheToolinfoFids(env, lParam, &PGLOB(ToolinfoFc));
        getToolinfoFields(env, lParam, lpParam1, &PGLOB(ToolinfoFc));
    }
    rc = (jint) SendMessageW((HWND)hWnd, Msg, wParam, (LPARAM)lpParam1);
    if (lParam) {
        setToolinfoFields(env, lParam, lpParam1, &PGLOB(ToolinfoFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetMessageTime
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetMessageTime
  (JNIEnv *env, jclass that)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetMessageTime\n");
#endif

    return (jint) GetMessageTime();
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SetDIBColorTable
 * Signature: (III[B)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SetDIBColorTable
  (JNIEnv *env, jclass that, jint hdc, jint uStartIndex, jint cEntries, jbyteArray pColors)
{
    RGBQUAD *pColors1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SetDIBColorTable\n");
#endif

    if (pColors)
        pColors1 = (RGBQUAD *)(*env)->GetByteArrayElements(env,pColors, NULL);

    rc = (jint)SetDIBColorTable((HDC)hdc, uStartIndex, cEntries, pColors1);

    if (pColors)
        (*env)->ReleaseByteArrayElements(env, pColors, (jbyte *)pColors1, 0);

    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SetMapMode
 * Signature: (II)I
 */
 /*
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SetMapMode
  (JNIEnv *env, jclass that, jint hdc, jint fnMapMode)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SetMapMode\n");
#endif
    return (jint) SetMapMode((HDC)hdc, fnMapMode);
}
*/
/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SetMenu
 * Signature: (II)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_SetMenu
   (JNIEnv *env, jclass that, jint hWnd, jint hMenu)
{
#ifdef DEBUG_CALL_PRINTS
	fprintf(stderr, "SetMenu\n");
#endif

	return (jboolean) SetMenu((HWND)hWnd, (HMENU)hMenu);
}

/*
 * Class:		org_eclipse_swt_internal_win32_OS
 * Method:		ShowOwnedPopups
 * Signature:	(IZ)Z
 */

JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_ShowOwnedPopups
   (JNIEnv *env, jclass that, jint hWnd, jboolean fShow)
{
#ifdef DEBUG_CALL_PRINTS
	fprintf(stderr, "ShowOwnedPopups\n");
#endif

	return (jboolean) ShowOwnedPopups((HWND)hWnd, fShow);
}
 
/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SetMenuDefaultItem
 * Signature: (III)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_SetMenuDefaultItem
  (JNIEnv *env, jclass that, jint hMenu, jint uItem, jint fByPos)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SetMenuDefaultItem\n");
#endif

    return (jboolean) SetMenuDefaultItem((HMENU)hMenu, uItem, fByPos);
}

#ifdef USE_2000_CALLS
/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SetMenuInfo
 * Signature: (ILorg/eclipse/swt/internal/win32/MENUINFO;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_SetMenuInfo
  (JNIEnv *env, jclass that, jint hmenu, jobject lpcmi)
{
	DECL_GLOB(pGlob)
    HMODULE hm;
    FARPROC fp;
    MENUINFO menuinfo, *lpcmi1=NULL;
    jboolean rc=FALSE;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SetMenuInfo\n");
#endif
    
    /*
    **  SetMenuInfo is a Win2000 and Win98 specific call
    **  If you link it into swt.dll a system modal entry point not found dialog will
    **  appear as soon as swt.dll is loaded. Here we check for the entry point and
    **  only do the call if it exists.
    */
    if ((hm=GetModuleHandle("user32.dll")) && (fp=GetProcAddress(hm, "SetMenuInfo"))) {
        if (lpcmi) {
            lpcmi1 = &menuinfo;
            cacheMenuinfoFids(env, lpcmi, &PGLOB(MenuinfoFc));
            getMenuinfoFields(env, lpcmi, lpcmi1, &PGLOB(MenuinfoFc));
        }
        rc = (jboolean) (fp)((HMENU)hmenu, lpcmi1);
//        rc = (jboolean) SetMenuInfo((HMENU)hmenu, lpcmi1);
        if (lpcmi) {
            setMenuinfoFields(env, lpcmi, lpcmi1, &PGLOB(MenuinfoFc));
        }
    }
    return rc;
}
#endif

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SetWindowPlacement
 * Signature: (ILorg/eclipse/swt/internal/win32/WINDOWPLACEMENT;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_SetWindowPlacement
  (JNIEnv *env, jclass that, jint hWnd, jobject lpwndpl)
{ 
	DECL_GLOB(pGlob)
    WINDOWPLACEMENT wndpl, *lpwndpl1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SetWindowPlacement\n");
#endif

    if (lpwndpl) {
        lpwndpl1 = &wndpl;
        cacheWindowplacementFids(env, lpwndpl, &PGLOB(WindowplacementFc));
        getWindowplacementFields(env, lpwndpl, lpwndpl1, &PGLOB(WindowplacementFc));
    }
    rc = (jboolean) SetWindowPlacement((HWND)hWnd, lpwndpl1);
    if (lpwndpl) {
        setWindowplacementFields(env, lpwndpl, lpwndpl1, &PGLOB(WindowplacementFc));    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SHBrowseForFolderA
 * Signature: (Lorg/eclipse/swt/internal/win32/BROWSEINFO;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SHBrowseForFolderA
  (JNIEnv *env, jclass that, jobject lpbi)
{
	DECL_GLOB(pGlob)
    BROWSEINFO bi, *lpbi1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SHBrowseForFolderA\n");
#endif

    if (lpbi) {
        lpbi1 = &bi;
        cacheBrowseinfoFids(env, lpbi, &PGLOB(BrowseinfoFc));
        getBrowseinfoFields(env, lpbi, lpbi1, &PGLOB(BrowseinfoFc));
    }
    rc = (jint) SHBrowseForFolderA(lpbi1);
    if (lpbi) {
        setBrowseinfoFields(env, lpbi, lpbi1, &PGLOB(BrowseinfoFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SHBrowseForFolderW
 * Signature: (Lorg/eclipse/swt/internal/win32/BROWSEINFO;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SHBrowseForFolderW
  (JNIEnv *env, jclass that, jobject lpbi)
{
	DECL_GLOB(pGlob)
    BROWSEINFO bi, *lpbi1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SHBrowseForFolderW\n");
#endif

    if (lpbi) {
        lpbi1 = &bi;
        cacheBrowseinfoFids(env, lpbi, &PGLOB(BrowseinfoFc));
        getBrowseinfoFields(env, lpbi, lpbi1, &PGLOB(BrowseinfoFc));
    }
    rc = (jint) SHBrowseForFolderW((LPBROWSEINFOW)lpbi1);
    if (lpbi) {
        setBrowseinfoFields(env, lpbi, lpbi1, &PGLOB(BrowseinfoFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SHGetPathFromIDListW
 * Signature: (I[C)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_SHGetPathFromIDListW
  (JNIEnv *env, jclass that, jint pidl, jcharArray pszPath)
{
    jchar* pszPath1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SHGetPathFromIDListW\n");
#endif

    if (pszPath)
        pszPath1 = (*env)->GetCharArrayElements(env,pszPath, NULL);

    rc = (jboolean)SHGetPathFromIDListW((LPCITEMIDLIST)pidl, (LPWSTR)pszPath1);

    if (pszPath)
        (*env)->ReleaseCharArrayElements(env, pszPath, pszPath1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ShowScrollBar
 * Signature: (IIZ)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_ShowScrollBar
  (JNIEnv *env, jclass that, jint hWnd, jint wBar, jboolean bShow)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "ShowScrollBar\n");
#endif

    return (jboolean) ShowScrollBar((HWND)hWnd, wBar, bShow);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    StartDocA
 * Signature: (ILorg/eclipse/swt/internal/win32/DOCINFO;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_StartDocA
  (JNIEnv *env, jclass that, jint hdc, jobject lpdi)
{
    DECL_GLOB(pGlob)
    DOCINFO di, *lpdi1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "StartDocA\n");
#endif

    if (lpdi) {
        lpdi1 = &di;
        cacheDocinfoFids(env, lpdi, &PGLOB(DocinfoFc));
        getDocinfoFields(env, lpdi, lpdi1, &PGLOB(DocinfoFc));
    }
    rc = (jint) StartDocA((HDC)hdc, lpdi1);
    if (lpdi) {
        setDocinfoFields(env, lpdi, lpdi1, &PGLOB(DocinfoFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    StartDocW
 * Signature: (ILorg/eclipse/swt/internal/win32/DOCINFO;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_StartDocW
  (JNIEnv *env, jclass that, jint hdc, jobject lpdi)
{
    DECL_GLOB(pGlob)
    DOCINFO di, *lpdi1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "StartDocW\n");
#endif

    if (lpdi) {
        lpdi1 = &di;
        cacheDocinfoFids(env, lpdi, &PGLOB(DocinfoFc));
        getDocinfoFields(env, lpdi, lpdi1, &PGLOB(DocinfoFc));
    }
    rc = (jint) StartDocW((HDC)hdc, (LPDOCINFOW)lpdi1);
    if (lpdi) {
        setDocinfoFields(env, lpdi, lpdi1, &PGLOB(DocinfoFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    StartPage
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_StartPage
  (JNIEnv *env, jclass that, jint hdc)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "StartPage\n");
#endif
    return (jint) StartPage((HDC)hdc);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ToAscii
 * Signature: (II[B[SI)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_ToAscii
  (JNIEnv *env, jclass that, jint uVirtKey, jint uScanMode, jbyteArray lpKeyState, jshortArray lpChar, jint uFlags)
{
    PBYTE lpKeyState1=NULL;
    LPWORD lpChar1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "ToAscii\n");
#endif

    if (lpKeyState)
        lpKeyState1 = (*env)->GetByteArrayElements(env, lpKeyState, NULL);
    if (lpChar)
        lpChar1 = (*env)->GetShortArrayElements(env, lpChar, NULL);

    rc = (jint) ToAscii(uVirtKey, uScanMode, lpKeyState1, lpChar1, uFlags);

    if (lpKeyState)
        (*env)->ReleaseByteArrayElements(env, lpKeyState, (jbyte *)lpKeyState1, 0);
    if (lpChar)
        (*env)->ReleaseShortArrayElements(env, lpChar, (jshort *)lpChar1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ToUnicode
 * Signature: 
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_ToUnicode
  (JNIEnv *env, jclass that, jint uVirtKey, jint uScanMode, jbyteArray lpKeyState, jcharArray lpChar, jint cchBuff, jint uFlags)
{
    PBYTE lpKeyState1=NULL;
    LPWSTR lpChar1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "ToUnicode\n");
#endif

    if (lpKeyState)
        lpKeyState1 = (*env)->GetByteArrayElements(env, lpKeyState, NULL);
    if (lpChar)
        lpChar1 = (*env)->GetCharArrayElements(env, lpChar, NULL);

    rc = (jint) ToUnicode(uVirtKey, uScanMode, lpKeyState1, lpChar1, cchBuff, uFlags);

    if (lpKeyState)
        (*env)->ReleaseByteArrayElements(env, lpKeyState, (jbyte *)lpKeyState1, 0);
    if (lpChar)
        (*env)->ReleaseCharArrayElements(env, lpChar, (jshort *)lpChar1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    TrackMouseEvent
 * Signature: (Lorg/eclipse/swt/internal/win32/TRACKMOUSEEVENT;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_TrackMouseEvent
  (JNIEnv *env, jclass that, jobject lpEventTrack)
{
	DECL_GLOB(pGlob)
    TRACKMOUSEEVENT eventTrack, *lpEventTrack1=NULL;
    jboolean rc;

#ifdef DEEBUG_CALL_PRINTS
    fprintf(stderr, "TrackMouseEvent\n");
#endif

    if (lpEventTrack) {
        lpEventTrack1 = &eventTrack;
        cacheTrackmouseeventFids(env, lpEventTrack, &PGLOB(TrackmouseeventFc));
        getTrackmouseeventFields(env, lpEventTrack, lpEventTrack1, &PGLOB(TrackmouseeventFc));
    }
    rc = (jboolean) _TrackMouseEvent(lpEventTrack1);
    if (lpEventTrack) {
        setTrackmouseeventFields(env, lpEventTrack, lpEventTrack1, &PGLOB(TrackmouseeventFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    VkKeyScanA
 * Signature: (S)S
 */
JNIEXPORT jshort JNICALL Java_org_eclipse_swt_internal_win32_OS_VkKeyScanA
  (JNIEnv *env, jclass that, jshort ch)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "VkKeyScanA\n");
#endif

    return (jshort) VkKeyScanA((TCHAR)ch);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    VkKeyScanW
 * Signature: (S)S
 */
JNIEXPORT jshort JNICALL Java_org_eclipse_swt_internal_win32_OS_VkKeyScanW
  (JNIEnv *env, jclass that, jshort ch)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "VkKeyScanW\n");
#endif

    return (jshort) VkKeyScanW((WCHAR)ch);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    WaitMessage
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_WaitMessage
  (JNIEnv *env, jclass that)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "WaitMessage\n");
#endif

    return (jboolean) WaitMessage();
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    WindowFromDC
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_WindowFromDC
  (JNIEnv *env, jclass that, jint hdc)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "WindowFromDC\n");
#endif

    return (jint) WindowFromDC((HDC)hdc);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    PrintDlgA
 * Signature: (Lorg/eclipse/swt/internal/win32/PRINTDLG;)Z
 */

JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_PrintDlgA
  (JNIEnv *env, jclass that, jobject lppd)
{
	DECL_GLOB(pGlob)
    PRINTDLG printdlg, *lppd1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "PrintDlgA\n");
#endif

    if (lppd) {
        lppd1 = &printdlg;
        cachePrintdlgFids(env, lppd, &PGLOB(PrintdlgFc));
        getPrintdlgFields(env, lppd, lppd1, &PGLOB(PrintdlgFc));
    }
    rc = (jboolean) PrintDlgA(lppd1);
    if (lppd) {
        setPrintdlgFields(env, lppd, lppd1, &PGLOB(PrintdlgFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    PrintDlgW
 * Signature: (Lorg/eclipse/swt/internal/win32/PRINTDLG;)Z
 */

JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_PrintDlgW
  (JNIEnv *env, jclass that, jobject lppd)
{
	DECL_GLOB(pGlob)
    PRINTDLG printdlg, *lppd1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "PrintDlgW\n");
#endif

    if (lppd) {
        lppd1 = &printdlg;
        cachePrintdlgFids(env, lppd, &PGLOB(PrintdlgFc));
        getPrintdlgFields(env, lppd, lppd1, &PGLOB(PrintdlgFc));
    }
    rc = (jboolean) PrintDlgW((LPPRINTDLGW)lppd1);
    if (lppd) {
        setPrintdlgFields(env, lppd, lppd1, &PGLOB(PrintdlgFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    PageSetupDlg
 * Signature: (Lorg/eclipse/swt/internal/win32/PAGESETUPDLG;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_PageSetupDlg
  (JNIEnv *env, jclass that, jobject lppsd)
{
	DECL_GLOB(pGlob)
    PAGESETUPDLG pagesetupdlg, *lppsd1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "PageSetupDlg\n");
#endif

    if (lppsd) {
        lppsd1 = &pagesetupdlg;
        cachePagesetupdlgFids(env, lppsd, &PGLOB(PagesetupdlgFc));
        getPagesetupdlgFields(env, lppsd, lppsd1, &PGLOB(PagesetupdlgFc));
    }
    rc = (jboolean) PageSetupDlg(lppsd1);
    if (lppsd) {
        setPagesetupdlgFields(env, lppsd, lppsd1, &PGLOB(PagesetupdlgFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    DrawStateA
 * Signature: (IIIIIIIIII)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_DrawStateA
  (JNIEnv *env, jclass that, jint hdc, jint hbr, jint lpOutputFunc, jint lData, jint wData, jint x, jint y, jint cx, jint cy, jint fuFlags)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "DrawStateA");
#endif
	return (jboolean) DrawStateA ((HDC)hdc, (HBRUSH)hbr, (DRAWSTATEPROC) lpOutputFunc, (LPARAM)lData, (WPARAM) wData, x, y, cx, cy, fuFlags);

}
    
/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    DrawStateW
 * Signature: (IIIIIIIIII)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_DrawStateW
  (JNIEnv *env, jclass that, jint hdc, jint hbr, jint lpOutputFunc, jint lData, jint wData, jint x, jint y, jint cx, jint cy, jint fuFlags)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "DrawStateW");
#endif
	return (jboolean) DrawStateW ((HDC)hdc, (HBRUSH)hbr, (DRAWSTATEPROC) lpOutputFunc, (LPARAM)lData, (WPARAM) wData, x, y, cx, cy, fuFlags);

}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SetStretchBltMode
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SetStretchBltMode
  (JNIEnv *env, jclass that, jint hdc, jint iStretchMode)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SetStretchBltMode\n");
#endif

    return (jint) SetStretchBltMode((HDC)hdc, iStretchMode);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SetWindowsHookExA
 * Signature: (IIII)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SetWindowsHookExA
  (JNIEnv *env, jclass that, jint idHook, jint lpfn, jint hMod,  jint dwThreadId)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SetWindowsHookExA\n");
#endif
    return (jint) SetWindowsHookExA(idHook, (HOOKPROC)lpfn, (HINSTANCE)hMod, dwThreadId);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SetWindowsHookExW
 * Signature: (IIII)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SetWindowsHookExW
  (JNIEnv *env, jclass that, jint idHook, jint lpfn, jint hMod,  jint dwThreadId)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SetWindowsHookExW\n");
#endif
    return (jint) SetWindowsHookExW(idHook, (HOOKPROC)lpfn, (HINSTANCE)hMod, dwThreadId);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    UnhookWindowsHookEx
 * Signature: (I)I
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_UnhookWindowsHookEx
  (JNIEnv *env, jclass that, jint hhk)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "UnhookWindowsHookEx\n");
#endif

    return (jboolean) UnhookWindowsHookEx((HHOOK)hhk);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    CallNextHookEx
 * Signature: (IIII)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_CallNextHookEx
  (JNIEnv *env, jclass that, jint hhk, jint nCode,  jint wParam,  jint lParam)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "CallNextHookEx\n");
#endif

    return (jint) CallNextHookEx((HHOOK)hhk, nCode, (WPARAM)wParam, (LPARAM)lParam);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetCharacterPlacementA
 * Signature: 
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetCharacterPlacementA
  (JNIEnv *env, jclass that, jint hdc, jbyteArray lpString, jint nCount, jint nMaxExtent, jobject lpResults, jint dwFlags)
{
	DECL_GLOB(pGlob)
    GCP_RESULTS results, *lpResults1=NULL;
    jbyte* lpString1=NULL;
    jint rc;
    
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetCharacterPlacementA\n");
#endif

    if (lpString)
        lpString1 = (*env)->GetByteArrayElements(env, lpString, NULL);
    if (lpResults) {
        lpResults1 = &results;
        cacheGCP_RESULTSFids(env, lpResults, &PGLOB(GCP_RESULTSFc));
        getGCP_RESULTSFields(env, lpResults, lpResults1, &PGLOB(GCP_RESULTSFc));
    }
    
    rc = (jint) GetCharacterPlacementA((HDC)hdc, (LPSTR)lpString1, nCount, nMaxExtent, lpResults1, dwFlags);
    
    if (lpString)
        (*env)->ReleaseByteArrayElements(env, lpString, lpString1, 0);
    if (lpResults) {
        setGCP_RESULTSFields(env, lpResults, lpResults1, &PGLOB(GCP_RESULTSFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetCharacterPlacementW
 * Signature: 
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetCharacterPlacementW
  (JNIEnv *env, jclass that, jint hdc, jcharArray lpString, jint nCount, jint nMaxExtent, jobject lpResults, jint dwFlags)
{
	DECL_GLOB(pGlob)
    GCP_RESULTS results, *lpResults1=NULL;
    jchar* lpString1=NULL;
    jint rc;
    
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetCharacterPlacementW\n");
#endif

    if (lpString)
        lpString1 = (*env)->GetCharArrayElements(env, lpString, NULL);
    if (lpResults) {
        lpResults1 = &results;
        cacheGCP_RESULTSFids(env, lpResults, &PGLOB(GCP_RESULTSFc));
        getGCP_RESULTSFields(env, lpResults, lpResults1, &PGLOB(GCP_RESULTSFc));
    }
    
    rc = (jint) GetCharacterPlacementW((HDC)hdc, (LPWSTR)lpString1, nCount, nMaxExtent, (LPGCP_RESULTSW)lpResults1, dwFlags);
    
    if (lpString)
        (*env)->ReleaseCharArrayElements(env, lpString, lpString1, 0);
    if (lpResults) {
        setGCP_RESULTSFields(env, lpResults, lpResults1, &PGLOB(GCP_RESULTSFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetFontLanguageInfo
 * Signature: 
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetFontLanguageInfo
  (JNIEnv *env, jclass that, jint hdc)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetFontLanguageInfo\n");
#endif

    return (jint) GetFontLanguageInfo((HDC)hdc);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetKeyboardLayoutList
 * Signature: 
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetKeyboardLayoutList
  (JNIEnv *env, jclass that, jint nBuff, jintArray lpList)
{
	HKL FAR *lpList1;
    jint rc;
    
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetKeyboardLayoutList\n");
#endif

    if (lpList)
        lpList1 = (HKL FAR *)(*env)->GetIntArrayElements(env, lpList, NULL);

    rc = (jint) GetKeyboardLayoutList(nBuff, lpList1);
    
    if (lpList)
        (*env)->ReleaseIntArrayElements(env, lpList, (jint *)lpList1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetKeyboardLayout
 * Signature: 
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetKeyboardLayout
  (JNIEnv *env, jclass that, jint idThread)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetKeyboardLayout\n");
#endif

    return (jint) GetKeyboardLayout(idThread);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ActivateKeyboardLayout
 * Signature: 
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_ActivateKeyboardLayout
  (JNIEnv *env, jclass that, jint hkl, jint Flags)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "ActivateKeyboardLayout\n");
#endif

    return (jint) ActivateKeyboardLayout((HKL)hkl, Flags);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SetTextAlign
 * Signature: 
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SetTextAlign
  (JNIEnv *env, jclass that, jint hdc, jint fMode)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SetTextAlign\n");
#endif

    return (jint) SetTextAlign((HDC)hdc, fMode);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetTextCharset
 * Signature: 
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetTextCharset
  (JNIEnv *env, jclass that, jint hdc)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetTextCharset\n");
#endif

    return (jint) GetTextCharset((HDC)hdc);
}

#endif // _WIN32_WCE

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    Call
 * Signature: (ILorg/eclipse/swt/internal/win32/DLLVERSIONINFO;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_Call
  (JNIEnv *env, jclass that, jint address, jobject arg0)
{
	DECL_GLOB(pGlob)
    DLLVERSIONINFO dllversioninfo, *arg01=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "Call\n");
#endif

    if (arg0) {
        arg01 = &dllversioninfo;
        cacheDllversioninfoFids(env, arg0, &PGLOB(DllversioninfoFc));
        getDllversioninfoFields(env, arg0, arg01, &PGLOB(DllversioninfoFc));
    }
    rc = ((DLLGETVERSIONPROC)address)(arg01);

    if (arg0) {
        setDllversioninfoFields(env, arg0, arg01, &PGLOB(DllversioninfoFc));
    }
    return rc;
}

JNIEXPORT int JNICALL Java_org_eclipse_swt_internal_win32_OS_getSharedLibraryMajorVersionNumber
  (JNIEnv *env, jclass that)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "getSharedLibraryMajorVersionNumber\n");
#endif
    return SWT_LIBRARY_MAJOR_VERSION;
}

JNIEXPORT int JNICALL Java_org_eclipse_swt_internal_win32_OS_getSharedLibraryMinorVersionNumber
  (JNIEnv *env, jclass that)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "getSharedLibraryMinorVersionNumber\n");
#endif
    return SWT_LIBRARY_MINOR_VERSION;
}

JNIEXPORT int JNICALL Java_org_eclipse_swt_internal_win32_OS_getSharedLibraryBuildNumber
  (JNIEnv *env, jclass that)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "getSharedLibraryBuildNumber\n");
#endif
    return SWT_LIBRARY_BUILD_NUM;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    AdjustWindowRectEx
 * Signature: (Lorg/eclipse/swt/internal/win32/RECT;IZI)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_AdjustWindowRectEx
  (JNIEnv *env, jclass that, jobject lpRect, jint dwStyle, jboolean bMenu, jint dwExStyle)
{
	DECL_GLOB(pGlob)
    RECT rect, *lpRect1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "AdjustWindowRectEx\n");
#endif

    if (lpRect) {
        lpRect1 = &rect;

        cacheRectFids(env, lpRect, &PGLOB(RectFc));
        getRectFields(env, lpRect, lpRect1, &PGLOB(RectFc));
    }
    rc = (jboolean) AdjustWindowRectEx(lpRect1, dwStyle, bMenu, dwExStyle);
    if (lpRect) {
        setRectFields(env, lpRect, lpRect1, &PGLOB(RectFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    BitBlt
 * Signature: (IIIIIIIII)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_BitBlt
  (JNIEnv *env, jclass that, jint hdcDest, jint nXDest, jint nYDest, jint nWidth, jint nHeight, jint hdcSrc, jint nXSrc, jint nYSrc, jint dwRop)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "BitBlt\n");
#endif

    return (jboolean) BitBlt((HDC)hdcDest, nXDest, nYDest, nWidth, nHeight, (HDC)hdcSrc, nXSrc, nYSrc, dwRop);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    BeginDeferWindowPos
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_BeginDeferWindowPos
  (JNIEnv *env, jclass that, jint numWindows)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "BeginDeferWindowPos\n");
#endif

    return (jint) BeginDeferWindowPos(numWindows);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    BeginPaint
 * Signature: (ILorg/eclipse/swt/internal/win32/PAINTSTRUCT;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_BeginPaint
  (JNIEnv *env, jclass that, jint hwnd, jobject lpPaint)
{
	DECL_GLOB(pGlob)
    PAINTSTRUCT paint, *lpPaint1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "BeginPaint\n");
#endif

    lpPaint1 = &paint;
    rc = (jint) BeginPaint((HWND)hwnd, lpPaint1);

    if (lpPaint) {
        cachePaintstructFids(env, lpPaint, &PGLOB(PaintstructFc));
        setPaintstructFields(env, lpPaint, lpPaint1, &PGLOB(PaintstructFc));
        /* we do not touch rgbReserved byte array of the PAINTSTRUCT */
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    BringWindowToTop
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_BringWindowToTop
  (JNIEnv *env, jclass that, jint hwnd)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "BringWindowToTop\n");
#endif

    return (jboolean) BringWindowToTop((HWND)hwnd);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    CallWindowProcA
 * Signature: (IIIII)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_CallWindowProcA
  (JNIEnv *env, jclass that,jint lpPrevWndFunc, jint hWnd, jint Msg, jint wParam, jint lParam)
{
    
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "CallWindowProcA\n");
#endif
    
    return (jint) CallWindowProcA((WNDPROC)lpPrevWndFunc,(HWND)hWnd, Msg, wParam, lParam);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    CallWindowProcW
 * Signature: (IIIII)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_CallWindowProcW
  (JNIEnv *env, jclass that,jint lpPrevWndFunc, jint hWnd, jint Msg, jint wParam, jint lParam)
{
    
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "CallWindowProcW\n");
#endif
    
    return (jint) CallWindowProcW((WNDPROC)lpPrevWndFunc,(HWND)hWnd, Msg, wParam, lParam);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    CharLowerA
 * Signature: (S)S
 */
JNIEXPORT jshort JNICALL Java_org_eclipse_swt_internal_win32_OS_CharLowerA
  (JNIEnv *env, jclass that, jshort lpsz)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "CharLowerA\n");
#endif

    return (jshort) CharLowerA((LPSTR) lpsz);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    CharLowerW
 * Signature: (S)S
 */
JNIEXPORT jshort JNICALL Java_org_eclipse_swt_internal_win32_OS_CharLowerW
  (JNIEnv *env, jclass that, jshort lpsz)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "CharLowerW\n");
#endif

    return (jshort) CharLowerW((LPWSTR) lpsz);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    CharUpperA
 * Signature: (S)S
 */
JNIEXPORT jshort JNICALL Java_org_eclipse_swt_internal_win32_OS_CharUpperA
  (JNIEnv *env, jclass that, jshort lpsz)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "CharUpperA\n");
#endif

    return (jshort) CharUpperA((LPSTR) lpsz);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    CharUpperW
 * Signature: (S)S
 */
JNIEXPORT jshort JNICALL Java_org_eclipse_swt_internal_win32_OS_CharUpperW
  (JNIEnv *env, jclass that, jshort lpsz)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "CharUpperW\n");
#endif

    return (jshort) CharUpperW((LPWSTR) lpsz);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ChooseColorA
 * Signature: (Lorg/eclipse/swt/internal/win32/CHOOSECOLOR;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_ChooseColorA
  (JNIEnv *env, jclass that, jobject lpcc)
{
	DECL_GLOB(pGlob)
    CHOOSECOLOR choosecolor, *lpcc1=NULL;
    jboolean rc;
    
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "ChooseColorA\n");
#endif

    if (lpcc) {
        lpcc1 = &choosecolor;
        cacheChoosecolorFids(env, lpcc, &PGLOB(ChoosecolorFc));
        getChoosecolorFields(env, lpcc, lpcc1, &PGLOB(ChoosecolorFc));
    }
    rc = (jboolean) ChooseColorA(lpcc1);
    if (lpcc) {
        setChoosecolorFields(env, lpcc, lpcc1, &PGLOB(ChoosecolorFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ChooseColorW
 * Signature: (Lorg/eclipse/swt/internal/win32/CHOOSECOLOR;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_ChooseColorW
  (JNIEnv *env, jclass that, jobject lpcc)
{
	DECL_GLOB(pGlob)
    CHOOSECOLOR choosecolor, *lpcc1=NULL;
    jboolean rc;
    
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "ChooseColorW\n");
#endif

    if (lpcc) {
        lpcc1 = &choosecolor;
        cacheChoosecolorFids(env, lpcc, &PGLOB(ChoosecolorFc));
        getChoosecolorFields(env, lpcc, lpcc1, &PGLOB(ChoosecolorFc));
    }
    rc = (jboolean) ChooseColorW ((LPCHOOSECOLORW)lpcc1);
    if (lpcc) {
        setChoosecolorFields(env, lpcc, lpcc1, &PGLOB(ChoosecolorFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ClientToScreen
 * Signature: (ILorg/eclipse/swt/internal/win32/POINT;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_ClientToScreen
  (JNIEnv *env, jclass that, jint hWnd, jobject lpPoint)
{
	DECL_GLOB(pGlob)
    POINT point, *lpPoint1=NULL;
    jboolean rc;
    
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "ClientToScreen\n");
#endif

    if (lpPoint) {
        lpPoint1 = &point;
        cachePointFids(env, lpPoint, &PGLOB(PointFc));
        getPointFields(env, lpPoint, lpPoint1, &PGLOB(PointFc));
    }
    rc = (jboolean) ClientToScreen((HWND)hWnd, lpPoint1);
    if (lpPoint) {
        setPointFields(env, lpPoint, lpPoint1, &PGLOB(PointFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    CloseClipboard
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_CloseClipboard
  (JNIEnv *env,  jclass that)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "CloseClipboard\n");
#endif
    return (jboolean) CloseClipboard();
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    CombineRgn
 * Signature: (IIII)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_CombineRgn
  (JNIEnv *env, jclass that, jint hrgnDest, jint hrgnSrc1, jint hrgnSrc2, jint fnCombineMode)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "CombineRgn\n");
#endif

    return (jint) CombineRgn( (HRGN)hrgnDest, (HRGN)hrgnSrc1, (HRGN)hrgnSrc2, fnCombineMode);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    CommDlgExtendedError
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_CommDlgExtendedError
  (JNIEnv *env, jclass that)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "CommDlgExtendedError\n");
#endif

    return (jint) CommDlgExtendedError();
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    CreateAcceleratorTableA
 * Signature: ([BI)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_CreateAcceleratorTableA
  (JNIEnv *env, jclass that, jbyteArray lpAccel, jint cEntries)
{
    LPACCEL lpAccel1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "CreateAcceleratorTableA\n");
#endif

    if (lpAccel)
        lpAccel1 = (LPACCEL)(*env)->GetByteArrayElements(env, lpAccel, NULL);

    rc = (jint)CreateAcceleratorTableA(lpAccel1, cEntries);

    if (lpAccel)
        (*env)->ReleaseByteArrayElements(env, lpAccel, (jbyte *)lpAccel1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    CreateAcceleratorTableW
 * Signature: ([BI)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_CreateAcceleratorTableW
  (JNIEnv *env, jclass that, jbyteArray lpAccel, jint cEntries)
{
    LPACCEL lpAccel1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "CreateAcceleratorTableW\n");
#endif

    if (lpAccel)
        lpAccel1 = (LPACCEL)(*env)->GetByteArrayElements(env, lpAccel, NULL);

    rc = (jint)CreateAcceleratorTableW(lpAccel1, cEntries);

    if (lpAccel)
        (*env)->ReleaseByteArrayElements(env, lpAccel, (jbyte *)lpAccel1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    CreateBitmap
 * Signature: (IIII[B)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_CreateBitmap
  (JNIEnv *env, jclass that, jint nWidth, jint nHeight, jint cPlanes, jint cBitsPerPel, jbyteArray lpvBits)
{
    LPVOID lpvBits1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "CreateBitmap\n");
#endif

    if (lpvBits)
        lpvBits1 = (LPVOID)(*env)->GetByteArrayElements(env, lpvBits, NULL);

    rc = (jint)CreateBitmap(nWidth, nHeight, cPlanes, cBitsPerPel, (CONST VOID *)lpvBits1);

    if (lpvBits)
        (*env)->ReleaseByteArrayElements(env, lpvBits, (jbyte *)lpvBits1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    CreateCompatibleBitmap
 * Signature: (III)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_CreateCompatibleBitmap
  (JNIEnv *env, jclass that, jint hdc, jint nWidth, jint nHeight)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "CreateCompatibleBitmap\n");
#endif

    return (jint) CreateCompatibleBitmap((HDC)hdc, nWidth, nHeight);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    CreateCaret
 * Signature: (IIII)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_CreateCaret
  (JNIEnv *env, jclass that, jint hWnd, jint hBitMap, jint nWidth, jint nHeight)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "CreateCaret\n");
#endif

    return (jboolean) CreateCaret( (HWND) hWnd, (HBITMAP)hBitMap, nWidth, nHeight);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    CreateCompatibleDC
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_CreateCompatibleDC
  (JNIEnv *env, jclass that, jint hdc)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "CreateCompatibleDC\n");
#endif

    return (jint) CreateCompatibleDC((HDC) hdc);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    CreateDC
 * Signature: ([B[BII)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_CreateDCA
  (JNIEnv *env, jclass that, jbyteArray lpszDriver, jbyteArray lpszDevice, jint lpszOutput, jint lpInitData)
{
    jbyte* lpszDriver1=NULL;
	jbyte* lpszDevice1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "CreateDCA\n");
#endif

    if (lpszDriver)
        lpszDriver1 = (*env)->GetByteArrayElements(env,lpszDriver, NULL);

    if (lpszDevice)
        lpszDevice1 = (*env)->GetByteArrayElements(env,lpszDevice, NULL);

    rc = (jint)CreateDCA((LPSTR)lpszDriver1, (LPSTR)lpszDevice1, (LPSTR)lpszOutput, (CONST DEVMODE *)lpInitData);

    if (lpszDriver)
        (*env)->ReleaseByteArrayElements(env, lpszDriver, lpszDriver1, 0);

    if (lpszDevice)
        (*env)->ReleaseByteArrayElements(env, lpszDevice, lpszDevice1, 0);

    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    CreateDCW
 * Signature: ([C[CII)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_CreateDCW
  (JNIEnv *env, jclass that, jcharArray lpszDriver, jcharArray lpszDevice, jint lpszOutput, jint lpInitData)
{
    jchar* lpszDriver1=NULL;
	jchar* lpszDevice1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "CreateDCW\n");
#endif

    if (lpszDriver)
        lpszDriver1 = (*env)->GetCharArrayElements(env,lpszDriver, NULL);

    if (lpszDevice)
        lpszDevice1 = (*env)->GetCharArrayElements(env,lpszDevice, NULL);

    rc = (jint)CreateDCW((LPWSTR)lpszDriver1, (LPWSTR)lpszDevice1, (LPWSTR)lpszOutput, (CONST DEVMODEW *)lpInitData);

    if (lpszDriver)
        (*env)->ReleaseCharArrayElements(env, lpszDriver, lpszDriver1, 0);

    if (lpszDevice)
        (*env)->ReleaseCharArrayElements(env, lpszDevice, lpszDevice1, 0);

    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    CreateFontIndirectA
 * Signature: (Lorg/eclipse/swt/internal/win32/LOGFONT;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_CreateFontIndirectA__Lorg_eclipse_swt_internal_win32_LOGFONT_2
  (JNIEnv *env, jclass that, jobject lpLogFont)
{
	DECL_GLOB(pGlob)
    LOGFONTA logfont, *lpLogFont1=NULL;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "CreateFontIndirectA__Lorg_eclipse_swt_internal_win32_LOGFONT_2\n");
#endif

    if (lpLogFont) {
        lpLogFont1 = &logfont;
        cacheLogfontFids(env, lpLogFont, &PGLOB(LogfontFc));
        getLogfontFieldsA(env, lpLogFont, lpLogFont1, &PGLOB(LogfontFc));
    }
    return (jint) CreateFontIndirectA(lpLogFont1);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    CreateFontIndirectW
 * Signature: (Lorg/eclipse/swt/internal/win32/LOGFONT;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_CreateFontIndirectW__Lorg_eclipse_swt_internal_win32_LOGFONT_2
  (JNIEnv *env, jclass that, jobject lpLogFont)
{
	DECL_GLOB(pGlob)
    LOGFONTW logfont, *lpLogFont1=NULL;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "CreateFontIndirectW__Lorg_eclipse_swt_internal_win32_LOGFONT_2\n");
#endif

    if (lpLogFont) {
        lpLogFont1 = &logfont;
        cacheLogfontFids(env, lpLogFont, &PGLOB(LogfontFc));
        getLogfontFieldsW(env, lpLogFont, lpLogFont1, &PGLOB(LogfontFc));
    }
    return (jint) CreateFontIndirectW(lpLogFont1);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    CreateDIBSection
 * Signature: (I[BI[III)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_CreateDIBSection
  (JNIEnv *env, jclass that, jint hdc, jbyteArray pbmi, jint iUsage, jintArray ppvBits, jint hSection, jint dwOffset)
{
    BITMAPINFO *pbmi1=NULL;
    PVOID *ppvBits1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "CreateDIBSection\n");
#endif

    if (pbmi)
        pbmi1 = (BITMAPINFO *)(*env)->GetByteArrayElements(env,pbmi, NULL);

    if (ppvBits)
        ppvBits1 = (PVOID *)(*env)->GetIntArrayElements(env, ppvBits, NULL);


    rc = (jint)CreateDIBSection((HDC)hdc, pbmi1, iUsage, ppvBits1, (HANDLE)hSection, dwOffset);

    if (pbmi)
        (*env)->ReleaseByteArrayElements(env, pbmi, (jbyte *)pbmi1, 0);

    if (ppvBits)
        (*env)->ReleaseIntArrayElements(env, ppvBits, (jint *)ppvBits1, 0);

    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    CreateFontIndirectA
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_CreateFontIndirectA__I
  (JNIEnv *env, jclass that, jint lplf)
{

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "CreateFontIndirectA__I\n");
#endif
    return (jint) CreateFontIndirectA((LPLOGFONTA)lplf);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    CreateFontIndirectW
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_CreateFontIndirectW__I
  (JNIEnv *env, jclass that, jint lplf)
{

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "CreateFontIndirectW__I\n");
#endif
    return (jint) CreateFontIndirectW((LPLOGFONTW)lplf);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    CreateIconIndirect
 * Signature: (Lorg/eclipse/swt/internal/win32/ICONINFO;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_CreateIconIndirect
  (JNIEnv *env, jclass that, jobject lplf)
{
	DECL_GLOB(pGlob)
    ICONINFO iconinfo, *lplf1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "CreateIconIndirect\n");
#endif

    if (lplf) {
        lplf1 = &iconinfo;
        cacheIconinfoFids(env, lplf, &PGLOB(IconinfoFc));
        getIconinfoFields(env, lplf, lplf1, &PGLOB(IconinfoFc));
    }
    rc = (jint) CreateIconIndirect(lplf1);
    if (lplf) {
        setIconinfoFields(env, lplf, lplf1, &PGLOB(IconinfoFc));
    }
    return rc;

}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    CreateMenu
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_CreateMenu
  (JNIEnv *env, jclass that)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "CreateMenu\n");
#endif

    return (jint) CreateMenu();
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    CreatePalette
 * Signature: ([B)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_CreatePalette
  (JNIEnv *env, jclass that, jbyteArray logPalette)
{
    jbyte *logPalette1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "CreatePalette\n");
#endif

    if (logPalette)
        logPalette1 = (*env)->GetByteArrayElements(env, logPalette, NULL);

    rc = (jint) CreatePalette( (LOGPALETTE *) logPalette1);

    if (logPalette)
        (*env)->ReleaseByteArrayElements(env, logPalette, (jbyte *)logPalette1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    CreatePatternBrush
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_CreatePatternBrush
  (JNIEnv *env, jclass that, jint colorRef)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "CreatePatternBrush\n");
#endif

    return (jint) CreatePatternBrush((HBITMAP)colorRef);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    CreatePen
 * Signature: (III)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_CreatePen
  (JNIEnv *env, jclass that, jint fnPenStyle, jint nWidth, jint crColor)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "CreatePen\n");
#endif

    return (jint) CreatePen(fnPenStyle, nWidth, (COLORREF)crColor);
}
  
/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ExtCreatePen
 * Signature: (IILorg/eclipse/swt/internal/win32/LOGBRUSH;II)I
 */
/*
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_ExtCreatePen
  (JNIEnv *env, jclass that, jint dwPenStyle, jint dwWidth, jobject lplb, int dwStyleCount, int lpStyle)
{
    DECL_GLOB(pGlob)
    LOGBRUSH logbrush, *lplb1=NULL;
    jint rc;
    
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "ExtCreatePen\n");
#endif

	if (lplb) {
        lplb1 = &logbrush;
        cacheLogbrushFids(env, lplb, &PGLOB(LogbrushFc));
        getLogbrushFields(env, lplb, lplb1, &PGLOB(LogbrushFc));
    }
    rc = (jint) ExtCreatePen(dwPenStyle, dwWidth, (CONST LOGBRUSH *)lplb1, dwStyleCount, (CONST DWORD *)lpStyle);
    
    if (lplb) {
        setLogbrushFields(env, lplb, lplb1, &PGLOB(LogbrushFc));
    }
    return rc;
}
*/

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    CreatePopupMenu
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_CreatePopupMenu
  (JNIEnv *env, jclass that)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "CreatePopupMenu\n");
#endif

    return (jint) CreatePopupMenu();
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    
 * Signature: (IIII)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_CreateRectRgn
  (JNIEnv *env, jclass that, jint nLeftRect, jint nTopRect, jint nRightRect, jint nBottomRect)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "CreateRectRgn\n");
#endif

    return (jint) CreateRectRgn(nLeftRect, nTopRect, nRightRect, nBottomRect);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    CreateSolidBrush
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_CreateSolidBrush
  (JNIEnv *env, jclass that, jint crColor)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "\n");
#endif

    return (jint) CreateSolidBrush((COLORREF)crColor) ;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    CreateWindowExA
 * Signature: (I[B[BIIIIIIIILorg/eclipse/swt/internal/win32/CREATESTRUCT;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_CreateWindowExA
  (JNIEnv *env, jclass that, jint dwExStyle, jbyteArray buff1, jbyteArray buff2,
                             jint dwStyle, jint X, jint Y, jint nWidth, jint nHeight,
                             jint hWndParent, jint hMenu, jint hInstance, jobject lpParam)
{
	DECL_GLOB(pGlob)
    jbyte *lpClassName=NULL, *lpWindowName=NULL;
    CREATESTRUCT param, *lpParam1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "CreateWindowExA\n");
#endif

    if (lpParam) {
        lpParam1 = &param;
        cacheCreatestructFids(env, lpParam, &PGLOB(CreatestructFc));
        getCreatestructFields(env, lpParam, lpParam1, &PGLOB(CreatestructFc));
    }
    if (buff1)
        lpClassName = (*env)->GetByteArrayElements(env, buff1, NULL);
    if (buff2)
        lpWindowName = (*env)->GetByteArrayElements(env, buff2, NULL);

    rc = (jint) CreateWindowExA (dwExStyle, (LPSTR)lpClassName, (LPSTR)lpWindowName, dwStyle, X, Y, nWidth, nHeight,
                                     (HWND)hWndParent, (HMENU)hMenu, (HINSTANCE) hInstance, lpParam1);

    if (buff1)
        (*env)->ReleaseByteArrayElements(env, buff1, lpClassName, 0);
    if (buff2)
        (*env)->ReleaseByteArrayElements(env, buff2, lpWindowName, 0);

    if (lpParam) {
        setCreatestructFields(env, lpParam, lpParam1, &PGLOB(CreatestructFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    CreateWindowExW
 * Signature: (I[B[BIIIIIIIILorg/eclipse/swt/internal/win32/CREATESTRUCT;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_CreateWindowExW
  (JNIEnv *env, jclass that, jint dwExStyle, jbyteArray buff1, jbyteArray buff2,
                             jint dwStyle, jint X, jint Y, jint nWidth, jint nHeight,
                             jint hWndParent, jint hMenu, jint hInstance, jobject lpParam)
{
	DECL_GLOB(pGlob)
    jchar *lpClassName=NULL, *lpWindowName=NULL;
    CREATESTRUCT param, *lpParam1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "CreateWindowExW\n");
#endif

    if (lpParam) {
        lpParam1 = &param;
        cacheCreatestructFids(env, lpParam, &PGLOB(CreatestructFc));
        getCreatestructFields(env, lpParam, lpParam1, &PGLOB(CreatestructFc));
    }
    if (buff1)
        lpClassName = (*env)->GetCharArrayElements(env, buff1, NULL);
    if (buff2)
        lpWindowName = (*env)->GetCharArrayElements(env, buff2, NULL);

    rc = (jint) CreateWindowExW (dwExStyle, (LPWSTR)lpClassName, (LPWSTR)lpWindowName, dwStyle, X, Y, nWidth, nHeight,
                                     (HWND)hWndParent, (HMENU)hMenu, (HINSTANCE) hInstance, lpParam1);

    if (buff1)
        (*env)->ReleaseCharArrayElements(env, buff1, lpClassName, 0);
    if (buff2)
        (*env)->ReleaseCharArrayElements(env, buff2, lpWindowName, 0);

    if (lpParam) {
        setCreatestructFields(env, lpParam, lpParam1, &PGLOB(CreatestructFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    DeferWindowPos
 * Signature: (IIIIIIII)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_DeferWindowPos
  (JNIEnv *env, jclass that, jint hWinPosInfo, jint hWnd, jint hWndInsertAfter, jint x, jint y, jint cx, jint cy, jint uFlags)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "DeferWindowPos\n");
#endif

    return (jint) DeferWindowPos((HDWP)hWinPosInfo, (HWND)hWnd, (HWND)hWndInsertAfter, x, y, cx, cy, uFlags);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    DefWindowProcA
 * Signature: (IIII)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_DefWindowProcA
  (JNIEnv *env, jclass that, jint hWnd, jint Msg, jint wParam, jint lParam)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "DefWindowProcA\n");
#endif

    return (jint) DefWindowProcA((HWND)hWnd, Msg, (WPARAM)wParam, (LPARAM)lParam);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    DefWindowProcW
 * Signature: (IIII)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_DefWindowProcW
  (JNIEnv *env, jclass that, jint hWnd, jint Msg, jint wParam, jint lParam)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "DefWindowProcW\n");
#endif

    return (jint) DefWindowProcW((HWND)hWnd, Msg, (WPARAM)wParam, (LPARAM)lParam);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    DeleteDC
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_DeleteDC
  (JNIEnv *env, jclass that, jint hdc)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "DeleteDC\n");
#endif

    return (jboolean) DeleteDC((HDC)hdc);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    DeleteMenu
 * Signature: (III)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_DeleteMenu
  (JNIEnv *env, jclass that, jint hMenu, jint uPosition, jint uFlags)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "DeleteMenu\n");
#endif

    return (jboolean) DeleteMenu((HMENU)hMenu, uPosition, uFlags);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    DeleteObject
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_DeleteObject
  (JNIEnv *env, jclass that, jint hObject)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "DeleteObject\n");
#endif

    return (jboolean) DeleteObject((HGDIOBJ)hObject);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    DestroyAcceleratorTable
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_DestroyAcceleratorTable
  (JNIEnv *env, jclass that, jint hAccel)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "DestroyAcceleratorTable\n");
#endif

    return (jboolean) DestroyAcceleratorTable((HACCEL) hAccel);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    DestroyCaret
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_DestroyCaret
  (JNIEnv *env, jclass that)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "DestroyCaret\n");
#endif

    return (jboolean) DestroyCaret();
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    DestroyIcon
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_DestroyIcon
  (JNIEnv *env, jclass that, jint hIcon)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "DestroyIcon\n");
#endif

    return (jboolean) DestroyIcon((HICON)hIcon);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    DestroyMenu
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_DestroyMenu
  (JNIEnv *env, jclass that, jint hMenu)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "DestroyMenu\n");
#endif

    return (jboolean) DestroyMenu((HMENU) hMenu);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    DestroyWindow
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_DestroyWindow
  (JNIEnv *env, jclass that, jint hWnd)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "DestroyWindow\n");
#endif

    return (jboolean) DestroyWindow((HWND) hWnd);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    DispatchMessageA
 * Signature: (Lorg/eclipse/swt/internal/win32/MSG;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_DispatchMessageA
  (JNIEnv *env, jclass that, jobject lpMsg)
{
	DECL_GLOB(pGlob)
    MSG callBack, *lpMsg1 = NULL;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "DispatchMessageA\n");
#endif

    if (lpMsg) {
        lpMsg1 = &callBack;
        cacheMsgFids(env, lpMsg, &PGLOB(MsgFc));
        getMsgFields(env, lpMsg, lpMsg1, &PGLOB(MsgFc));
    }
    return (jint) DispatchMessageA(lpMsg1);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    DispatchMessageW
 * Signature: (Lorg/eclipse/swt/internal/win32/MSG;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_DispatchMessageW
  (JNIEnv *env, jclass that, jobject lpMsg)
{
	DECL_GLOB(pGlob)
    MSG callBack, *lpMsg1 = NULL;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "DispatchMessageW\n");
#endif

    if (lpMsg) {
        lpMsg1 = &callBack;
        cacheMsgFids(env, lpMsg, &PGLOB(MsgFc));
        getMsgFields(env, lpMsg, lpMsg1, &PGLOB(MsgFc));
    }
    return (jint) DispatchMessageW(lpMsg1);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    DrawEdge
 * Signature: (ILorg/eclipse/swt/internal/win32/RECT;II)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_DrawEdge
  (JNIEnv *env, jclass that, jint hdc, jobject lpRect, jint edge, jint grfFlags)
{
	DECL_GLOB(pGlob)
    RECT rect, *lpRect1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "DrawEdge\n");
#endif

    if (lpRect) {
        lpRect1 = &rect;

        cacheRectFids(env, lpRect, &PGLOB(RectFc));
        getRectFields(env, lpRect, lpRect1, &PGLOB(RectFc));
    }
    rc = (jboolean) DrawEdge((HDC)hdc, lpRect1, edge, grfFlags);
    if (lpRect) {
        setRectFields(env, lpRect, lpRect1, &PGLOB(RectFc));    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    DrawFocusRect
 * Signature: (ILorg/eclipse/swt/internal/win32/RECT;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_DrawFocusRect
  (JNIEnv *env, jclass that, jint hdc, jobject lpRect)
{
	DECL_GLOB(pGlob)
    RECT rect, *lpRect1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "DrawFocusRect\n");
#endif

    if (lpRect) {
        lpRect1 = &rect;
        cacheRectFids(env, lpRect, &PGLOB(RectFc));
        getRectFields(env, lpRect, lpRect1, &PGLOB(RectFc));
    }
    rc = (jboolean) DrawFocusRect((HDC)hdc, lpRect1);
    if (lpRect) {
        setRectFields(env, lpRect, lpRect1, &PGLOB(RectFc));    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    DrawFrameControl
 * Signature: (ILorg/eclipse/swt/internal/win32/RECT;II)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_DrawFrameControl
  (JNIEnv *env, jclass that, jint hdc, jobject lprc, jint uType, jint uState)
{
	DECL_GLOB(pGlob)
    RECT rect, *lprc1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "DrawFrameControl\n");
#endif

    if (lprc) {
        lprc1 = &rect;
        cacheRectFids(env, lprc, &PGLOB(RectFc));
        getRectFields(env, lprc, lprc1, &PGLOB(RectFc));
    }
    rc = (jboolean) DrawFrameControl((HDC)hdc, lprc1, uType, uState);
    if (lprc) {
        setRectFields(env, lprc, lprc1, &PGLOB(RectFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    DrawIconEx
 * Signature: (IIIIIIIII)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_DrawIconEx
  (JNIEnv *env, jclass that, jint hdc, jint xLeft, jint yTop, jint hIcom,
                             jint cxWidth, jint cyWidth, jint istepIfAniCur,
                             jint hbrFlickerFreeDraw, jint diFlags)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "DrawIconEx\n");
#endif

    return (jboolean) DrawIconEx((HDC)hdc, xLeft, yTop, (HICON)hIcom, cxWidth,
                                   cyWidth, istepIfAniCur, (HBRUSH)hbrFlickerFreeDraw,
                                   diFlags);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    DrawMenuBar
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_DrawMenuBar
  (JNIEnv *env, jclass that, jint hWnd)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "DrawMenuBar\n");
#endif

    return (jboolean) DrawMenuBar((HWND)hWnd);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    DrawTextA
 * Signature: (I[BILorg/eclipse/swt/internal/win32/RECT;I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_DrawTextA
  (JNIEnv *env, jclass that, jint hDC, jbyteArray lpString, jint nCount, jobject lpRect, jint uFormat)
{
	DECL_GLOB(pGlob)
    jbyte* lpString1=NULL;
    RECT rect, *lpRect1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "DrawTextA\n");
#endif

    if (lpRect) {
        lpRect1 = &rect;
        cacheRectFids(env, lpRect, &PGLOB(RectFc));
        getRectFields(env, lpRect, lpRect1, &PGLOB(RectFc));
    }

    if (lpString)
        lpString1 = (*env)->GetByteArrayElements(env, lpString, NULL);

    rc = (jint) DrawTextA((HDC)hDC, (LPSTR)lpString1, nCount, lpRect1, uFormat);

    if (lpString)
        (*env)->ReleaseByteArrayElements(env, lpString, lpString1, 0);

    if (lpRect)
        setRectFields(env, lpRect, lpRect1, &PGLOB(RectFc));
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    DrawTextW
 * Signature: (I[BILorg/eclipse/swt/internal/win32/RECT;I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_DrawTextW
  (JNIEnv *env, jclass that, jint hDC, jcharArray lpString, jint nCount, jobject lpRect, jint uFormat)
{
	DECL_GLOB(pGlob)
    jchar* lpString1=NULL;
    RECT rect, *lpRect1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "DrawTextW\n");
#endif

    if (lpRect) {
        lpRect1 = &rect;
        cacheRectFids(env, lpRect, &PGLOB(RectFc));
        getRectFields(env, lpRect, lpRect1, &PGLOB(RectFc));
    }

    if (lpString)
        lpString1 = (*env)->GetCharArrayElements(env, lpString, NULL);

    rc = (jint) DrawTextW((HDC)hDC, (LPWSTR)lpString1, nCount, lpRect1, uFormat);

    if (lpString)
        (*env)->ReleaseCharArrayElements(env, lpString, lpString1, 0);

    if (lpRect)
        setRectFields(env, lpRect, lpRect1, &PGLOB(RectFc));
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    Ellipse
 * Signature: (IIIII)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_Ellipse
  (JNIEnv *env, jclass that, jint hdc, jint nLeftRect, jint nTopRect, jint nRightRect, jint nBottomRect)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "Ellipse\n");
#endif

    return (jboolean) Ellipse((HDC)hdc, nLeftRect, nTopRect, nRightRect, nBottomRect);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    EnableMenuItem
 * Signature: (III)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_EnableMenuItem
  (JNIEnv *env, jclass that, jint hMenu, jint uIDEnableItem, jint uEnable)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "EnableMenuItem\n");
#endif

    return (jboolean) EnableMenuItem((HMENU)hMenu, uIDEnableItem, uEnable);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    EnableWindow
 * Signature: (IZ)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_EnableWindow
  (JNIEnv *env, jclass that, jint hWnd, jboolean bEnable)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "EnableWindow\n");
#endif

    return (jboolean) EnableWindow((HWND)hWnd, bEnable);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    EndDeferWindowPos
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_EndDeferWindowPos
  (JNIEnv *env, jclass that, jint hWinPosInfo)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "EndDeferWindowPos\n");
#endif

    return (jboolean) EndDeferWindowPos((HDWP)hWinPosInfo);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    EndPaint
 * Signature: (ILorg/eclipse/swt/internal/win32/;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_EndPaint
  (JNIEnv *env, jclass that, jint hWnd, jobject lpPaint)
{
    PAINTSTRUCT paint, *lpPaint1=NULL;
    jclass paintClass;
    jfieldID fid;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "EndPaint\n");
#endif

    if (lpPaint) {
        paintClass = (*env)->GetObjectClass(env,lpPaint);
        lpPaint1=&paint;

        fid = (*env)->GetFieldID(env,paintClass,"hdc","I");
        lpPaint1->hdc = (void *) (*env)->GetIntField(env,lpPaint,fid);
    }
    rc = (jint)EndPaint((HWND)hWnd, lpPaint1);
    
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    EnumFontFamiliesA
 * Signature: (I[BII)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_EnumFontFamiliesA
  (JNIEnv *env, jclass that, jint hdc, jbyteArray lpszFamily, jint lpEnumFontFamProc, jint lParam)
{
    jbyte* lpszFamily1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "EnumFontFamiliesA\n");
#endif

    if (lpszFamily)
        lpszFamily1 = (*env)->GetByteArrayElements(env, lpszFamily, NULL);

    rc = (jint) EnumFontFamiliesA((HDC)hdc, (LPSTR)lpszFamily1, (FONTENUMPROC)lpEnumFontFamProc, (LPARAM)lParam);

    if (lpszFamily)
        (*env)->ReleaseByteArrayElements(env, lpszFamily, (jbyte *)lpszFamily1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    EnumFontFamiliesW
 * Signature: (I[CII)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_EnumFontFamiliesW
  (JNIEnv *env, jclass that, jint hdc, jcharArray lpszFamily, jint lpEnumFontFamProc, jint lParam)
{
    jchar* lpszFamily1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "EnumFontFamiliesW\n");
#endif

    if (lpszFamily)
        lpszFamily1 = (*env)->GetCharArrayElements(env, lpszFamily, NULL);

    rc = (jint) EnumFontFamiliesW((HDC)hdc, (LPCWSTR)lpszFamily1, (FONTENUMPROCW)lpEnumFontFamProc, (LPARAM)lParam);

    if (lpszFamily)
        (*env)->ReleaseCharArrayElements(env, lpszFamily, lpszFamily1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    EnumFontFamiliesEx
 * Signature: (ILorg/eclipse/swt/internal/win32/LOGFONT;III)I
 */
/*
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_EnumFontFamiliesEx
  (JNIEnv *env, jclass that, jint hdc, jobject lpLogfont, jint lpEnumFontFamExProc, jint lParam, jint dwFlags)
{
	DECL_GLOB(pGlob)
    LOGFONT logfont, *lpLogfont1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "EnumFontFamiliesEx\n");
#endif
    if (lpLogfont) {
        lpLogfont1 = &logfont;
        cacheLogfontFids(env, lpLogfont, &PGLOB(LogfontFc));
        getLogfontFields(env, lpLogfont, lpLogfont1, &PGLOB(LogfontFc));
    }
    rc = (jint) EnumFontFamiliesEx((HDC)hdc, lpLogfont1, (FONTENUMPROC)lpEnumFontFamExProc, lParam, dwFlags);
    if (lpLogfont) {
        setLogfontFields(env, lpLogfont, lpLogfont1, &PGLOB(LogfontFc));
    }
    return rc;
}
*/

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    EqualRgn
 * Signature: (II)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_EqualRgn
  (JNIEnv *env, jclass that, jint hSrcRgn1, jint hSrcRgn2)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "EqualRgn\n");
#endif

    return (jboolean) EqualRgn((HRGN)hSrcRgn1, (HRGN)hSrcRgn2);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ExtractIconExA
 * Signature: ([BI[I[II)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_ExtractIconExA
  (JNIEnv *env, jclass that, jbyteArray lpszFile, jint nIconIndex, jintArray phiconLarge, jintArray phiconSmall, jint nIcons)
{
    LPSTR lpszFile1=NULL;
    HICON FAR *phiconLarge1=NULL, *phiconSmall1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "ExtractIconEx\n");
#endif

    if (lpszFile)
        lpszFile1 = (*env)->GetByteArrayElements(env, lpszFile, NULL);
    if (phiconLarge)
        phiconLarge1 = (HICON FAR *)(*env)->GetIntArrayElements(env, phiconLarge, NULL);
    if (phiconSmall)
        phiconSmall1 = (HICON FAR *)(*env)->GetIntArrayElements(env, phiconSmall, NULL);

    rc = (jint) ExtractIconExA( lpszFile1, nIconIndex, phiconLarge1, phiconSmall1, nIcons);

    if (lpszFile)
        (*env)->ReleaseByteArrayElements(env, lpszFile, (jbyte *)lpszFile1, 0);
    if (phiconLarge)
        (*env)->ReleaseIntArrayElements(env, phiconLarge, (jint *)phiconLarge1, 0);
    if (phiconSmall)
        (*env)->ReleaseIntArrayElements(env, phiconSmall, (jint *)phiconSmall1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ExtractIconExW
 * Signature: ([CI[I[II)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_ExtractIconExW
   (JNIEnv *env, jclass that, jcharArray lpszFile, jint nIconIndex, jintArray phiconLarge, jintArray phiconSmall, jint nIcons)
{
	LPWSTR lpszFile1=NULL;
	HICON FAR *phiconLarge1=NULL, *phiconSmall1=NULL;
	jint rc;

#ifdef DEBUG_CALL_PRINTS
	fprintf(stderr, "ExtractIconExW\n");
#endif

	if (lpszFile)
		lpszFile1 = (*env)->GetCharArrayElements(env, lpszFile, NULL);
	if (phiconLarge)
		phiconLarge1 = (HICON FAR *)(*env)->GetIntArrayElements(env, phiconLarge, NULL);
	if (phiconSmall)
		phiconSmall1 = (HICON FAR *)(*env)->GetIntArrayElements(env, phiconSmall, NULL);

	rc = (jint) ExtractIconExW( lpszFile1, nIconIndex, phiconLarge1, phiconSmall1, nIcons);

	if (lpszFile)
		(*env)->ReleaseCharArrayElements(env, lpszFile, (jchar *)lpszFile1, 0);
	if (phiconLarge)
		(*env)->ReleaseIntArrayElements(env, phiconLarge, (jint *)phiconLarge1, 0);
	if (phiconSmall)
		(*env)->ReleaseIntArrayElements(env, phiconSmall, (jint *)phiconSmall1, 0);
	return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    FillRect
 * Signature: (ILorg/eclipse/swt/internal/win32/RECT;I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_FillRect
  (JNIEnv *env, jclass that, jint hDC, jobject lpRect, jint hbr)
{
	DECL_GLOB(pGlob)
    RECT rect, *lpRect1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "FillRect\n");
#endif

    if (lpRect) {
        lpRect1 = &rect;
        cacheRectFids(env, lpRect, &PGLOB(RectFc));
        getRectFields(env, lpRect, lpRect1, &PGLOB(RectFc));
    }
    rc = (jint) FillRect((HDC)hDC, lpRect1, (HBRUSH) hbr);
    if (lpRect) {
        setRectFields(env, lpRect, lpRect1, &PGLOB(RectFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    FreeLibrary
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_FreeLibrary
  (JNIEnv *env, jclass that, jint hLibModule)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "FreeLibrary\n");
#endif

    return (jboolean) FreeLibrary((HMODULE) hLibModule);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetACP
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetACP
  (JNIEnv *env, jclass that)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetACP\n");
#endif

    return (jint)GetACP();
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetActiveWindow
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetActiveWindow
  (JNIEnv *env, jclass that)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetActiveWindow\n");
#endif

    return (jint)GetActiveWindow();
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetBkColor
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetBkColor
  (JNIEnv *env, jclass that, jint hDC)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetBkColor\n");
#endif

    return (jint) GetBkColor((HDC)hDC);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetCapture
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetCapture
  (JNIEnv *env, jclass that)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetCapture\n");
#endif

    return (jint)GetCapture();
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetCaretPos
 * Signature: (Lorg/eclipse/swt/internal/win32/POINT;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_GetCaretPos
  (JNIEnv *env, jclass that, jobject lpPoint)
{
	DECL_GLOB(pGlob)
    POINT point, *lpPoint1=NULL;
    jboolean rc;
    
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetCaretPos\n");
#endif

    if (lpPoint) {
        lpPoint1 = &point;
        cachePointFids(env, lpPoint, &PGLOB(PointFc));
        getPointFields(env, lpPoint, lpPoint1, &PGLOB(PointFc));
    }
    rc = (jboolean) GetCaretPos(lpPoint1);
    if (lpPoint) {
        setPointFields(env, lpPoint, lpPoint1, &PGLOB(PointFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetClassInfoA
 * Signature: (I[BLorg/eclipse/swt/internal/win32/WNDCLASS;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_GetClassInfoA
  (JNIEnv *env, jclass that, jint hinst, jbyteArray lpszClass, jobject lpwcx)
{
	DECL_GLOB(pGlob)
    jbyte* lpszClass1=NULL;
    WNDCLASS wcx, *lpwcx1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetClassInfoA\n");
#endif
    
    if (lpszClass)
        lpszClass1 = (*env)->GetByteArrayElements(env, lpszClass, NULL);
    if (lpwcx) {
        lpwcx1 = &wcx;
        cacheWndclassFids(env, lpwcx, &PGLOB(WndclassFc));
        getWndclassFields(env, lpwcx, lpwcx1, &PGLOB(WndclassFc));
    }
    
    rc = (jboolean) GetClassInfoA((HINSTANCE)hinst, (LPSTR)lpszClass1, &wcx);

    if (lpwcx) {
        setWndclassFields(env, lpwcx, lpwcx1, &PGLOB(WndclassFc));
    }
    if (lpszClass)
        (*env)->ReleaseByteArrayElements(env, lpszClass, lpszClass1, 0);
        
    return rc;
}

JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_GetClassInfoW
  (JNIEnv *env, jclass that, jint hinst, jcharArray lpszClass, jobject lpwcx)
{
	DECL_GLOB(pGlob)
    jchar* lpszClass1=NULL;
    WNDCLASSW wcx, *lpwcx1=NULL;
    jboolean rc;
    
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetClassInfoW\n");
#endif

    if (lpszClass)
        lpszClass1 = (*env)->GetCharArrayElements(env, lpszClass, NULL);
    if (lpwcx) {
        lpwcx1 = &wcx;
        cacheWndclassFids(env, lpwcx, &PGLOB(WndclassFc));
        getWndclassFields(env, lpwcx, lpwcx1, &PGLOB(WndclassFc));
    }
    
    rc = (jboolean) GetClassInfoW((HINSTANCE)hinst, (LPWSTR)lpszClass1, lpwcx1);

    if (lpwcx) {
        setWndclassFields(env, lpwcx, lpwcx1, &PGLOB(WndclassFc));
    }
    if (lpszClass)
        (*env)->ReleaseCharArrayElements(env, lpszClass, lpszClass1, 0);
        
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetClientRect
 * Signature: (ILorg/eclipse/swt/internal/win32/RECT;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_GetClientRect
  (JNIEnv *env, jclass that, jint hWnd, jobject lpRect)
{
	DECL_GLOB(pGlob)
    RECT rect, *lpRect1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetClientRect\n");
#endif

    if (lpRect) {
        lpRect1 = &rect;
        cacheRectFids(env, lpRect, &PGLOB(RectFc));
        getRectFields(env, lpRect, lpRect1, &PGLOB(RectFc));
    }
    rc = (jboolean) GetClientRect((HWND)hWnd, lpRect1);
    if (lpRect) {
        setRectFields(env, lpRect, lpRect1, &PGLOB(RectFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetClipboardData
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetClipboardData
  (JNIEnv *env,  jclass that, jint uFormat)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetClipboardData\n");
#endif
    return (jint) GetClipboardData(uFormat);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetClipBox
 * Signature: (ILorg/eclipse/swt/internal/win32/RECT;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetClipBox
  (JNIEnv *env, jclass that, jint hdc, jobject lprc)
{
	DECL_GLOB(pGlob)
    RECT rect, *lprc1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetClipBox\n");
#endif

    if (lprc) {
        lprc1 = &rect;
        cacheRectFids(env, lprc, &PGLOB(RectFc));
        getRectFields(env, lprc, lprc1, &PGLOB(RectFc));
    }
    rc = (jint) GetClipBox((HDC)hdc, lprc1);
    if (lprc) {
        setRectFields(env, lprc, lprc1, &PGLOB(RectFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetCursor
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetCursor
  (JNIEnv *env, jclass that)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetCursor\n");
#endif

    return (jint) GetCursor();
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetClipRgn
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetClipRgn
  (JNIEnv *env, jclass that, jint hdc, jint hrgn)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetClipRgn\n");
#endif
    return (jint) GetClipRgn((HDC)hdc, (HRGN)hrgn);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetCurrentObject
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetCurrentObject
  (JNIEnv *env, jclass that, jint hdc, jint uObjectType)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetCurrentObject\n");
#endif

    return (jint)GetCurrentObject((HDC)hdc, uObjectType);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetCurrentProcessId
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetCurrentProcessId
  (JNIEnv * env, jclass that)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetCurrentProcessId\n");
#endif

    return (jint) GetCurrentProcessId();
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetCurrentThreadId
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetCurrentThreadId
  (JNIEnv *env, jclass that)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetCurrentThreadId\n");
#endif

    return (jint)GetCurrentThreadId();
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetCursorPos
 * Signature: (Lorg/eclipse/swt/internal/win32/POINT;)I
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_GetCursorPos
  (JNIEnv *env, jclass that, jobject lpPoint)
{
	DECL_GLOB(pGlob)
    POINT point, *lpPoint1=NULL;
    jboolean rc;
    
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetCursorPos\n");
#endif

    if (lpPoint) {
        lpPoint1 = &point;
        cachePointFids(env, lpPoint, &PGLOB(PointFc));
        getPointFields(env, lpPoint, lpPoint1, &PGLOB(PointFc));
    }
    rc = (jboolean) GetCursorPos(lpPoint1);
    if (lpPoint)
        setPointFields(env, lpPoint, lpPoint1, &PGLOB(PointFc));

    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetDC
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetDC
  (JNIEnv *env, jclass that, jint hWnd)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetDC\n");
#endif

    return (jint)GetDC((HWND)hWnd);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetDCEx
 * Signature: (III)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetDCEx
  (JNIEnv *env, jclass that, jint hWnd, jint hrgnClip, jint flags)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetDCEx\n");
#endif

    return (jint)GetDCEx((HWND)hWnd, (HRGN)hrgnClip, (DWORD)flags);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetDesktopWindow
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetDesktopWindow
  (JNIEnv *env, jclass that)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetDesktopWindow\n");
#endif

    return (jint) GetDesktopWindow();
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetDeviceCaps
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetDeviceCaps
  (JNIEnv *env, jclass that, jint hdc, jint nIndex)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetDeviceCaps\n");
#endif

    return (jint) GetDeviceCaps((HDC) hdc, nIndex);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetDialogBaseUnits
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetDialogBaseUnits
  (JNIEnv *env, jclass that)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetDialogBaseUnits\n");
#endif

    return (jint)GetDialogBaseUnits();
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetDlgItem
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetDlgItem
  (JNIEnv *env, jclass that, jint hDlg, jint nIDDlgItem)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetDlgItem\n");
#endif

    return (jint)GetDlgItem((HWND)hDlg, nIDDlgItem);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetDoubleClickTime
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetDoubleClickTime
  (JNIEnv *env, jclass that)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetDoubleClickTime\n");
#endif

    return (jint)GetDoubleClickTime();
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetFocus
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetFocus
  (JNIEnv *env, jclass that)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetFocus\n");
#endif

    return (jint) GetFocus();
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetKeyState
 * Signature: (I)S
 */
JNIEXPORT jshort JNICALL Java_org_eclipse_swt_internal_win32_OS_GetKeyState
  (JNIEnv *env, jclass that, jint nVirtKey)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetKeyState\n");
#endif

    return (jshort) GetKeyState(nVirtKey);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetLastError
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetLastError
  (JNIEnv *env,  jclass that)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetLastError\n");
#endif
    return (jint) GetLastError();
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetMenuItemInfoA
 * Signature: (IIZLorg/eclipse/swt/internal/win32/MENUITEMINFO;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_GetMenuItemInfoA
  (JNIEnv *env, jclass that, jint hMenu, jint uItem, jboolean fByPosition, jobject lpmii)
{
	DECL_GLOB(pGlob)
    MENUITEMINFO mii1, *lpmii1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetMenuItemInfoA\n");
#endif

    if (lpmii) {
        lpmii1 = &mii1;
        cacheMenuiteminfoFids(env, lpmii, &PGLOB(MenuiteminfoFc));
        getMenuiteminfoFields(env, lpmii, lpmii1, &PGLOB(MenuiteminfoFc));
    }

    rc = (jboolean) GetMenuItemInfoA((HMENU)hMenu, uItem, fByPosition, lpmii1);
    if (lpmii) {
        setMenuiteminfoFields(env, lpmii, lpmii1, &PGLOB(MenuiteminfoFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetMenuItemInfoW
 * Signature: (IIZLorg/eclipse/swt/internal/win32/MENUITEMINFO;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_GetMenuItemInfoW
  (JNIEnv *env, jclass that, jint hMenu, jint uItem, jboolean fByPosition, jobject lpmii)
{
	DECL_GLOB(pGlob)
    MENUITEMINFO mii1, *lpmii1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetMenuItemInfoW\n");
#endif

    if (lpmii) {
        lpmii1 = &mii1;
        cacheMenuiteminfoFids(env, lpmii, &PGLOB(MenuiteminfoFc));
        getMenuiteminfoFields(env, lpmii, lpmii1, &PGLOB(MenuiteminfoFc));
    }

    rc = (jboolean) GetMenuItemInfoW((HMENU)hMenu, uItem, fByPosition, (LPMENUITEMINFOW)lpmii1);
    if (lpmii) {
        setMenuiteminfoFields(env, lpmii, lpmii1, &PGLOB(MenuiteminfoFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetMessageA
 * Signature: (Lorg/eclipse/swt/internal/win32/MSG;III)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_GetMessageA
  (JNIEnv *env, jclass that, jobject lpMsg, jint hWnd, jint wMsgFilterMin, jint wMsgFilterMax)
{
	DECL_GLOB(pGlob)
    MSG callBack, *lpMsg1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetMessageA\n");
#endif

    if (lpMsg) {
        lpMsg1 = &callBack;
        cacheMsgFids(env, lpMsg, &PGLOB(MsgFc));
        getMsgFields(env, lpMsg, lpMsg1, &PGLOB(MsgFc));
    }
    rc = (jboolean) GetMessageA(&callBack,(HWND)hWnd,wMsgFilterMin,wMsgFilterMax);
    if (lpMsg) {
        setMsgFields(env, lpMsg, lpMsg1, &PGLOB(MsgFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetMessageW
 * Signature: (Lorg/eclipse/swt/internal/win32/MSG;III)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_GetMessageW
  (JNIEnv *env, jclass that, jobject lpMsg, jint hWnd, jint wMsgFilterMin, jint wMsgFilterMax)
{
	DECL_GLOB(pGlob)
    MSG callBack, *lpMsg1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetMessageW\n");
#endif

    if (lpMsg) {
        lpMsg1 = &callBack;
        cacheMsgFids(env, lpMsg, &PGLOB(MsgFc));
        getMsgFields(env, lpMsg, lpMsg1, &PGLOB(MsgFc));
    }
    rc = (jboolean) GetMessageW(&callBack,(HWND)hWnd,wMsgFilterMin,wMsgFilterMax);
    if (lpMsg) {
        setMsgFields(env, lpMsg, lpMsg1, &PGLOB(MsgFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetMessagePos
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetMessagePos
  (JNIEnv *env, jclass that)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetMessagePos\n");
#endif

    return (jint) GetMessagePos();
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetModuleHandleA
 * Signature: ([B)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetModuleHandleA
  (JNIEnv *env, jclass that, jbyteArray lpModuleName)
{
    jbyte *lpModuleName1 = NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetModuleHandleA\n");
#endif

    if (lpModuleName)
         lpModuleName1 = (*env)->GetByteArrayElements(env, lpModuleName, NULL);

    rc = (jint) GetModuleHandleA((LPSTR)lpModuleName1);

    if (lpModuleName)
        (*env)->ReleaseByteArrayElements(env, lpModuleName, lpModuleName1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetModuleHandleW
 * Signature: ([C)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetModuleHandleW
  (JNIEnv *env, jclass that, jcharArray lpModuleName)
{
    jchar* lpModuleName1 = NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetModuleHandleW\n");
#endif

    if (lpModuleName)
         lpModuleName1 = (*env)->GetCharArrayElements(env, lpModuleName, NULL);

    rc = (jint) GetModuleHandleW((LPWSTR)lpModuleName1);

    if (lpModuleName)
        (*env)->ReleaseCharArrayElements(env, lpModuleName, lpModuleName1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetNearestPaletteIndex
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetNearestPaletteIndex
  (JNIEnv *env, jclass that, jint hPal, jint crColor)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetNearestPaletteIndex\n");
#endif

    return (jint)GetNearestPaletteIndex((HPALETTE)hPal, (COLORREF) crColor);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetObjectA
 * Signature: (IILorg/eclipse/swt/internal/win32/BITMAP;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetObjectA__IILorg_eclipse_swt_internal_win32_BITMAP_2
  (JNIEnv *env, jclass that, jint hgdiobj, jint cbBuffer, jobject lpvObject)
{
	DECL_GLOB(pGlob)
    BITMAP bitmap, *lpvObject1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetObjectA__IILorg_eclipse_swt_internal_win32_BITMAP_2\n");
#endif

    if (lpvObject) {
        lpvObject1 = &bitmap;
        cacheBitmapFids(env, lpvObject, &PGLOB(BitmapFc));
        getBitmapFields(env, lpvObject, lpvObject1, &PGLOB(BitmapFc));
    }
    rc = (jint) GetObjectA((HGDIOBJ)hgdiobj, cbBuffer, (LPVOID)lpvObject1);
    if (lpvObject) {
        setBitmapFields(env, lpvObject, lpvObject1, &PGLOB(BitmapFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetObjectW
 * Signature: (IILorg/eclipse/swt/internal/win32/BITMAP;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetObjectW__IILorg_eclipse_swt_internal_win32_BITMAP_2
  (JNIEnv *env, jclass that, jint hgdiobj, jint cbBuffer, jobject lpvObject)
{
	DECL_GLOB(pGlob)
    BITMAP bitmap, *lpvObject1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetObjectW__IILorg_eclipse_swt_internal_win32_BITMAP_2\n");
#endif

    if (lpvObject) {
        lpvObject1 = &bitmap;
        cacheBitmapFids(env, lpvObject, &PGLOB(BitmapFc));
        getBitmapFields(env, lpvObject, lpvObject1, &PGLOB(BitmapFc));
    }
    rc = (jint) GetObjectW((HGDIOBJ)hgdiobj, cbBuffer, (LPVOID)lpvObject1);
    if (lpvObject) {
        setBitmapFields(env, lpvObject, lpvObject1, &PGLOB(BitmapFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetObjectA
 * Signature: (IILorg/eclipse/swt/internal/win32/DIBSECTION;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetObjectA__IILorg_eclipse_swt_internal_win32_DIBSECTION_2
  (JNIEnv *env, jclass that, jint hgdiobj, jint cbBuffer, jobject lpvObject)
{
	DECL_GLOB(pGlob)
    DIBSECTION dibsection, *lpvObject1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetObjectA__IILorg_eclipse_swt_internal_win32_DIBSECTION_2\n");
#endif

    if (lpvObject) {
        lpvObject1 = &dibsection;
        cacheDibsectionFids(env, lpvObject, &PGLOB(DibsectionFc));
        getDibsectionFields(env, lpvObject, lpvObject1, &PGLOB(DibsectionFc));
    }
    rc = (jint) GetObjectA((HGDIOBJ)hgdiobj, cbBuffer, (LPVOID)lpvObject1);
    if (lpvObject) {
        setDibsectionFields(env, lpvObject, lpvObject1, &PGLOB(DibsectionFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetObjectW
 * Signature: (IILorg/eclipse/swt/internal/win32/DIBSECTION;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetObjectW__IILorg_eclipse_swt_internal_win32_DIBSECTION_2
  (JNIEnv *env, jclass that, jint hgdiobj, jint cbBuffer, jobject lpvObject)
{
	DECL_GLOB(pGlob)
    DIBSECTION dibsection, *lpvObject1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetObjectW__IILorg_eclipse_swt_internal_win32_DIBSECTION_2\n");
#endif

    if (lpvObject) {
        lpvObject1 = &dibsection;
        cacheDibsectionFids(env, lpvObject, &PGLOB(DibsectionFc));
        getDibsectionFields(env, lpvObject, lpvObject1, &PGLOB(DibsectionFc));
    }
    rc = (jint) GetObjectW((HGDIOBJ)hgdiobj, cbBuffer, (LPVOID)lpvObject1);
    if (lpvObject) {
        setDibsectionFields(env, lpvObject, lpvObject1, &PGLOB(DibsectionFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetObjectA
 * Signature: (IILorg/eclipse/swt/internal/win32/LOGBRUSH;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetObjectA__IILorg_eclipse_swt_internal_win32_LOGBRUSH_2
  (JNIEnv *env, jclass that, jint hgdiobj, jint cbBuffer, jobject lpvObject)
{
	DECL_GLOB(pGlob)
    LOGBRUSH logbrush, *lpvObject1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetObjectA__IILorg_eclipse_swt_internal_win32_LOGBRUSH_2\n");
#endif

    if (lpvObject) {
        lpvObject1 = &logbrush;
        cacheLogbrushFids(env, lpvObject, &PGLOB(LogbrushFc));
        getLogbrushFields(env, lpvObject, lpvObject1, &PGLOB(LogbrushFc));
    }
    rc = (jint) GetObjectA((HGDIOBJ)hgdiobj, cbBuffer, (LPVOID)lpvObject1);
    if (lpvObject) {
        setLogbrushFields(env, lpvObject, lpvObject1, &PGLOB(LogbrushFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetObjectW
 * Signature: (IILorg/eclipse/swt/internal/win32/LOGBRUSH;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetObjectW__IILorg_eclipse_swt_internal_win32_LOGBRUSH_2
  (JNIEnv *env, jclass that, jint hgdiobj, jint cbBuffer, jobject lpvObject)
{
	DECL_GLOB(pGlob)
    LOGBRUSH logbrush, *lpvObject1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetObjectW__IILorg_eclipse_swt_internal_win32_LOGBRUSH_2\n");
#endif

    if (lpvObject) {
        lpvObject1 = &logbrush;
        cacheLogbrushFids(env, lpvObject, &PGLOB(LogbrushFc));
        getLogbrushFields(env, lpvObject, lpvObject1, &PGLOB(LogbrushFc));
    }
    rc = (jint) GetObjectW((HGDIOBJ)hgdiobj, cbBuffer, (LPVOID)lpvObject1);
    if (lpvObject) {
        setLogbrushFields(env, lpvObject, lpvObject1, &PGLOB(LogbrushFc));
    }
    return rc;
}


/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetObjectA
 * Signature: (IILorg/eclipse/swt/internal/win32/LOGFONT;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetObjectA__IILorg_eclipse_swt_internal_win32_LOGFONT_2
  (JNIEnv *env, jclass that, jint hgdiobj, jint cbBuffer, jobject lpvObject)
{
	DECL_GLOB(pGlob)
    LOGFONTA logfont, *lpvObject1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetObjectA__IILorg_eclipse_swt_internal_win32_LOGFONT_2\n");
#endif
    if (lpvObject) {
        lpvObject1 = &logfont;
        cacheLogfontFids(env, lpvObject, &PGLOB(LogfontFc));
        getLogfontFieldsA(env, lpvObject, lpvObject1, &PGLOB(LogfontFc));
    }

    rc = (jint) GetObjectA((HGDIOBJ)hgdiobj, cbBuffer, lpvObject1);

    if (lpvObject1) {
        setLogfontFieldsA(env, lpvObject, lpvObject1, &PGLOB(LogfontFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetObjectW
 * Signature: (IILorg/eclipse/swt/internal/win32/LOGFONT;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetObjectW__IILorg_eclipse_swt_internal_win32_LOGFONT_2
  (JNIEnv *env, jclass that, jint hgdiobj, jint cbBuffer, jobject lpvObject)
{
	DECL_GLOB(pGlob)
    LOGFONTW logfont, *lpvObject1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetObject__IILorg_eclipse_swt_internal_win32_LOGFONT_2\n");
#endif
    if (lpvObject) {
        lpvObject1 = &logfont;
        cacheLogfontFids(env, lpvObject, &PGLOB(LogfontFc));
        getLogfontFieldsW(env, lpvObject, lpvObject1, &PGLOB(LogfontFc));
    }

    rc = (jint) GetObjectW((HGDIOBJ)hgdiobj, cbBuffer, lpvObject1);

    if (lpvObject1) {
        setLogfontFieldsW(env, lpvObject, lpvObject1, &PGLOB(LogfontFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetObjectA
 * Signature: (IILorg/eclipse/swt/internal/win32/LOGPEN;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetObjectA__IILorg_eclipse_swt_internal_win32_LOGPEN_2
  (JNIEnv *env, jclass that, jint hgdiobj, jint cbBuffer, jobject lpvObject)
{
	DECL_GLOB(pGlob)
    LOGPEN logpen, *lpvObject1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetObjectA__IILorg_eclipse_swt_internal_win32_LOGPEN_2\n");
#endif
    if (lpvObject) {
        lpvObject1 = &logpen;
        cacheLogpenFids(env, lpvObject, &PGLOB(LogpenFc));
        getLogpenFields(env, lpvObject, lpvObject1, &PGLOB(LogpenFc));
    }

    rc = (jint) GetObjectA((HGDIOBJ)hgdiobj, cbBuffer, lpvObject1);

    if (lpvObject1) {
        setLogpenFields(env, lpvObject, lpvObject1, &PGLOB(LogpenFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetObjectW
 * Signature: (IILorg/eclipse/swt/internal/win32/LOGPEN;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetObjectW__IILorg_eclipse_swt_internal_win32_LOGPEN_2
  (JNIEnv *env, jclass that, jint hgdiobj, jint cbBuffer, jobject lpvObject)
{
	DECL_GLOB(pGlob)
    LOGPEN logpen, *lpvObject1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetObjectW__IILorg_eclipse_swt_internal_win32_LOGPEN_2\n");
#endif
    if (lpvObject) {
        lpvObject1 = &logpen;
        cacheLogpenFids(env, lpvObject, &PGLOB(LogpenFc));
        getLogpenFields(env, lpvObject, lpvObject1, &PGLOB(LogpenFc));
    }

    rc = (jint) GetObjectW((HGDIOBJ)hgdiobj, cbBuffer, lpvObject1);

    if (lpvObject1) {
        setLogpenFields(env, lpvObject, lpvObject1, &PGLOB(LogpenFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetObject
 * Signature: (IILorg/eclipse/swt/internal/win32/EXTLOGPEN;)I
 */
/*
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetObject__IILorg_eclipse_swt_internal_win32_EXTLOGPEN_2
  (JNIEnv *env, jclass that, jint hgdiobj, jint cbBuffer, jobject lpvObject)
{
	DECL_GLOB(pGlob)
    EXTLOGPEN extlogpen, *lpvObject1=NULL;
    jint rc;
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetObject__IILorg_eclipse_swt_internal_win32_EXTLOGPEN_2\n");
#endif
    if (lpvObject) {
        lpvObject1 = &extlogpen;
        cacheExtlogpenFids(env, lpvObject, &PGLOB(ExtlogpenFc));
        getExtlogpenFields(env, lpvObject, lpvObject1, &PGLOB(ExtlogpenFc));
    }
    rc = (jint) GetObject((HGDIOBJ)hgdiobj, cbBuffer, lpvObject1);
    if (lpvObject1) {
        setExtlogpenFields(env, lpvObject, lpvObject1, &PGLOB(ExtlogpenFc));
    }
    return rc;
}
*/

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetOpenFileNameA
 * Signature: (Lorg/eclipse/swt/internal/win32/OPENFILENAME;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_GetOpenFileNameA
  (JNIEnv *env, jclass that, jobject lpofn)
{
	DECL_GLOB(pGlob)
    OPENFILENAME ofn1, *lpofn1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetOpenFileNameA\n");
#endif

    if (lpofn) {
        lpofn1 = &ofn1;
        cacheOpenfilenameFids(env, lpofn, &PGLOB(OpenfilenameFc));
        getOpenfilenameFields(env, lpofn, lpofn1, &PGLOB(OpenfilenameFc));
    }
    rc = (jboolean) GetOpenFileNameA((LPOPENFILENAME)lpofn1);
    if (lpofn) {
        setOpenfilenameFields(env, lpofn, lpofn1, &PGLOB(OpenfilenameFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetOpenFileNameW
 * Signature: (Lorg/eclipse/swt/internal/win32/OPENFILENAME;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_GetOpenFileNameW
  (JNIEnv *env, jclass that, jobject lpofn)
{
	DECL_GLOB(pGlob)
    OPENFILENAME ofn1, *lpofn1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetOpenFileNameW\n");
#endif

    if (lpofn) {
        lpofn1 = &ofn1;
        cacheOpenfilenameFids(env, lpofn, &PGLOB(OpenfilenameFc));
        getOpenfilenameFields(env, lpofn, lpofn1, &PGLOB(OpenfilenameFc));
    }
    rc = (jboolean) GetOpenFileNameW((LPOPENFILENAMEW)lpofn1);
    if (lpofn) {
        setOpenfilenameFields(env, lpofn, lpofn1, &PGLOB(OpenfilenameFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetPaletteEntries
 * Signature: (III[B)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetPaletteEntries
  (JNIEnv *env, jclass that, jint hPalette, jint iStartIndex, jint nEntries, jbyteArray logPalette)
{
    LPTSTR logPalette1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetPaletteEntries\n");
#endif

    if (logPalette)
        logPalette1 = (*env)->GetByteArrayElements(env, logPalette, NULL);

    rc = (jint) GetPaletteEntries((HPALETTE) hPalette, iStartIndex, nEntries, (LPPALETTEENTRY)logPalette1);

    if (logPalette)
        (*env)->ReleaseByteArrayElements(env, logPalette, (jbyte *)logPalette1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetParent
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetParent
  (JNIEnv *env, jclass that, jint hWnd)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetParent\n");
#endif

    return (jint) GetParent((HWND)hWnd);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetProcAddress
 * Signature: (I[B)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetProcAddress
  (JNIEnv *env, jclass that, jint hModule, jbyteArray lpProcName)
{
    LPCSTR lpProcName1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetProcAddress\n");
#endif

    if (lpProcName)
        lpProcName1 = (LPCSTR)(*env)->GetByteArrayElements(env,lpProcName, NULL);

    rc = (jint)GetProcAddress((HMODULE)hModule, lpProcName1);

    if (lpProcName)
        (*env)->ReleaseByteArrayElements(env, lpProcName, (jbyte *)lpProcName1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetProcessHeap
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetProcessHeap
  (JNIEnv *env, jclass that)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetProcessHeap\n");
#endif

    return (jint) GetProcessHeap();
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetRegionData
 * Signature: (II[I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetRegionData
  (JNIEnv *env, jclass that, jint hRgn, jint dwCount, jintArray lpRgnData)
{
    RGNDATA *lpRgnData1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetRegionData\n");
#endif

    if (lpRgnData)
        lpRgnData1 = (RGNDATA *)(*env)->GetIntArrayElements(env, lpRgnData, NULL);

    rc = (jint) GetRegionData((HRGN)hRgn, dwCount, lpRgnData1);

    if (lpRgnData)
        (*env)->ReleaseIntArrayElements(env, lpRgnData, (jint *)lpRgnData1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetRgnBox
 * Signature: (ILorg/eclipse/swt/internal/win32/RECT;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetRgnBox
  (JNIEnv *env, jclass that, jint hrgn, jobject lpRect)
{
	DECL_GLOB(pGlob)
    RECT rect, *lpRect1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetRgnBox\n");
#endif

    if (lpRect) {
        lpRect1 = &rect;
        cacheRectFids(env, lpRect, &PGLOB(RectFc));
        getRectFields(env, lpRect, lpRect1, &PGLOB(RectFc));
    }
    rc = (jint) GetRgnBox((HRGN)hrgn, lpRect1);

    if (lpRect) {
        setRectFields(env, lpRect, lpRect1, &PGLOB(RectFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetSaveFileNameA
 * Signature: (Lorg/eclipse/swt/internal/win32/OPENFILENAME;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_GetSaveFileNameA
  (JNIEnv *env, jclass that, jobject lpofn)
{
	DECL_GLOB(pGlob)
    OPENFILENAME ofn1, *lpofn1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetSaveFileNameA\n");
#endif

    if (lpofn) {
        lpofn1 = &ofn1;
        cacheOpenfilenameFids(env, lpofn, &PGLOB(OpenfilenameFc));
        getOpenfilenameFields(env, lpofn, lpofn1, &PGLOB(OpenfilenameFc));
    }
    rc = (jboolean) GetSaveFileNameA((LPOPENFILENAME)lpofn1);
    if (lpofn) {
        setOpenfilenameFields(env, lpofn, lpofn1, &PGLOB(OpenfilenameFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetSaveFileNameW
 * Signature: (Lorg/eclipse/swt/internal/win32/OPENFILENAME;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_GetSaveFileNameW
  (JNIEnv *env, jclass that, jobject lpofn)
{
	DECL_GLOB(pGlob)
    OPENFILENAME ofn1, *lpofn1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetSaveFileNameW\n");
#endif

    if (lpofn) {
        lpofn1 = &ofn1;
        cacheOpenfilenameFids(env, lpofn, &PGLOB(OpenfilenameFc));
        getOpenfilenameFields(env, lpofn, lpofn1, &PGLOB(OpenfilenameFc));
    }
    rc = (jboolean) GetSaveFileNameW((LPOPENFILENAMEW)lpofn1);
    if (lpofn) {
        setOpenfilenameFields(env, lpofn, lpofn1, &PGLOB(OpenfilenameFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetScrollInfo
 * Signature: (IILorg/eclipse/swt/internal/win32/SCROLLINFO;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_GetScrollInfo
  (JNIEnv *env, jclass that, jint hWnd, jint fnBar, jobject lpsi)
{
	DECL_GLOB(pGlob)
    SCROLLINFO si1, *lpsi1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetScrollInfo\n");
#endif

    if (lpsi) {
        lpsi1 = &si1;
        cacheScrollinfoFids(env, lpsi, &PGLOB(ScrollinfoFc));
        getScrollinfoFields(env, lpsi, lpsi1, &PGLOB(ScrollinfoFc));
    }
    rc = (jboolean) GetScrollInfo((HWND)hWnd, fnBar, lpsi1);
    if (lpsi) {
        setScrollinfoFields(env, lpsi, lpsi1, &PGLOB(ScrollinfoFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetStockObject
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetStockObject
  (JNIEnv *env, jclass that, jint fnObject)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetStockObject\n");
#endif

    return (jint) GetStockObject(fnObject);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetSysColor
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetSysColor
  (JNIEnv *env, jclass that, jint nIndex)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetSysColor\n");
#endif

    return (jint) GetSysColor(nIndex);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetSysColorBrush
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetSysColorBrush
  (JNIEnv *env, jclass that, jint nIndex)
{
    return (jint) GetSysColorBrush(nIndex);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetSystemMenu
 * Signature: (IZ)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetSystemMenu
  (JNIEnv *env, jclass that, jint hWnd, jboolean bRevert)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetSystemMenu\n");
#endif

    return (jint) GetSystemMenu((HWND)hWnd, bRevert);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetSystemMetrics
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetSystemMetrics
  (JNIEnv *env, jclass that, jint nIndex)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetSystemMetrics\n");
#endif

    return (jint) GetSystemMetrics(nIndex);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetTextColor
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetTextColor
  (JNIEnv *env, jclass that, jint hDC)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetTextColor\n");
#endif

    return (jint) GetTextColor((HDC)hDC);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetTextMetricsA
 * Signature: (ILorg/eclipse/swt/internal/win32/TEXTMETRIC;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_GetTextMetricsA
  (JNIEnv *env, jclass that, jint hdc, jobject lptm)
{
	DECL_GLOB(pGlob)
    TEXTMETRICA tm={0}, *lptm1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetTextMetricsA\n");
#endif

    rc = GetTextMetricsA((HDC)hdc, &tm);

    if (lptm) {
        lptm1 = &tm;
        cacheTextmetricFids(env, lptm, &PGLOB(TextmetricFc));
        setTextmetricFieldsA(env, lptm, lptm1, &PGLOB(TextmetricFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetTextMetricsW
 * Signature: (ILorg/eclipse/swt/internal/win32/TEXTMETRIC;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_GetTextMetricsW
  (JNIEnv *env, jclass that, jint hdc, jobject lptm)
{
	DECL_GLOB(pGlob)
    TEXTMETRICW tm={0}, *lptm1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetTextMetricsW\n");
#endif

    rc = GetTextMetricsW((HDC)hdc, &tm);

    if (lptm) {
        lptm1 = &tm;
        cacheTextmetricFids(env, lptm, &PGLOB(TextmetricFc));
        setTextmetricFieldsW(env, lptm, lptm1, &PGLOB(TextmetricFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetUpdateRgn
 * Signature: (IIZ)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetUpdateRgn
  (JNIEnv *env, jclass that, jint hWnd, jint hRgn, jboolean hErase)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetUpdateRgn\n");
#endif

    return (jint) GetUpdateRgn((HWND)hWnd, (HRGN)hRgn, hErase);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetWindow
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetWindow
  (JNIEnv *env, jclass that, jint hWnd, jint uCmd)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetWindow\n");
#endif

    return (jint) GetWindow((HWND)hWnd, uCmd);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetWindowLongA
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetWindowLongA
  (JNIEnv *env, jclass that, jint hWnd, jint nIndex)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetWindowLongA\n");
#endif

     return (jint) GetWindowLongA((HWND)hWnd, nIndex);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetWindowLongW
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetWindowLongW
  (JNIEnv *env, jclass that, jint hWnd, jint nIndex)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetWindowLongW\n");
#endif

     return (jint) GetWindowLongW((HWND)hWnd, nIndex);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetWindowRect
 * Signature: (ILorg/eclipse/swt/internal/win32/RECT;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_GetWindowRect
  (JNIEnv *env, jclass that, jint hWnd, jobject lpRect)
{
	DECL_GLOB(pGlob)
    RECT rect, *lpRect1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetWindowRect\n");
#endif

    if (lpRect) {
        lpRect1 = &rect;
        cacheRectFids(env, lpRect, &PGLOB(RectFc));
        getRectFields(env, lpRect, lpRect1, &PGLOB(RectFc));
    }
    rc = (jboolean) GetWindowRect((HWND)hWnd, lpRect1);
    if (lpRect) {
        setRectFields(env, lpRect, lpRect1, &PGLOB(RectFc));    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetWindowTextA
 * Signature: (I[BI)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetWindowTextA
  (JNIEnv *env, jclass that, jint hWnd, jbyteArray lpString, jint nMaxCount)
{
    jbyte* lpString1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetWindowTextA\n");
#endif

    if (lpString)
        lpString1 = (*env)->GetByteArrayElements(env, lpString, NULL);

    rc = (jint) GetWindowTextA((HWND)hWnd, (LPSTR)lpString1, nMaxCount);

    if (lpString)
        (*env)->ReleaseByteArrayElements(env, lpString, lpString1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetWindowTextW
 * Signature: (I[CI)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetWindowTextW
  (JNIEnv *env, jclass that, jint hWnd, jcharArray lpString, jint nMaxCount)
{
    jchar* lpString1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetWindowTextW\n");
#endif

    if (lpString)
        lpString1 = (*env)->GetCharArrayElements(env, lpString, NULL);

    rc = (jint) GetWindowTextW((HWND)hWnd, (LPWSTR)lpString1, nMaxCount);

    if (lpString)
        (*env)->ReleaseCharArrayElements(env, lpString, lpString1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetWindowTextLengthA
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetWindowTextLengthA
  (JNIEnv *env, jclass that, jint hWnd)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetWindowTextLengthA\n");
#endif

    return (jint) GetWindowTextLengthA((HWND)hWnd);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetWindowTextLengthW
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetWindowTextLengthW
  (JNIEnv *env, jclass that, jint hWnd)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetWindowTextLengthW\n");
#endif

    return (jint) GetWindowTextLengthW((HWND)hWnd);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetWindowThreadProcessId
 * Signature: (I[I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetWindowThreadProcessId
  (JNIEnv *env, jclass that, jint hWnd, jintArray lpdwProcessId)
{
    LPDWORD lpdwProcessId1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetWindowThreadProcessId\n");
#endif

    if (lpdwProcessId)
        lpdwProcessId1 = (*env)->GetIntArrayElements(env, lpdwProcessId, NULL);

    rc = (jint) GetWindowThreadProcessId((HWND)hWnd, lpdwProcessId1);

    if (lpdwProcessId)
        (*env)->ReleaseIntArrayElements(env, lpdwProcessId, (jint *)lpdwProcessId1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GlobalAlloc
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GlobalAlloc
  (JNIEnv *env,  jclass that, jint uFlags, jint dwBytes)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GlobalAlloc\n");
#endif
    return (jint) GlobalAlloc(uFlags, dwBytes);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GlobalFree
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GlobalFree
  (JNIEnv *env,  jclass that, jint hMem)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GlobalFree: handle = %d\n", hMem);
#endif
    return (jint) GlobalFree((HANDLE)hMem);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GlobalLock
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GlobalLock
  (JNIEnv *env,  jclass that, jint hMem)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GlobalLock\n");
#endif
    return (jint) GlobalLock((HANDLE)hMem);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GlobalSize
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GlobalSize
  (JNIEnv *env,  jclass that, jint hMem)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GlobalSize\n");
#endif
    return (jint) GlobalSize((HANDLE)hMem);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GlobalUnlock
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_GlobalUnlock
  (JNIEnv *env,  jclass that, jint hMem)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GlobalUnlock\n");
#endif
    return (jboolean) GlobalUnlock((HANDLE)hMem);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    HeapAlloc
 * Signature: (III)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_HeapAlloc
  (JNIEnv *env, jclass that, jint hHeap, jint dwFlags, jint dwBytes)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "HeapAlloc\n");
#endif

    return (jint) HeapAlloc((HANDLE)hHeap, (DWORD)dwFlags, (DWORD)dwBytes);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    HeapFree
 * Signature: (III)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_HeapFree
  (JNIEnv *env, jclass that, jint hHeap, jint dwFlags, jint lpMenu)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "HeapFree\n");
#endif

    return (jboolean) HeapFree((HANDLE)hHeap, (DWORD)dwFlags, (LPVOID)lpMenu);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    HideCaret
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_HideCaret
  (JNIEnv *env, jclass that, jint hWnd)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "HideCaret\n");
#endif

    return (jboolean) HideCaret((HWND)hWnd);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ImageList_AddMasked
 * Signature: (III)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_ImageList_1AddMasked
  (JNIEnv *env, jclass that, jint himl, jint hbmImage, jint crMask)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "ImageList_AddMasked\n");
#endif

    return (jint)ImageList_AddMasked((HIMAGELIST)himl, (HBITMAP)hbmImage, (COLORREF)crMask);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ImageList_Create
 * Signature: (IIIII)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_ImageList_1Create
  (JNIEnv *env, jclass that, jint cx, jint cy, jint flags, jint cInitial, jint cGrow)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "ImageList_Create\n");
#endif

    return (jint)ImageList_Create(cx, cy, flags, cInitial, cGrow);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ImageList_Destroy
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_ImageList_1Destroy
  (JNIEnv *env, jclass that, jint himl)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "ImageList_Destroy\n");
#endif

    return (jboolean)ImageList_Destroy((HIMAGELIST)himl);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ImageList_GetIcon
 * Signature: (III)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_ImageList_1GetIcon
  (JNIEnv *env, jclass that, jint himl, jint i, jint flags)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "ImageList_GetIcon\n");
#endif

    return (jint)ImageList_GetIcon((HIMAGELIST)himl, i, flags);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ImageList_GetIconSize
 * Signature: (I[I[I)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_ImageList_1GetIconSize
  (JNIEnv *env, jclass that, jint himl, jintArray cx, jintArray cy)
{
    int FAR *lpcx1=NULL,*lpcy1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "ImageList_GetIconSize\n");
#endif

    if (cx)
        lpcx1 = (int FAR *)(*env)->GetIntArrayElements(env, cx, NULL);
    if (cy)
        lpcy1 = (int FAR *)(*env)->GetIntArrayElements(env, cy, NULL);

    rc = (jboolean) ImageList_GetIconSize((HIMAGELIST)himl, lpcx1, lpcy1);

    if (cx)
        (*env)->ReleaseIntArrayElements(env, cx, (jint *)lpcx1, 0);
    if (cy)
        (*env)->ReleaseIntArrayElements(env, cy, (jint *)lpcy1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ImageList_GetImageCount
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_ImageList_1GetImageCount
  (JNIEnv *env, jclass that, jint himl)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "ImageList_GetImageCount\n");
#endif

    return (jint)ImageList_GetImageCount((HIMAGELIST)himl);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ImageList_Remove
 * Signature: (II)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_ImageList_1Remove
   (JNIEnv *env, jclass that, jint himl, jint i)
{
#ifdef DEBUG_CALL_PRINTS
	fprintf(stderr, "ImageList_Remove\n");
#endif

	return (jboolean)ImageList_Remove((HIMAGELIST)himl, i);
}


/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ImageList_Replace
 * Signature: (IIII)Z
 */
JNIEXPORT boolean JNICALL Java_org_eclipse_swt_internal_win32_OS_ImageList_1Replace
   (JNIEnv *env, jclass that, jint himl, jint i, jint hbmImage, jint hbmMask)
{
#ifdef DEBUG_CALL_PRINTS
	fprintf(stderr, "ImageList_Replace\n");
#endif

	return (boolean)ImageList_Replace((HIMAGELIST)himl, i, (HBITMAP)hbmImage, (HBITMAP)hbmMask);
}


/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ImageList_ReplaceIcon
 * Signature: (III)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_ImageList_1ReplaceIcon
   (JNIEnv *env, jclass that, jint himl, jint i, jint hicon)
{
#ifdef DEBUG_CALL_PRINTS
	fprintf(stderr, "ImageList_ReplaceIcon\n");
#endif

	return (jint)ImageList_ReplaceIcon((HIMAGELIST)himl, i, (HICON)hicon);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ImageList_SetIconSize
 * Signature: (III)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_ImageList_1SetIconSize
  (JNIEnv *env, jclass that, jint himl, jint cx, jint cy)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "ImageList_SetIconSize\n");
#endif

    return (jboolean)ImageList_SetIconSize((HIMAGELIST)himl, cx, cy);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ImmAssociateContext
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_ImmAssociateContext
  (JNIEnv *env, jclass that, jint hWnd, jint hIMC)
{
    return (jint) ImmAssociateContext((HWND)hWnd, (HIMC)hIMC);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ImmCreateContext
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_ImmCreateContext
  (JNIEnv *env, jclass that)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "ImmCreateContext\n");
#endif
    return (jint) ImmCreateContext();
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ImmDestroyContext
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_ImmDestroyContext
  (JNIEnv *env, jclass that, jint hIMC)
{
    return (jboolean) ImmDestroyContext((HIMC)hIMC);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ImmGetContext
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_ImmGetContext
  (JNIEnv *env, jclass that, jint hWnd)
{
    return (jint) ImmGetContext((HWND)hWnd);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ImmGetConversionStatus
 * Signature: (I[I[I)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_ImmGetConversionStatus
  (JNIEnv *env, jclass that, jint hIMC, jintArray lpfdwConversion, jintArray lpfdwSentence)
{
    LPDWORD lpfdwConversion1=NULL, lpfdwSentence1=NULL;
    jboolean rc;
    
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "ImmGetConversionStatus\n");
#endif
    
    if (lpfdwConversion)
        lpfdwConversion1 = (LPDWORD)(*env)->GetIntArrayElements(env, lpfdwConversion, NULL);

    if (lpfdwSentence)
        lpfdwSentence1 = (LPDWORD)(*env)->GetIntArrayElements(env, lpfdwSentence, NULL);

    rc = (jboolean) ImmGetConversionStatus((HIMC)hIMC, lpfdwConversion1, lpfdwSentence1);
    
    if (lpfdwConversion)
        (*env)->ReleaseIntArrayElements(env, lpfdwConversion, (jint *)lpfdwConversion1, 0);

    if (lpfdwSentence)
        (*env)->ReleaseIntArrayElements(env, lpfdwSentence, (jint *)lpfdwSentence1, 0);
        
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ImmGetDefaultIMEWnd
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_ImmGetDefaultIMEWnd
  (JNIEnv *env, jclass that, jint hWnd)
{
    return (jint) ImmGetDefaultIMEWnd((HWND)hWnd);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ImmGetCompositionFontA
 * Signature: (ILorg/eclipse/swt/internal/win32/LOGFONT;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_ImmGetCompositionFontA
  (JNIEnv *env, jclass that, jint hIMC, jobject lplf)
{
	DECL_GLOB(pGlob)
    LOGFONTA logfont, *lplf1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "ImmGetCompositionFontA\n");
#endif
    if (lplf) {
        lplf1 = &logfont;
        cacheLogfontFids(env, lplf, &PGLOB(LogfontFc));
        getLogfontFieldsA(env, lplf, lplf1, &PGLOB(LogfontFc));
    }
    rc = (jboolean) ImmGetCompositionFontA((HIMC)hIMC, lplf1);
    if (lplf) {
        setLogfontFieldsA(env, lplf, lplf1, &PGLOB(LogfontFc));
    }
    return rc;
}
/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ImmGetCompositionFontW
 * Signature: (ILorg/eclipse/swt/internal/win32/LOGFONT;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_ImmGetCompositionFontW
   (JNIEnv *env, jclass that, jint hIMC, jobject lplf)
{
	DECL_GLOB(pGlob)
	LOGFONTW logfont, *lplf1=NULL;
	jboolean rc;

#ifdef DEBUG_CALL_PRINTS
	fprintf(stderr, "ImmGetCompositionFontW\n");
#endif
	if (lplf) {
		lplf1 = &logfont;
		cacheLogfontFids(env, lplf, &PGLOB(LogfontFc));
		getLogfontFieldsW(env, lplf, lplf1, &PGLOB(LogfontFc));
	}
	rc = (jboolean) ImmGetCompositionFontW((HIMC)hIMC, lplf1);
	if (lplf) {
		setLogfontFieldsW(env, lplf, lplf1, &PGLOB(LogfontFc));
	}
	return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ImmGetCompositionStringA
 * Signature: (II[BI)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_ImmGetCompositionStringA
  (JNIEnv *env, jclass that, jint hIMC, jint dwIndex, jbyteArray lpBuf, jint dwBufLen)
{
    jbyte *lpBuf1=NULL;
    jint rc;
    
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "ImmGetCompositionStringA\n");
#endif
    
    if (lpBuf)
        lpBuf1 = (LPSTR)(*env)->GetByteArrayElements(env, lpBuf, NULL);
        
    rc = (jint) ImmGetCompositionStringA((HIMC)hIMC, dwIndex, (LPSTR)lpBuf1, dwBufLen);
    
    if (lpBuf)
        (*env)->ReleaseByteArrayElements(env, lpBuf, lpBuf1, 0);
        
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ImmGetCompositionStringW
 * Signature: (II[CI)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_ImmGetCompositionStringW
   (JNIEnv *env, jclass that, jint hIMC, jint dwIndex, jcharArray lpBuf, jint dwBufLen)
{
	jchar *lpBuf1=NULL;
	jint rc;

#ifdef DEBUG_CALL_PRINTS
	fprintf(stderr, "ImmGetCompositionStringW\n");
#endif

	if (lpBuf)
		lpBuf1 = (*env)->GetCharArrayElements(env, lpBuf, NULL);

	rc = (jint) ImmGetCompositionStringW((HIMC)hIMC, dwIndex, (LPWSTR)lpBuf1, dwBufLen);

	if (lpBuf)
		(*env)->ReleaseCharArrayElements(env, lpBuf, lpBuf1, 0);

	return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ImmSetCompositionFontA
 * Signature: (ILorg/eclipse/swt/internal/win32/LOGFONT;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_ImmSetCompositionFontA
  (JNIEnv *env, jclass that, jint hIMC, jobject lplf)
{
	DECL_GLOB(pGlob)
    LOGFONT logfont, *lplf1=NULL;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "ImmSetCompositionFontA\n");
#endif
    if (lplf) {
        lplf1 = &logfont;
        cacheLogfontFids(env, lplf, &PGLOB(LogfontFc));
        getLogfontFieldsA(env, lplf, lplf1, &PGLOB(LogfontFc));
    }
    return (jboolean) ImmSetCompositionFontA((HIMC)hIMC, lplf1);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ImmSetCompositionFontW
 * Signature: (ILorg/eclipse/swt/internal/win32/LOGFONT;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_ImmSetCompositionFontW
  (JNIEnv *env, jclass that, jint hIMC, jobject lplf)
{
	DECL_GLOB(pGlob)
    LOGFONTW logfont, *lplf1=NULL;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "ImmSetCompositionFontW\n");
#endif
    if (lplf) {
        lplf1 = &logfont;
        cacheLogfontFids(env, lplf, &PGLOB(LogfontFc));
        getLogfontFieldsW(env, lplf, lplf1, &PGLOB(LogfontFc));
    }
    return (jboolean) ImmSetCompositionFontW((HIMC)hIMC, lplf1);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ImmGetOpenStatus
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_ImmGetOpenStatus
  (JNIEnv *env, jclass that, jint hIMC)
{
    return (jboolean) ImmGetOpenStatus((HIMC) hIMC);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ImmReleaseContext
 * Signature: (II)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_ImmReleaseContext
  (JNIEnv *env, jclass that, jint hWnd, jint hIMC)
{
    return (jboolean) ImmReleaseContext((HWND)hWnd, (HIMC)hIMC);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ImmSetCompositionWindow
 * Signature: (ILorg/eclipse/swt/internal/win32/COMPOSITIONFORM;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_ImmSetCompositionWindow
  (JNIEnv *env, jclass that, jint hIMC, jobject lpCompForm)
{
	DECL_GLOB(pGlob)
     
    COMPOSITIONFORM compositionform, *lpCompForm1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "ImmSetCompositionWindow\n");
#endif
    if (lpCompForm) {
        lpCompForm1 = &compositionform;
        cacheCompositionformFids(env, lpCompForm, &PGLOB(CompositionformFc));
        getCompositionformFields(env, lpCompForm, lpCompForm1, &PGLOB(CompositionformFc));
    }
    rc = (jboolean) ImmSetCompositionWindow((HIMC)hIMC, lpCompForm1);
    if (lpCompForm) {
        setCompositionformFields(env, lpCompForm, lpCompForm1, &PGLOB(CompositionformFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ImmSetConversionStatus
 * Signature: (III)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_ImmSetConversionStatus
  (JNIEnv *env, jclass that, jint hIMC, jint fdwConversion, jint dwSentence)
{
    return (jboolean) ImmSetConversionStatus((HIMC)hIMC, fdwConversion, dwSentence);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ImmSetOpenStatus
 * Signature: (IZ)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_ImmSetOpenStatus
  (JNIEnv *env, jclass that, jint hIMC, jboolean fOpen)
{
    return (jboolean) ImmSetOpenStatus((HIMC) hIMC, fOpen);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    InitCommonControls
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_win32_OS_InitCommonControls
  (JNIEnv *env, jclass that)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "InitCommonControls\n");
#endif

    InitCommonControls();
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    InitCommonControlsEx
 * Signature: (Lorg/eclipse/swt/internal/win32/INITCOMMONCONTROLSEX;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_InitCommonControlsEx
  (JNIEnv *env, jclass that, jobject lpInitCtrls)
{
	DECL_GLOB(pGlob)
    INITCOMMONCONTROLSEX initCtrl, *lpInitCtrls1=NULL;
    jboolean rc;

    if (lpInitCtrls) {
        lpInitCtrls1 = &initCtrl;
        cacheInitcommoncontrolsexFids(env, lpInitCtrls, &PGLOB(InitcommoncontrolsexFc));
        getInitcommoncontrolsexFields(env, lpInitCtrls, lpInitCtrls1, &PGLOB(InitcommoncontrolsexFc));
    }
    rc = (jboolean) InitCommonControlsEx(lpInitCtrls1);
    if (lpInitCtrls) {
        setInitcommoncontrolsexFields(env, lpInitCtrls, lpInitCtrls1, &PGLOB(InitcommoncontrolsexFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    InvalidateRect
 * Signature: (ILorg/eclipse/swt/internal/win32/RECT;Z)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_InvalidateRect
  (JNIEnv *env, jclass that, jint hWnd, jobject lpRect, jboolean hErase)
{
	DECL_GLOB(pGlob)
    RECT rect, *lpRect1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "InvalidateRect\n");
#endif

    if (lpRect) {
        lpRect1 = &rect;
        cacheRectFids(env, lpRect, &PGLOB(RectFc));
        getRectFields(env, lpRect, lpRect1, &PGLOB(RectFc));
    }
    rc = (jboolean) InvalidateRect((HWND)hWnd, lpRect1, hErase);
    if (lpRect) {
        setRectFields(env, lpRect, lpRect1, &PGLOB(RectFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    IsDBCSLeadByte
 * Signature: (B)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_IsDBCSLeadByte
  (JNIEnv *env, jclass that, jbyte TestChar)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "IsDBCSLeadByte\n");
#endif
    return (jboolean) IsDBCSLeadByte(TestChar);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    IsWindow
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_IsWindow
  (JNIEnv *env, jclass that, jint hWnd)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "IsWindow\n");
#endif

    return (jboolean) IsWindow((HWND)hWnd);
}


/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    IsWindowEnabled
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_IsWindowEnabled
  (JNIEnv *env, jclass that, jint hWnd)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "IsWindowEnabled\n");
#endif

    return (jboolean) IsWindowEnabled((HWND)hWnd);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    IsWindowVisible
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_IsWindowVisible
  (JNIEnv *env, jclass that, jint hWnd)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "IsWindowVisible\n");
#endif

    return (jboolean) IsWindowVisible((HWND)hWnd);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    LoadBitmapA
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_LoadBitmapA__II
  (JNIEnv *env, jclass that, jint hInstance, jint lpBitmapName)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "LoadBitmapA__II\n");
#endif

    return (jint) LoadBitmapA((HINSTANCE)hInstance, (LPSTR)lpBitmapName);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    LoadBitmapW
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_LoadBitmapW__II
  (JNIEnv *env, jclass that, jint hInstance, jint lpBitmapName)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "LoadBitmapW__II\n");
#endif

    return (jint) LoadBitmapW((HINSTANCE)hInstance, (LPWSTR)lpBitmapName);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    LoadCursorA
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_LoadCursorA
  (JNIEnv *env, jclass that, jint hInstance, jint lpCursorName)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "LoadCursorA\n");
#endif

    return (jint) LoadCursorA((HINSTANCE)hInstance, (LPSTR)lpCursorName);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    LoadCursorW
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_LoadCursorW
  (JNIEnv *env, jclass that, jint hInstance, jint lpCursorName)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "LoadCursorW\n");
#endif

    return (jint) LoadCursorW((HINSTANCE)hInstance, (LPWSTR)lpCursorName);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    LoadIconA
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_LoadIconA
  (JNIEnv *env, jclass that, jint hInstance, jint lpIconName)
{    
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "LoadIconA\n");
#endif

    return (jint) LoadIconA((HINSTANCE)hInstance, (LPSTR)lpIconName);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    LoadIconW
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_LoadIconW
  (JNIEnv *env, jclass that, jint hInstance, jint lpIconName)
{    
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "LoadIconW\n");
#endif

    return (jint) LoadIconW((HINSTANCE)hInstance, (LPWSTR)lpIconName);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    LoadLibraryA
 * Signature: ([B)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_LoadLibraryA
  (JNIEnv *env, jclass that, jbyteArray lpLibFileName)
{
    jbyte* lpLibFileName1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "LoadLibraryA\n");
#endif

    if (lpLibFileName)
        lpLibFileName1 = (*env)->GetByteArrayElements(env, lpLibFileName, NULL);

    rc = (jint) LoadLibraryA((LPSTR)lpLibFileName1);

    if (lpLibFileName)
        (*env)->ReleaseByteArrayElements(env, lpLibFileName, lpLibFileName1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    LoadLibraryW
 * Signature: ([C)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_LoadLibraryW
  (JNIEnv *env, jclass that, jcharArray lpLibFileName)
{
    jchar* lpLibFileName1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "LoadLibraryW\n");
#endif

    if (lpLibFileName)
        lpLibFileName1 = (*env)->GetCharArrayElements(env, lpLibFileName, NULL);

    rc = (jint) LoadLibraryW((LPWSTR)lpLibFileName1);

    if (lpLibFileName)
        (*env)->ReleaseCharArrayElements(env, lpLibFileName, lpLibFileName1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    MapVirtualKeyA
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_MapVirtualKeyA
  (JNIEnv *env, jclass that, jint uCode, jint uMapType)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "MapVirtualKeyA\n");
#endif

    return (jint) MapVirtualKeyA(uCode, uMapType);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    MapVirtualKeyW
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_MapVirtualKeyW
  (JNIEnv *env, jclass that, jint uCode, jint uMapType)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "MapVirtualKeyW\n");
#endif

    return (jint) MapVirtualKeyW(uCode, uMapType);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    MapWindowPoints
 * Signature: (IILorg/eclipse/swt/internal/win32/POINT;I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_MapWindowPoints__IILorg_eclipse_swt_internal_win32_POINT_2I
  (JNIEnv *env, jclass that, jint hWndFrom, jint hWndTo, jobject lpPoints, jint cPoints)
{
	DECL_GLOB(pGlob)
    POINT point, *lpPoints1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "MapWindowPoints__IILorg_eclipse_swt_internal_win32_POINT_2I\n");
#endif

    if (lpPoints) {
        lpPoints1 = &point;
        cachePointFids(env, lpPoints, &PGLOB(PointFc));
        getPointFields(env, lpPoints, lpPoints1, &PGLOB(PointFc));
    }
    rc = (jint) MapWindowPoints((HWND)hWndFrom, (HWND)hWndTo, (LPPOINT)lpPoints1, cPoints);

    if (lpPoints) {
        setPointFields(env, lpPoints, lpPoints1, &PGLOB(PointFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    MapWindowPoints
 * Signature: (IILorg/eclipse/swt/internal/win32/RECT;I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_MapWindowPoints__IILorg_eclipse_swt_internal_win32_RECT_2I
  (JNIEnv *env, jclass that, jint hWndFrom, jint hWndTo, jobject lpPoints, jint cPoints)
{
	DECL_GLOB(pGlob)
    RECT rect, *lpPoints1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "MapWindowPoints__IILorg_eclipse_swt_internal_win32_RECT_2I\n");
#endif

    if (lpPoints) {
        lpPoints1 = &rect;
        cacheRectFids(env, lpPoints, &PGLOB(RectFc));
        getRectFields(env, lpPoints, lpPoints1, &PGLOB(RectFc));
    }
    rc = (jint) MapWindowPoints((HWND)hWndFrom, (HWND)hWndTo, (LPPOINT)lpPoints1, cPoints);

    if (lpPoints) {
        setRectFields(env, lpPoints, lpPoints1, &PGLOB(RectFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    MessageBeep
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_MessageBeep
  (JNIEnv *env, jclass that, jint uType)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "MessageBeep\n");
#endif

    return (jboolean) MessageBeep(uType);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    MessageBoxA
 * Signature: (I[B[BI)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_MessageBoxA
  (JNIEnv *env, jclass that, jint hWnd, jbyteArray lpText, jbyteArray lpCaption, jint uType)
{
    jbyte* lpText1=NULL, *lpCaption1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "MessageBoxA\n");
#endif

    if (lpText)
        lpText1 = (*env)->GetByteArrayElements(env, lpText, NULL);
    if (lpCaption)
        lpCaption1 = (*env)->GetByteArrayElements(env, lpCaption, NULL);

    rc = (jint) MessageBoxA((HWND)hWnd, (LPSTR)lpText1, (LPSTR)lpCaption1, uType);

    if (lpText)
        (*env)->ReleaseByteArrayElements(env, lpText, lpText1, 0);
    if (lpCaption)
        (*env)->ReleaseByteArrayElements(env, lpCaption, lpCaption1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    MessageBoxW
 * Signature: (I[C[CI)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_MessageBoxW
  (JNIEnv *env, jclass that, jint hWnd, jcharArray lpText, jcharArray lpCaption, jint uType)
{
    jchar* lpText1=NULL, *lpCaption1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "MessageBoxW\n");
#endif

    if (lpText)
        lpText1 = (*env)->GetCharArrayElements(env, lpText, NULL);
    if (lpCaption)
        lpCaption1 = (*env)->GetCharArrayElements(env, lpCaption, NULL);

    rc = (jint) MessageBoxW((HWND)hWnd, (LPWSTR)lpText1, (LPWSTR)lpCaption1, uType);

    if (lpText)
        (*env)->ReleaseCharArrayElements(env, lpText, lpText1, 0);
    if (lpCaption)
        (*env)->ReleaseCharArrayElements(env, lpCaption, lpCaption1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    MoveMemory
 * Signature: ([BII)V
 */
JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_win32_OS_MoveMemory___3BII
  (JNIEnv *env, jclass that, jbyteArray Destination, jint Source, jint Length)
{
    PVOID Destination1=NULL;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "OS_MoveMemory___3BII\n");
#endif

    if (Destination)
        Destination1 = (PVOID)(*env)->GetByteArrayElements(env, Destination, NULL);

    MoveMemory(Destination1, (CONST VOID *)Source, Length);

    if (Destination)
        (*env)->ReleaseByteArrayElements(env, Destination, (jbyte *)Destination1, 0);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    MoveMemory
 * Signature: ([BLorg/eclipse/swt/internal/win32/ACCEL;I)V
 */
JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_win32_OS_MoveMemory___3BLorg_eclipse_swt_internal_win32_ACCEL_2I
  (JNIEnv *env, jclass that, jbyteArray Destination, jobject lpSource, jint Length)
{
	DECL_GLOB(pGlob)
    PVOID Destination1=NULL;
    ACCEL source, *lpSource1=NULL;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "MoveMemory___3BLorg_eclipse_swt_internal_win32_ACCEL_2I\n");
#endif

    if (lpSource) {
        lpSource1 = &source;
        cacheAccelFids(env, lpSource, &PGLOB(AccelFc));
        getAccelFields(env, lpSource, lpSource1, &PGLOB(AccelFc));
    }

    if (Destination)
        Destination1 = (PVOID)(*env)->GetByteArrayElements(env, Destination, NULL);

    MoveMemory(Destination1, (CONST VOID *)lpSource1, Length);

    if (Destination)
        (*env)->ReleaseByteArrayElements(env, Destination, (jbyte *)Destination1, 0);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    MoveMemory
 * Signature: ([III)V
 */
JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_win32_OS_MoveMemory___3III
  (JNIEnv *env, jclass that, jintArray lpDestination, jint Source, jint Length)
{
    jint *lpDestination1=NULL;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "MoveMemory___3III\n");
#endif

    if (lpDestination)
        lpDestination1 = (*env)->GetIntArrayElements(env, lpDestination, NULL);

    MoveMemory((PVOID)lpDestination1, (PVOID)Source, Length);

    if (lpDestination)
        (*env)->ReleaseIntArrayElements(env, lpDestination, lpDestination1, 0);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    MoveMemory
 * Signature: (Lorg/eclipse/swt/internal/win32/HDITEM;II)V
 */
JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_win32_OS_MoveMemory__Lorg_eclipse_swt_internal_win32_HDITEM_2II
  (JNIEnv *env, jclass that, jobject Destination, jint Source, jint Length)
{
	DECL_GLOB(pGlob)
    HDITEM hditem, *Destination1=NULL;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "MoveMemory__Lorg_eclipse_swt_internal_win32_HDITEM_2II\n");
#endif

    MoveMemory((PVOID)&hditem, (CONST VOID *)Source, Length);

    if (Destination) {
        Destination1 = &hditem;
        cacheHditemFids(env, Destination, &PGLOB(HditemFc));
        setHditemFields(env, Destination, Destination1, &PGLOB(HditemFc));
    }
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    MoveMemoryA
 * Signature: (Lorg/eclipse/swt/internal/win32/LOGFONT;II)V
 */
JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_win32_OS_MoveMemoryA__Lorg_eclipse_swt_internal_win32_LOGFONT_2II
  (JNIEnv *env, jclass that, jobject Destination, jint Source, jint Length)
{
	DECL_GLOB(pGlob)
    LOGFONT logfont, *lpDestination1=NULL;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "MoveMemoryA__Lorg_eclipse_swt_internal_win32_LOGFONT_2II\n");
#endif

    MoveMemory((PVOID)&logfont, (CONST VOID *)Source, Length);

    if (Destination) {
        lpDestination1 = &logfont;
        cacheLogfontFids(env, Destination, &PGLOB(LogfontFc));
        setLogfontFieldsA(env, Destination, lpDestination1, &PGLOB(LogfontFc));
    }
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    MoveMemoryW
 * Signature: (Lorg/eclipse/swt/internal/win32/LOGFONT;II)V
 */
JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_win32_OS_MoveMemoryW__Lorg_eclipse_swt_internal_win32_LOGFONT_2II
  (JNIEnv *env, jclass that, jobject Destination, jint Source, jint Length)
{
	DECL_GLOB(pGlob)
    LOGFONTW logfont, *lpDestination1=NULL;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "MoveMemoryW__Lorg_eclipse_swt_internal_win32_LOGFONT_2II\n");
#endif

    MoveMemory((PVOID)&logfont, (CONST VOID *)Source, Length);

    if (Destination) {
        lpDestination1 = &logfont;
        cacheLogfontFids(env, Destination, &PGLOB(LogfontFc));
        setLogfontFieldsW(env, Destination, lpDestination1, &PGLOB(LogfontFc));
    }
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    MoveMemory
 * Signature: (Lorg/eclipse/swt/internal/win32/NMHEADER;II)V
 */
JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_win32_OS_MoveMemory__Lorg_eclipse_swt_internal_win32_NMHEADER_2II
  (JNIEnv *env, jclass that, jobject Destination, jint Source, jint Length)
{
	DECL_GLOB(pGlob)
    NMHEADER nmheader, *Destination1=NULL;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "MoveMemory__Lorg_eclipse_swt_internal_win32_NMHEADER_2II\n");
#endif

    MoveMemory((PVOID)&nmheader, (CONST VOID *)Source, Length);

    if (Destination) {
        Destination1 = &nmheader;
        cacheNmheaderFids(env, Destination, &PGLOB(NmheaderFc));
        setNmheaderFields(env, Destination, Destination1, &PGLOB(NmheaderFc));
    }
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    MoveMemory
 * Signature: (Lorg/eclipse/swt/internal/win32/NMLISTVIEW;II)V
 */
JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_win32_OS_MoveMemory__Lorg_eclipse_swt_internal_win32_NMLISTVIEW_2II
  (JNIEnv *env, jclass that, jobject Destination, jint Source, jint Length)
{
	DECL_GLOB(pGlob)
    NMLISTVIEW nmlistview, *lpDestination1=NULL;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "MoveMemory__Lorg_eclipse_swt_internal_win32_NMLISTVIEW_2II\n");
#endif

       MoveMemory((PVOID)&nmlistview, (CONST VOID *)Source, Length);
    if (Destination) {
           lpDestination1=&nmlistview;
        cacheNmlistviewFids(env, Destination, &PGLOB(NmlistviewFc));
        setNmlistviewFields(env, Destination, lpDestination1, &PGLOB(NmlistviewFc));
    }
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    MoveMemory
 * Signature: (I[BI)V
 */
JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_win32_OS_MoveMemory__I_3BI
  (JNIEnv *env, jclass that, jint Destination, jbyteArray Source, jint Length)
{
    CONST VOID *Source1=NULL;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "MoveMemory__I_3BI\n");
#endif

    if (Source)
        Source1 = (PVOID)(*env)->GetByteArrayElements(env, Source, NULL);

    MoveMemory((PVOID)Destination, Source1, Length);

    if (Source)
        (*env)->ReleaseByteArrayElements(env, Source, (jbyte *)Source1, 0);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    MoveMemory
 * Signature: (I[CI)V
 */
JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_win32_OS_MoveMemory__I_3CI
  (JNIEnv * env, jclass that, jint Destination, jcharArray Source, jint Length)
{
    CONST VOID *Source1=NULL;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "MoveMemory__I_3CI\n");
#endif

    if (Source)
        Source1 = (PVOID)(*env)->GetCharArrayElements(env, Source, NULL);

    MoveMemory((PVOID)Destination, Source1, Length);

    if (Source)
        (*env)->ReleaseCharArrayElements(env, Source, (jchar *)Source1, 0);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    MoveMemory
 * Signature: (I[II)V
 */
JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_win32_OS_MoveMemory__I_3II
  (JNIEnv *env, jclass that, jint Destination, jintArray Source, jint Length)
{
    CONST VOID *Source1=NULL;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "MoveMemory__I_3II\n");
#endif

    if (Source)
        Source1 = (CONST VOID *)(*env)->GetIntArrayElements(env, Source, NULL);

    MoveMemory((PVOID)Destination, Source1, Length);

    if (Source)
        (*env)->ReleaseIntArrayElements(env, Source, (jint *)Source1, 0);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    MoveMemoryA
 * Signature: (ILorg/eclipse/swt/internal/win32/LOGFONT;I)V
 */
JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_win32_OS_MoveMemoryA__ILorg_eclipse_swt_internal_win32_LOGFONT_2I
  (JNIEnv *env, jclass that, jint Destination, jobject Source, jint Length)
{
	DECL_GLOB(pGlob)
    LOGFONT logfont, *Source1=NULL;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "MoveMemoryA__ILorg_eclipse_swt_internal_win32_LOGFONT_2I\n");
#endif
    if (Source) {
        Source1 = &logfont;
        cacheLogfontFids(env, Source, &PGLOB(LogfontFc));
        getLogfontFieldsA(env, Source, Source1, &PGLOB(LogfontFc));
    }
    MoveMemory((PVOID)Destination, (CONST VOID *)Source1, Length);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    MoveMemoryW
 * Signature: (ILorg/eclipse/swt/internal/win32/LOGFONT;I)V
 */
JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_win32_OS_MoveMemoryW__ILorg_eclipse_swt_internal_win32_LOGFONT_2I
  (JNIEnv *env, jclass that, jint Destination, jobject Source, jint Length)
{
	DECL_GLOB(pGlob)
    LOGFONTW logfont, *Source1=NULL;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "MoveMemoryW__ILorg_eclipse_swt_internal_win32_LOGFONT_2I\n");
#endif
    if (Source) {
        Source1 = &logfont;
        cacheLogfontFids(env, Source, &PGLOB(LogfontFc));
        getLogfontFieldsW(env, Source, Source1, &PGLOB(LogfontFc));
    }
    MoveMemory((PVOID)Destination, (CONST VOID *)Source1, Length);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    MoveMemory
 * Signature: (Lorg/eclipse/swt/internal/win32/MEASUREITEMSTRUCT;II)V
 */
JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_win32_OS_MoveMemory__Lorg_eclipse_swt_internal_win32_MEASUREITEMSTRUCT_2II
  (JNIEnv *env, jclass that, jobject Destination, jint Source, jint Length)
{
	DECL_GLOB(pGlob)
    MEASUREITEMSTRUCT measureitemstruct, *lpDestination1=NULL;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "MoveMemory__Lorg_eclipse_swt_internal_win32_MEASUREITEMSTRUCT_2II\n");
#endif

    MoveMemory((PVOID)&measureitemstruct, (CONST VOID *)Source, Length);

    if (Destination) {
        lpDestination1 = &measureitemstruct;
        cacheMeasureitemstructFids(env, Destination, &PGLOB(MeasureitemstructFc));
        setMeasureitemstructFields(env, Destination, lpDestination1, &PGLOB(MeasureitemstructFc));
    }
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    MoveMemory
 * Signature: (ILorg/eclipse/swt/internal/win32/MEASUREITEMSTRUCT;I)V
 */
JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_win32_OS_MoveMemory__ILorg_eclipse_swt_internal_win32_MEASUREITEMSTRUCT_2I
  (JNIEnv *env, jclass that, jint Destination, jobject Source, jint Length)
{
	DECL_GLOB(pGlob)
    MEASUREITEMSTRUCT measureitemstruct, *lpSource1=NULL;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "MoveMemory__ILorg_eclipse_swt_internal_win32_MEASUREITEMSTRUCT_2I\n");
#endif

    if (Source) {
        lpSource1 = &measureitemstruct;
        cacheMeasureitemstructFids(env, Source, &PGLOB(MeasureitemstructFc));
        getMeasureitemstructFields(env, Source, lpSource1, &PGLOB(MeasureitemstructFc));
    }
    MoveMemory((PVOID)Destination, lpSource1, Length);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    MoveMemory
 * Signature: (ILorg/eclipse/swt/internal/win32/RECT;I)V
 */
JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_win32_OS_MoveMemory__ILorg_eclipse_swt_internal_win32_RECT_2I
  (JNIEnv *env, jclass that, jint Destination, jobject Source, jint Length)
{
	DECL_GLOB(pGlob)
    RECT rect, *lpSource1=NULL;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "MoveMemory__ILorg_eclipse_swt_internal_win32_RECT_2I\n");
#endif

    if (Source) {
        lpSource1 = &rect;
        cacheRectFids(env, Source, &PGLOB(RectFc));
        getRectFields(env, Source, lpSource1, &PGLOB(RectFc));
    }
    MoveMemory((PVOID)Destination, lpSource1, Length);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    MoveMemory
 * Signature: (Lorg/eclipse/swt/internal/win32/DRAWITEMSTRUCT;II)V
 */
JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_win32_OS_MoveMemory__Lorg_eclipse_swt_internal_win32_DRAWITEMSTRUCT_2II
  (JNIEnv *env, jclass that, jobject Destination, jint Source, jint Length)
{
	DECL_GLOB(pGlob)
    DRAWITEMSTRUCT drawItem, *lpDestination1=NULL;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "MoveMemory__Lorg_eclipse_swt_internal_win32_DRAWITEMSTRUCT_2II\n");
#endif

    if (Source) {
           lpDestination1=&drawItem;
    }

       MoveMemory((PVOID)lpDestination1, (CONST VOID *)Source, Length);

    if (Destination) {
        cacheDrawitemstructFids(env, Destination, &PGLOB(DrawitemstructFc));
        setDrawitemstructFields(env, Destination, lpDestination1, &PGLOB(DrawitemstructFc));
    }
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    MoveMemory
 * Signature: (Lorg/eclipse/swt/internal/win32/NMHDR;II)V
 */
JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_win32_OS_MoveMemory__Lorg_eclipse_swt_internal_win32_NMHDR_2II
  (JNIEnv *env, jclass that, jobject Destination, jint Source, jint Length)
{
	DECL_GLOB(pGlob)
    NMHDR nmhdr, *lpDestination1=NULL;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "MoveMemory__Lorg_eclipse_swt_internal_win32_NMHDR_2II\n");
#endif

       MoveMemory((PVOID)&nmhdr, (CONST VOID *)Source, Length);

    if (Destination) {
        lpDestination1 = &nmhdr;
        cacheNmhdrFids(env, Destination, &PGLOB(NmhdrFc));
        setNmhdrFields(env, Destination, lpDestination1, &PGLOB(NmhdrFc));
    }
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    MoveMemory
 * Signature: (Lorg/eclipse/swt/internal/win32/NMTOOLBAR;II)V
 */
JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_win32_OS_MoveMemory__Lorg_eclipse_swt_internal_win32_NMTOOLBAR_2II
  (JNIEnv *env, jclass that, jobject Destination, jint Source, jint Length)
{
	DECL_GLOB(pGlob)
    NMTOOLBAR nmtoolbar, *lpDestination1=NULL;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "MoveMemory__Lorg_eclipse_swt_internal_win32_NMTOOLBAR_2II\n");
#endif

       MoveMemory((PVOID)&nmtoolbar, (CONST VOID *)Source, Length);

    if (Destination) {
        lpDestination1 = &nmtoolbar;
        cacheNmtoolbarFids(env, Destination, &PGLOB(NmtoolbarFc));
        setNmtoolbarFields(env, Destination, lpDestination1, &PGLOB(NmtoolbarFc));
    }
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    MoveMemory
 * Signature: (Lorg/eclipse/swt/internal/win32/TVITEM;II)V
 */
JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_win32_OS_MoveMemory__Lorg_eclipse_swt_internal_win32_TVITEM_2II
  (JNIEnv *env, jclass that, jobject Destination, jint Source, jint Length)
{
	DECL_GLOB(pGlob)
    TVITEM tvitem, *lpDestination1=NULL;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "MoveMemory__Lorg_eclipse_swt_internal_win32_TVITEM_2II\n");
#endif

       MoveMemory((PVOID)&tvitem, (CONST VOID *)Source, Length);

    if (Destination) {
        lpDestination1 = &tvitem;
        cacheTvitemFids(env, Destination, &PGLOB(TvitemFc));
        setTvitemFields(env, Destination, lpDestination1, &PGLOB(TvitemFc));
    }
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    MoveMemory
 * Signature: (Lorg/eclipse/swt/internal/win32/WINDOWPOS;II)V
 */
JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_win32_OS_MoveMemory__Lorg_eclipse_swt_internal_win32_WINDOWPOS_2II
  (JNIEnv *env, jclass that, jobject Destination, jint Source, jint Length)
{
	DECL_GLOB(pGlob)
    WINDOWPOS windowpos, *lpDestination1=NULL;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "MoveMemory__Lorg_eclipse_swt_internal_win32_WINDOWPOS_2II\n");
#endif

       MoveMemory((PVOID)&windowpos, (CONST VOID *)Source, Length);

    if (Destination) {
        lpDestination1 = &windowpos;
        cacheWindowposFids(env, Destination, &PGLOB(WindowposFc));
        setWindowposFields(env, Destination, lpDestination1, &PGLOB(WindowposFc));
    }
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    MultiByteToWideChar
 * Signature: (II[BI[CI)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_MultiByteToWideChar__II_3BI_3CI
  (JNIEnv *env, jclass that, jint CodePage, jint dwFlags, jbyteArray lpMultiByteStr, jint cchMultiByte, jcharArray lpWideCharStr, jint cchWideChar)
{
    LPCSTR lpMultiByteStr1=NULL;
    LPWSTR lpWideCharStr1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "MultiByteToWideChar__II_3BI_3CI\n");
#endif

    if (lpMultiByteStr)
        lpMultiByteStr1 = (LPCSTR) (*env)->GetByteArrayElements(env, lpMultiByteStr, NULL);
    if (lpWideCharStr)
        lpWideCharStr1 = (LPWSTR) (*env)->GetCharArrayElements(env, lpWideCharStr, NULL);

    rc = (jint) MultiByteToWideChar(CodePage, dwFlags, lpMultiByteStr1, cchMultiByte, lpWideCharStr1, cchWideChar);

    if (lpMultiByteStr)
        (*env)->ReleaseByteArrayElements(env, lpMultiByteStr, (jbyte *)lpMultiByteStr1, 0);
    if (lpWideCharStr)
        (*env)->ReleaseCharArrayElements(env, lpWideCharStr, (jchar *)lpWideCharStr1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    MultiByteToWideChar
 * Signature: (IIII[CI)I
 */
/*
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_MultiByteToWideChar__IIII_3CI
  (JNIEnv *env, jclass that, jint CodePage, jint dwFlags, jint lpMultiByteStr, jint cchMultiByte, jcharArray lpWideCharStr, jint cchWideChar)
{
    LPWSTR lpWideCharStr1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "MultiByteToWideChar__IIII_3CI\n");
#endif

    if (lpWideCharStr)
        lpWideCharStr1 = (LPWSTR) (*env)->GetCharArrayElements(env, lpWideCharStr, NULL);

    rc = (jint) MultiByteToWideChar(CodePage, dwFlags, (LPCSTR)lpMultiByteStr, cchMultiByte, lpWideCharStr1, cchWideChar);

    if (lpWideCharStr)
        (*env)->ReleaseCharArrayElements(env, lpWideCharStr, (jchar *)lpWideCharStr1, 0);
    return rc;
}
*/

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    OpenClipboard
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_OpenClipboard
  (JNIEnv *env,  jclass that, jint hWndNewOwner)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "OpenClipboard\n");
#endif
    return (jboolean) OpenClipboard((HWND) hWndNewOwner);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    PatBlt
 * Signature: (IIIIII)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_PatBlt
  (JNIEnv *env, jclass that, jint hdc, jint nXLeft, jint nYLeft, jint nWidth, jint nHeight, jint dwRop)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "PatBlt\n");
#endif

    return (jboolean) PatBlt((HDC)hdc, nXLeft, nYLeft, nWidth, nHeight, dwRop);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    PeekMessageA
 * Signature: (Lorg/eclipse/swt/internal/win32/MSG;IIII)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_PeekMessageA
  (JNIEnv *env, jclass that, jobject lpMsg, jint hWnd, jint wMsgFilterMin, jint wMsgFilterMax, jint wRemoveMsg)
{
	DECL_GLOB(pGlob)
    MSG callBack, *lpMsg1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "PeekMessageA\n");
#endif

    if (lpMsg) {
        lpMsg1 = &callBack;
        cacheMsgFids(env, lpMsg, &PGLOB(MsgFc));
        getMsgFields(env, lpMsg, lpMsg1, &PGLOB(MsgFc));
    }
    rc = (jboolean) PeekMessageA(lpMsg1,(HWND)hWnd,wMsgFilterMin,wMsgFilterMax, wRemoveMsg);
    if (lpMsg) {
        setMsgFields(env, lpMsg, lpMsg1, &PGLOB(MsgFc));
    }
    return rc;
}
/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    PeekMessageW
 * Signature: (Lorg/eclipse/swt/internal/win32/MSG;IIII)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_PeekMessageW
  (JNIEnv *env, jclass that, jobject lpMsg, jint hWnd, jint wMsgFilterMin, jint wMsgFilterMax, jint wRemoveMsg)
{
	DECL_GLOB(pGlob)
    MSG callBack, *lpMsg1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "PeekMessageW\n");
#endif

    if (lpMsg) {
        lpMsg1 = &callBack;
        cacheMsgFids(env, lpMsg, &PGLOB(MsgFc));
        getMsgFields(env, lpMsg, lpMsg1, &PGLOB(MsgFc));
    }
    rc = (jboolean) PeekMessageW(lpMsg1,(HWND)hWnd,wMsgFilterMin,wMsgFilterMax, wRemoveMsg);
    if (lpMsg) {
        setMsgFields(env, lpMsg, lpMsg1, &PGLOB(MsgFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    Polygon
 * Signature: (I[II)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_Polygon
  (JNIEnv *env, jclass that, jint hdc, jintArray points, jint nPoints)
{
    jint *points1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "Polygon\n");
#endif

    if (points)
        points1 = (*env)->GetIntArrayElements(env, points, NULL);

    rc = (jboolean) Polygon((HDC)hdc, (POINT *)points1, nPoints);

    if (points)
        (*env)->ReleaseIntArrayElements(env, points, (jint *)points1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    Polyline
 * Signature: (I[II)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_Polyline
  (JNIEnv *env, jclass that, jint hdc, jintArray points, jint nPoints)
{
    POINT *points1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "Polyline\n");
#endif

    if (points)
        points1 = (POINT *)(*env)->GetIntArrayElements(env, points, NULL);

    rc = (jboolean) Polyline((HDC)hdc, points1, nPoints);

    if (points)
        (*env)->ReleaseIntArrayElements(env, points, (jint *)points1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    PostMessageA
 * Signature: (IIII)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_PostMessageA
  (JNIEnv *env, jclass that, jint hWnd, jint Msg, jint wParam, jint lParam)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "PostMessageA\n");
#endif

    return (jboolean) PostMessageA((HWND)hWnd, Msg, (WPARAM)wParam, (LPARAM)lParam);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    PostMessageW
 * Signature: (IIII)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_PostMessageW
  (JNIEnv *env, jclass that, jint hWnd, jint Msg, jint wParam, jint lParam)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "PostMessageW\n");
#endif

    return (jboolean) PostMessageW((HWND)hWnd, Msg, (WPARAM)wParam, (LPARAM)lParam);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    PostThreadMessageA
 * Signature: (IIII)I
 */
JNIEXPORT boolean JNICALL Java_org_eclipse_swt_internal_win32_OS_PostThreadMessageA
  (JNIEnv *env, jclass that, jint idThread, jint Msg, jint wParam, jint lParam)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "PostThreadMessageA\n");
#endif

    return (jboolean) PostThreadMessageA(idThread, Msg, (WPARAM)wParam, (LPARAM)lParam);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    PostThreadMessageW
 * Signature: (IIII)I
 */
JNIEXPORT boolean JNICALL Java_org_eclipse_swt_internal_win32_OS_PostThreadMessageW
  (JNIEnv *env, jclass that, jint idThread, jint Msg, jint wParam, jint lParam)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "PostThreadMessageW\n");
#endif

    return (jboolean) PostThreadMessageW(idThread, Msg, (WPARAM)wParam, (LPARAM)lParam);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    PtInRect
 * Signature: (Lorg/eclipse/swt/internal/win32/RECT;Lorg/eclipse/swt/internal/win32/POINT;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_PtInRect
  (JNIEnv *env, jclass that, jobject lpRect, jobject lpPoint)
{
	DECL_GLOB(pGlob)
    RECT rect, *lpRect1=NULL;
    POINT point, *lpPoint1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "PtInRect\n");
#endif

    if (lpRect) {
        lpRect1 = &rect;
        cacheRectFids(env, lpRect, &PGLOB(RectFc));
        getRectFields(env, lpRect, lpRect1, &PGLOB(RectFc));
    }
    if (lpPoint) {
        lpPoint1 = &point;
        cachePointFids(env, lpPoint, &PGLOB(PointFc));
        getPointFields(env, lpPoint, lpPoint1, &PGLOB(PointFc));
    }
    rc = (jboolean) PtInRect(lpRect1, point);
    if (lpRect) {
        setRectFields(env, lpRect, lpRect1, &PGLOB(RectFc));
    }
    if (lpPoint) {
        setPointFields(env, lpPoint, lpPoint1, &PGLOB(PointFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    PtInRegion
 * Signature: (III)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_PtInRegion
  (JNIEnv *env, jclass that, jint hrgn, jint X, jint Y)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "PtInRegion\n");
#endif

    return (jboolean) PtInRegion((HRGN)hrgn, X, Y);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    RealizePalette
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_RealizePalette
  (JNIEnv *env, jclass that, jint hdc)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "RealizePalette\n");
#endif

    return (jint) RealizePalette((HDC)hdc);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    Rectangle
 * Signature: (IIIII)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_Rectangle
  (JNIEnv *env, jclass that, jint hdc, jint nLeftRect, jint nTopRect, jint nRightRect, jint nBottomRect)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "Rectangle\n");
#endif
    return (jboolean) Rectangle((HDC)hdc, nLeftRect, nTopRect, nRightRect, nBottomRect);
}
/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    RectInRegion
 * Signature: (ILorg/eclipse/swt/internal/win32/RECT;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_RectInRegion
  (JNIEnv *env, jclass that, jint hrgn, jobject lprc)
{
	DECL_GLOB(pGlob)
    RECT rect, *lprc1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "RectInRegion\n");
#endif

    if (lprc) {
        lprc1 = &rect;
        cacheRectFids(env, lprc, &PGLOB(RectFc));
        getRectFields(env, lprc, lprc1, &PGLOB(RectFc));
    }
    rc = (jboolean) RectInRegion((HRGN)hrgn, lprc1);

    if (lprc) {
        setRectFields(env, lprc, lprc1, &PGLOB(RectFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    RegCloseKey
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_RegCloseKey
  (JNIEnv *env, jclass that, jint hKey)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "RegCloseKey\n");
#endif
    
    return (jint) RegCloseKey((HKEY)hKey);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    RegisterClassA
 * Signature: (Lorg/eclipse/swt/internal/win32/WNDCLASS;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_RegisterClassA
  (JNIEnv *env, jclass that, jobject lpwcx)
{
	DECL_GLOB(pGlob)
    WNDCLASS wcx, *lpwcx1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "RegisterClassA\n");
#endif

    if (lpwcx) {
        lpwcx1 = &wcx;
        cacheWndclassFids(env, lpwcx, &PGLOB(WndclassFc));
        getWndclassFields(env, lpwcx, lpwcx1, &PGLOB(WndclassFc));
    }
    rc = (jint) RegisterClassA(lpwcx1);

    if (lpwcx) {
        setWndclassFields(env, lpwcx, lpwcx1, &PGLOB(WndclassFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    RegisterClassW
 * Signature: (Lorg/eclipse/swt/internal/win32/WNDCLASS;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_RegisterClassW
  (JNIEnv *env, jclass that, jobject lpwcx)
{
	DECL_GLOB(pGlob)
    WNDCLASS wcx, *lpwcx1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "RegisterClassW\n");
#endif

    if (lpwcx) {
        lpwcx1 = &wcx;
        cacheWndclassFids(env, lpwcx, &PGLOB(WndclassFc));
        getWndclassFields(env, lpwcx, lpwcx1, &PGLOB(WndclassFc));
    }
    rc = (jint) RegisterClassW((LPWNDCLASSW)lpwcx1);

    if (lpwcx) {
        setWndclassFields(env, lpwcx, lpwcx1, &PGLOB(WndclassFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    RegEnumKeyExA
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_RegEnumKeyExA
  (JNIEnv *env, jclass that, jint hKey, jint dwIndex, jbyteArray lpName, jintArray lpcName, jintArray lpReserved, jbyteArray lpClass, jintArray lpcClass, jobject lpftLastWriteTime)
{
	DECL_GLOB(pGlob)
	jbyte *lpName1=NULL;
	jint *lpcName1=NULL;
	jint *lpReserved1=NULL;
	jbyte *lpClass1=NULL;
	jint *lpcClass1=NULL;
	FILETIME ftLastWriteTime, *lpftLastWriteTime1=NULL;
	jint rc;
	
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "RegEnumKeyExA\n");
#endif

	if (lpName)
		lpName1 = (*env)->GetByteArrayElements(env, lpName, NULL);
	if (lpcName)
		lpcName1 = (*env)->GetIntArrayElements(env, lpcName, NULL);
	if (lpReserved)
		lpReserved1 = (*env)->GetIntArrayElements(env, lpReserved, NULL);
	if (lpClass)
		lpClass1 = (*env)->GetByteArrayElements(env, lpClass, NULL);
	if (lpcClass)
		lpcClass1 = (*env)->GetIntArrayElements(env, lpcClass, NULL);
    if (lpftLastWriteTime) {
        lpftLastWriteTime1 = &ftLastWriteTime;
        cacheFiletimeFids(env, lpftLastWriteTime, &PGLOB(FiletimeFc));
        getFiletimeFields(env, lpftLastWriteTime, lpftLastWriteTime1, &PGLOB(FiletimeFc));
    }
                
    rc = (jint) RegEnumKeyExA((HKEY)hKey, dwIndex, (LPSTR)lpName1, lpcName1, lpReserved1, (LPSTR) lpClass1, lpcClass1, lpftLastWriteTime1);
    
	if (lpName)
		(*env)->ReleaseByteArrayElements(env, lpName, lpName1, 0);
	if (lpcName)
		(*env)->ReleaseIntArrayElements(env, lpcName, lpcName1, 0);
 	if (lpReserved)
		(*env)->ReleaseIntArrayElements(env, lpReserved, lpReserved1, 0);
 	if (lpClass)
		(*env)->ReleaseByteArrayElements(env, lpClass, lpClass1, 0);
 	if (lpcClass)
		(*env)->ReleaseIntArrayElements(env, lpcClass, lpcClass1, 0);
    if (lpftLastWriteTime) {
        setFiletimeFields(env, lpftLastWriteTime, lpftLastWriteTime1, &PGLOB(FiletimeFc));
    }
    return rc;
}

JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_RegEnumKeyExW
  (JNIEnv *env, jclass that, jint hKey, jint dwIndex, jcharArray lpName, jintArray lpcName, jintArray lpReserved, jcharArray lpClass, jintArray lpcClass, jobject lpftLastWriteTime)
{
	DECL_GLOB(pGlob)
	jchar *lpName1=NULL;
	jint *lpcName1=NULL;
	jint *lpReserved1=NULL;
	jchar *lpClass1=NULL;
	jint *lpcClass1=NULL;
	FILETIME ftLastWriteTime, *lpftLastWriteTime1=NULL;
	jint rc;
	
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "RegEnumKeyExW\n");
#endif

	if (lpName)
		lpName1 = (*env)->GetCharArrayElements(env, lpName, NULL);
	if (lpcName)
		lpcName1 = (*env)->GetIntArrayElements(env, lpcName, NULL);
	if (lpReserved)
		lpReserved1 = (*env)->GetIntArrayElements(env, lpReserved, NULL);
	if (lpClass)
		lpClass1 = (*env)->GetCharArrayElements(env, lpClass, NULL);
	if (lpcClass)
		lpcClass1 = (*env)->GetIntArrayElements(env, lpcClass, NULL);
    if (lpftLastWriteTime) {
        lpftLastWriteTime1 = &ftLastWriteTime;
        cacheFiletimeFids(env, lpftLastWriteTime, &PGLOB(FiletimeFc));
        getFiletimeFields(env, lpftLastWriteTime, lpftLastWriteTime1, &PGLOB(FiletimeFc));
    }
                
    rc = (jint) RegEnumKeyExW((HKEY)hKey, dwIndex, (LPWSTR)lpName1, lpcName1, lpReserved1, (LPWSTR) lpClass1, lpcClass1, lpftLastWriteTime1);
    
	if (lpName)
		(*env)->ReleaseCharArrayElements(env, lpName, lpName1, 0);
	if (lpcName)
		(*env)->ReleaseIntArrayElements(env, lpcName, lpcName1, 0);
 	if (lpReserved)
		(*env)->ReleaseIntArrayElements(env, lpReserved, lpReserved1, 0);
 	if (lpClass)
		(*env)->ReleaseCharArrayElements(env, lpClass, lpClass1, 0);
 	if (lpcClass)
		(*env)->ReleaseIntArrayElements(env, lpcClass, lpcClass1, 0);
    if (lpftLastWriteTime) {
        setFiletimeFields(env, lpftLastWriteTime, lpftLastWriteTime1, &PGLOB(FiletimeFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    RegOpenKeyExA
 * Signature: (I[BII[I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_RegOpenKeyExA
  (JNIEnv *env, jclass that, jint hKey, jbyteArray lpSubKey, jint ulOptions, jint samDesired, jintArray jhkResult)
{
    jint *jhkResult1=NULL;
    jbyte *lpSubKey1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "RegOpenKeyExA\n");
#endif
    

    if (jhkResult)
        jhkResult1 = (*env)->GetIntArrayElements(env, jhkResult, NULL);
    if (lpSubKey)
        lpSubKey1 = (*env)->GetByteArrayElements(env, lpSubKey, NULL);

    rc = (jint) RegOpenKeyExA((HKEY)hKey, (LPSTR)lpSubKey1, ulOptions, samDesired, (PHKEY)jhkResult1);

    if (jhkResult)
        (*env)->ReleaseIntArrayElements(env, jhkResult, jhkResult1, 0);
    if (lpSubKey)
        (*env)->ReleaseByteArrayElements(env, lpSubKey, lpSubKey1, 0);
    return rc;    
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    RegOpenKeyExW
 * Signature: (I[BII[I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_RegOpenKeyExW
  (JNIEnv *env, jclass that, jint hKey, jbyteArray lpSubKey, jint ulOptions, jint samDesired, jintArray jhkResult)
{
    jint *jhkResult1=NULL;
    jchar *lpSubKey1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "RegOpenKeyExW\n");
#endif
    

    if (jhkResult)
        jhkResult1 = (*env)->GetIntArrayElements(env, jhkResult, NULL);
    if (lpSubKey)
        lpSubKey1 = (*env)->GetCharArrayElements(env, lpSubKey, NULL);

    rc = (jint) RegOpenKeyExW((HKEY)hKey, (LPWSTR)lpSubKey1, ulOptions, samDesired, (PHKEY)jhkResult1);

    if (jhkResult)
        (*env)->ReleaseIntArrayElements(env, jhkResult, jhkResult1, 0);
    if (lpSubKey)
        (*env)->ReleaseCharArrayElements(env, lpSubKey, lpSubKey1, 0);
    return rc;    
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    RegQueryInfoKeyA
 * Signature: (II[II[I[I[I[I[I[I[II)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_RegQueryInfoKeyA
  (JNIEnv *env, jclass that, jint hKey, jint lpClass, jintArray lpcbClass, jint lpReserved, jintArray lpSubKeys, jintArray lpcbMaxSubKeyLen, jintArray lpcbMaxClassLen, jintArray lpcValues, jintArray lpcbMaxValueNameLen, jintArray lpcbMaxValueLen, jintArray lpcbSecurityDescriptor, jint lpftLastWriteTime)
{
    jint *lpcbClass1=NULL;
    jint *lpSubKeys1=NULL;
    jint *lpcbMaxSubKeyLen1=NULL;
    jint *lpcbMaxClassLen1=NULL;
    jint *lpcValues1=NULL;
    jint *lpcbMaxValueNameLen1=NULL;
    jint *lpcbMaxValueLen1=NULL;
    jint *lpcbSecurityDescriptor1=NULL;
    jint rc;
    
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "RegQueryInfoKeyA\n");
#endif
    
    if (lpcbClass)
        lpcbClass1 = (*env)->GetIntArrayElements(env, lpcbClass, NULL);
    if (lpSubKeys)
        lpSubKeys1 = (*env)->GetIntArrayElements(env, lpSubKeys, NULL);
    if (lpcbMaxSubKeyLen)
        lpcbMaxSubKeyLen1 = (*env)->GetIntArrayElements(env, lpcbMaxSubKeyLen, NULL);
    if (lpcbMaxClassLen)
        lpcbMaxClassLen1 = (*env)->GetIntArrayElements(env, lpcbMaxClassLen, NULL);
    if (lpcValues)
        lpcValues1 = (*env)->GetIntArrayElements(env, lpcValues, NULL);
    if (lpcbMaxValueNameLen)
        lpcbMaxValueNameLen1 = (*env)->GetIntArrayElements(env, lpcbMaxValueNameLen, NULL);
    if (lpcbMaxValueLen)
        lpcbMaxValueLen1 = (*env)->GetIntArrayElements(env, lpcbMaxValueLen, NULL);
    if (lpcbSecurityDescriptor)
        lpcbSecurityDescriptor1 = (*env)->GetIntArrayElements(env, lpcbSecurityDescriptor, NULL);

    rc = (jint) RegQueryInfoKeyA((HKEY)hKey, (LPTSTR)lpClass, lpcbClass1, (LPDWORD)lpReserved, lpSubKeys1, lpcbMaxSubKeyLen1, lpcbMaxClassLen1, lpcValues1, lpcbMaxValueNameLen1, lpcbMaxValueLen1, lpcbSecurityDescriptor1, (PFILETIME)lpftLastWriteTime);
    
    if (lpcbClass)
        (*env)->ReleaseIntArrayElements(env, lpcbClass, lpcbClass1, 0);
    if (lpSubKeys)
        (*env)->ReleaseIntArrayElements(env, lpSubKeys, lpSubKeys1, 0);
    if (lpcbMaxSubKeyLen)
        (*env)->ReleaseIntArrayElements(env, lpcbMaxSubKeyLen, lpcbMaxSubKeyLen1, 0);
    if (lpcbMaxClassLen)
        (*env)->ReleaseIntArrayElements(env, lpcbMaxClassLen, lpcbMaxClassLen1, 0);
    if (lpcValues)
        (*env)->ReleaseIntArrayElements(env, lpcValues, lpcValues1, 0);
    if (lpcbMaxValueNameLen)
        (*env)->ReleaseIntArrayElements(env, lpcbMaxValueNameLen, lpcbMaxValueNameLen1, 0);
    if (lpcbMaxValueLen)
        (*env)->ReleaseIntArrayElements(env, lpcbMaxValueLen, lpcbMaxValueLen1, 0);
    if (lpcbSecurityDescriptor)
        (*env)->ReleaseIntArrayElements(env, lpcbSecurityDescriptor, lpcbSecurityDescriptor1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    RegQueryInfoKeyW
 * Signature: (II[II[I[I[I[I[I[I[II)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_RegQueryInfoKeyW
  (JNIEnv *env, jclass that, jint hKey, jint lpClass, jintArray lpcbClass, jint lpReserved, jintArray lpSubKeys, jintArray lpcbMaxSubKeyLen, jintArray lpcbMaxClassLen, jintArray lpcValues, jintArray lpcbMaxValueNameLen, jintArray lpcbMaxValueLen, jintArray lpcbSecurityDescriptor, jint lpftLastWriteTime)
{
    jint *lpcbClass1=NULL;
    jint *lpSubKeys1=NULL;
    jint *lpcbMaxSubKeyLen1=NULL;
    jint *lpcbMaxClassLen1=NULL;
    jint *lpcValues1=NULL;
    jint *lpcbMaxValueNameLen1=NULL;
    jint *lpcbMaxValueLen1=NULL;
    jint *lpcbSecurityDescriptor1=NULL;
    jint rc;
    
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "RegQueryInfoKeyW\n");
#endif
    
    if (lpcbClass)
        lpcbClass1 = (*env)->GetIntArrayElements(env, lpcbClass, NULL);
    if (lpSubKeys)
        lpSubKeys1 = (*env)->GetIntArrayElements(env, lpSubKeys, NULL);
    if (lpcbMaxSubKeyLen)
        lpcbMaxSubKeyLen1 = (*env)->GetIntArrayElements(env, lpcbMaxSubKeyLen, NULL);
    if (lpcbMaxClassLen)
        lpcbMaxClassLen1 = (*env)->GetIntArrayElements(env, lpcbMaxClassLen, NULL);
    if (lpcValues)
        lpcValues1 = (*env)->GetIntArrayElements(env, lpcValues, NULL);
    if (lpcbMaxValueNameLen)
        lpcbMaxValueNameLen1 = (*env)->GetIntArrayElements(env, lpcbMaxValueNameLen, NULL);
    if (lpcbMaxValueLen)
        lpcbMaxValueLen1 = (*env)->GetIntArrayElements(env, lpcbMaxValueLen, NULL);
    if (lpcbSecurityDescriptor)
        lpcbSecurityDescriptor1 = (*env)->GetIntArrayElements(env, lpcbSecurityDescriptor, NULL);

    rc = (jint) RegQueryInfoKeyW((HKEY)hKey, (LPWSTR)lpClass, lpcbClass1, (LPDWORD)lpReserved, lpSubKeys1, lpcbMaxSubKeyLen1, lpcbMaxClassLen1, lpcValues1, lpcbMaxValueNameLen1, lpcbMaxValueLen1, lpcbSecurityDescriptor1, (PFILETIME)lpftLastWriteTime);
    
    if (lpcbClass)
        (*env)->ReleaseIntArrayElements(env, lpcbClass, lpcbClass1, 0);
    if (lpSubKeys)
        (*env)->ReleaseIntArrayElements(env, lpSubKeys, lpSubKeys1, 0);
    if (lpcbMaxSubKeyLen)
        (*env)->ReleaseIntArrayElements(env, lpcbMaxSubKeyLen, lpcbMaxSubKeyLen1, 0);
    if (lpcbMaxClassLen)
        (*env)->ReleaseIntArrayElements(env, lpcbMaxClassLen, lpcbMaxClassLen1, 0);
    if (lpcValues)
        (*env)->ReleaseIntArrayElements(env, lpcValues, lpcValues1, 0);
    if (lpcbMaxValueNameLen)
        (*env)->ReleaseIntArrayElements(env, lpcbMaxValueNameLen, lpcbMaxValueNameLen1, 0);
    if (lpcbMaxValueLen)
        (*env)->ReleaseIntArrayElements(env, lpcbMaxValueLen, lpcbMaxValueLen1, 0);
    if (lpcbSecurityDescriptor)
        (*env)->ReleaseIntArrayElements(env, lpcbSecurityDescriptor, lpcbSecurityDescriptor1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    RegQueryValueExA
 * Signature: (I[BI[I[B[I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_RegQueryValueExA
  (JNIEnv *env, jclass that, jint hKey, jbyteArray lpValueName, jint lpReserved, jintArray lpType, jbyteArray lpData, jintArray lpcbData)
{
    jbyte *lpValueName1=NULL;
    jbyte *lpData1=NULL;
    jint *lpType1=NULL;
    jint *lpcbData1=NULL;
    jint rc;
    
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "RegQueryValueExA\n");
#endif
    
    if (lpValueName)
        lpValueName1 = (*env)->GetByteArrayElements(env, lpValueName, NULL);
    if (lpData)
        lpData1 = (*env)->GetByteArrayElements(env, lpData, NULL);
    if (lpType)
        lpType1 = (*env)->GetIntArrayElements(env, lpType, NULL);
    if (lpcbData)
        lpcbData1 = (*env)->GetIntArrayElements(env, lpcbData, NULL);

    rc = (jint) RegQueryValueExA((HKEY)hKey, (LPSTR)lpValueName1, (LPDWORD)lpReserved, lpType1, (LPBYTE)lpData1, lpcbData1);

    if (lpValueName)
        (*env)->ReleaseByteArrayElements(env, lpValueName, lpValueName1, 0);
    if (lpData)
        (*env)->ReleaseByteArrayElements(env, lpData, lpData1, 0);
    if (lpType)
        (*env)->ReleaseIntArrayElements(env, lpType, lpType1, 0);
    if (lpcbData)
        (*env)->ReleaseIntArrayElements(env, lpcbData, lpcbData1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    RegQueryValueExW
 * Signature: (I[CI[I[C[I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_RegQueryValueExW
  (JNIEnv *env, jclass that, jint hKey, jcharArray lpValueName, jint lpReserved, jintArray lpType, jcharArray lpData, jintArray lpcbData)
{
    jchar *lpValueName1=NULL;
    jchar *lpData1=NULL;
    jint *lpType1=NULL;
    jint *lpcbData1=NULL;
    jint rc;
    
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "RegQueryValueExW\n");
#endif
    
    if (lpValueName)
        lpValueName1 = (*env)->GetCharArrayElements(env, lpValueName, NULL);
    if (lpData)
        lpData1 = (*env)->GetCharArrayElements(env, lpData, NULL);
    if (lpType)
        lpType1 = (*env)->GetIntArrayElements(env, lpType, NULL);
    if (lpcbData)
        lpcbData1 = (*env)->GetIntArrayElements(env, lpcbData, NULL);

    rc = (jint) RegQueryValueExW((HKEY)hKey, (LPWSTR)lpValueName1, (LPDWORD)lpReserved, lpType1, (LPBYTE)lpData1, lpcbData1);

    if (lpValueName)
        (*env)->ReleaseCharArrayElements(env, lpValueName, lpValueName1, 0);
    if (lpData)
        (*env)->ReleaseCharArrayElements(env, lpData, lpData1, 0);
    if (lpType)
        (*env)->ReleaseIntArrayElements(env, lpType, lpType1, 0);
    if (lpcbData)
        (*env)->ReleaseIntArrayElements(env, lpcbData, lpcbData1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ReleaseCapture
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_ReleaseCapture
  (JNIEnv *env, jclass that)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "ReleaseCapture\n");
#endif

    return (jboolean) ReleaseCapture();
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ReleaseDC
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_ReleaseDC
  (JNIEnv *env, jclass that, jint hWnd, jint hDC)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "ReleaseDC\n");
#endif

    return (jint) ReleaseDC((HWND)hWnd, (HDC)hDC);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    RemoveMenu
 * Signature: (III)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_RemoveMenu
  (JNIEnv *env, jclass that, jint hMenu, jint uPosition, jint uFlags)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "RemoveMenu\n");
#endif

    return (jboolean) RemoveMenu((HMENU)hMenu, uPosition, uFlags);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    RoundRect
 * Signature: (IIIIIII)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_RoundRect
  (JNIEnv *env, jclass that, jint hdc, jint nLeftRect, jint nTopRect, jint nRightRect, jint nBottomRect, jint nWidth, jint nHeight)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "RoundRect\n");
#endif

    return (jboolean) RoundRect((HDC)hdc, nLeftRect, nTopRect, nRightRect, nBottomRect, nWidth, nHeight);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ScreenToClient
 * Signature: (ILorg/eclipse/swt/internal/win32/POINT;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_ScreenToClient
  (JNIEnv *env, jclass that, jint hWnd, jobject lpPoint)
{
	DECL_GLOB(pGlob)
    POINT point1, *lpPoint1=NULL;
    jboolean rc;
    
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "ScreenToClient\n");
#endif

    if (lpPoint) {
        lpPoint1 = &point1;
        cachePointFids(env, lpPoint, &PGLOB(PointFc));
        getPointFields(env, lpPoint, lpPoint1, &PGLOB(PointFc));
    }
    rc = (jboolean) ScreenToClient((HWND)hWnd, lpPoint1);
    if (lpPoint) {
        setPointFields(env, lpPoint, lpPoint1, &PGLOB(PointFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ScrollWindowEx
 * Signature: (IIILorg/eclipse/swt/internal/win32/RECT;Lorg/eclipse/swt/internal/win32/RECT;ILorg/eclipse/swt/internal/win32/RECT;I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_ScrollWindowEx
  (JNIEnv *env, jclass that, jint hWnd, jint dx, jint dy, jobject prcScroll, jobject prcClip, jint hrgnUpdate, jobject prcUpdate, jint flags)
{
	DECL_GLOB(pGlob)
    RECT rect1, rect2, rect3;
    RECT *prcScroll1=NULL, *prcClip1=NULL, *prcUpdate1=NULL;
    jobject lpRect;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "ScrollWindowEx\n");
#endif

    if (prcScroll || prcClip || prcUpdate) {
        if (prcScroll) {
            lpRect = prcScroll;
        } 
        else if (prcClip) {
            lpRect = prcClip;
        }
        else if (prcUpdate) {
            lpRect = prcUpdate;
        }
        cacheRectFids(env, lpRect, &PGLOB(RectFc));
    }

    if (prcScroll) {
        prcScroll1 = &rect1;
        getRectFields(env, prcScroll, prcScroll1, &PGLOB(RectFc));
    }
    if (prcClip) {
        prcClip1 = &rect2;
        getRectFields(env, prcClip, prcClip1, &PGLOB(RectFc));
    }
    if (prcUpdate) {
        prcUpdate1 = &rect3;
        getRectFields(env, prcUpdate, prcUpdate1, &PGLOB(RectFc));
    }
    rc = (jint) ScrollWindowEx((HWND)hWnd, dx, dy, prcScroll1, prcClip1, (HRGN)hrgnUpdate, prcUpdate1, flags);
    if (prcScroll) {
        setRectFields(env, prcScroll, prcScroll1, &PGLOB(RectFc));
    }
    if (prcClip) {
        setRectFields(env, prcClip, prcClip1, &PGLOB(RectFc));
    }
    if (prcUpdate) {
        setRectFields(env, prcUpdate, prcUpdate1, &PGLOB(RectFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SelectClipRgn
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SelectClipRgn
  (JNIEnv *env, jclass that, jint hdc, jint hrgn)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SelectClipRgn\n");
#endif

    return (jint) SelectClipRgn((HDC)hdc, (HRGN)hrgn);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SelectObject
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SelectObject
  (JNIEnv *env, jclass that, jint hdc, jint hgdiobj)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SelectObject\n");
#endif

    return (jint) SelectObject((HDC)hdc, (HGDIOBJ)hgdiobj);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SelectPalette
 * Signature: (IIZ)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SelectPalette
  (JNIEnv *env, jclass that, jint hdc, jint hpal, jboolean bForceBackground)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SelectPalette\n");
#endif

    return (jint) SelectPalette((HDC)hdc, (HPALETTE)hpal, bForceBackground);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SendMessageA
 * Signature: (II[II)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SendMessageA__II_3II
  (JNIEnv *env, jclass that, jint hWnd, jint Msg, jintArray wParam, jint lParam)
{
    jint *wParam1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SendMessageA__II_3II\n");
#endif

    if (wParam)
        wParam1 = (*env)->GetIntArrayElements(env, wParam, NULL);

    rc = (jint) SendMessageA((HWND)hWnd, Msg, (WPARAM)wParam1, (LPARAM)lParam);

    if (wParam)
        (*env)->ReleaseIntArrayElements(env, wParam, wParam1, 0);

    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SendMessageW
 * Signature: (II[II)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SendMessageW__II_3II
  (JNIEnv *env, jclass that, jint hWnd, jint Msg, jintArray wParam, jint lParam)
{
    jint *wParam1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SendMessageW__II_3II\n");
#endif

    if (wParam)
        wParam1 = (*env)->GetIntArrayElements(env, wParam, NULL);

    rc = (jint) SendMessageW((HWND)hWnd, Msg, (WPARAM)wParam1, (LPARAM)lParam);

    if (wParam)
        (*env)->ReleaseIntArrayElements(env, wParam, wParam1, 0);

    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SendMessageA
 * Signature: (II[I[I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SendMessageA__II_3I_3I
  (JNIEnv *env, jclass that, jint hWnd, jint Msg, jintArray wParam, jintArray lParam)
{
    WPARAM wParam1=0;
    LPARAM lParam1=0;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SendMessageA__II_3I_3I\n");
#endif

    if (wParam)
        wParam1 = (WPARAM)(*env)->GetIntArrayElements(env, wParam, NULL);
    if (lParam)
        lParam1 = (LPARAM)(*env)->GetIntArrayElements(env, lParam, NULL);

    rc = (jint) SendMessageA((HWND)hWnd, Msg, wParam1, lParam1);

    if (wParam)
        (*env)->ReleaseIntArrayElements(env, wParam, (jint *)wParam1, 0);
    if (lParam)
        (*env)->ReleaseIntArrayElements(env, lParam, (jint *)lParam1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SendMessageW
 * Signature: (II[I[I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SendMessageW__II_3I_3I
  (JNIEnv *env, jclass that, jint hWnd, jint Msg, jintArray wParam, jintArray lParam)
{
    WPARAM wParam1=0;
    LPARAM lParam1=0;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SendMessageW__II_3I_3I\n");
#endif

    if (wParam)
        wParam1 = (WPARAM)(*env)->GetIntArrayElements(env, wParam, NULL);
    if (lParam)
        lParam1 = (LPARAM)(*env)->GetIntArrayElements(env, lParam, NULL);

    rc = (jint) SendMessageW((HWND)hWnd, Msg, wParam1, lParam1);

    if (wParam)
        (*env)->ReleaseIntArrayElements(env, wParam, (jint *)wParam1, 0);
    if (lParam)
        (*env)->ReleaseIntArrayElements(env, lParam, (jint *)lParam1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SendMessageA
 * Signature: (III[B)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SendMessageA__III_3B
  (JNIEnv *env, jclass that, jint hWnd, jint Msg, jint wParam, jbyteArray lParam)
{
    jbyte* lParam1=0;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SendMessageA__III_3B\n");
#endif

    if (lParam)
        lParam1 = (*env)->GetByteArrayElements(env, lParam, NULL);

    rc = (jint) SendMessageA((HWND)hWnd, Msg, wParam, (LPARAM)lParam1);

    if (lParam)
        (*env)->ReleaseByteArrayElements(env, lParam, lParam1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SendMessageW
 * Signature: (III[C)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SendMessageW__III_3C
  (JNIEnv *env, jclass that, jint hWnd, jint Msg, jint wParam, jcharArray lParam)
{
    jchar* lParam1=0;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SendMessageW__III_3C\n");
#endif

    if (lParam)
        lParam1 = (*env)->GetCharArrayElements(env, lParam, NULL);

    rc = (jint) SendMessageW((HWND)hWnd, Msg, wParam, (LPARAM)lParam1);

    if (lParam)
        (*env)->ReleaseCharArrayElements(env, lParam, lParam1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SendMessageA
 * Signature: (III[I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SendMessageA__III_3I
  (JNIEnv *env, jclass that, jint hWnd, jint Msg, jint wParam, jintArray lParam)
{
    jint* lParam1=0;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SendMessageA__III_3I\n");
#endif

    if (lParam)
        lParam1 = (*env)->GetIntArrayElements(env, lParam, NULL);

    rc = (jint) SendMessageA((HWND)hWnd, Msg, wParam, (LPARAM)lParam1);

    if (lParam)
        (*env)->ReleaseIntArrayElements(env, lParam, lParam1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SendMessageW
 * Signature: (III[I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SendMessageW__III_3I
  (JNIEnv *env, jclass that, jint hWnd, jint Msg, jint wParam, jintArray lParam)
{
    jint* lParam1=0;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SendMessageW__III_3I\n");
#endif

    if (lParam)
        lParam1 = (*env)->GetIntArrayElements(env, lParam, NULL);

    rc = (jint) SendMessageW((HWND)hWnd, Msg, wParam, (LPARAM)lParam1);

    if (lParam)
        (*env)->ReleaseIntArrayElements(env, lParam, lParam1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SendMessageA
 * Signature: (III[S)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SendMessageA__III_3S
  (JNIEnv *env, jclass that, jint hWnd, jint Msg, jint wParam, jshortArray lParam)
{
    jshort* lParam1=0;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SendMessageA__III_3S\n");
#endif

    if (lParam)
        lParam1 = (*env)->GetShortArrayElements(env, lParam, NULL);

    rc = (jint) SendMessageA((HWND)hWnd, Msg, wParam, (LPARAM)lParam1);

    if (lParam)
        (*env)->ReleaseShortArrayElements(env, lParam, lParam1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SendMessageW
 * Signature: (III[S)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SendMessageW__III_3S
  (JNIEnv *env, jclass that, jint hWnd, jint Msg, jint wParam, jshortArray lParam)
{
    jshort* lParam1=0;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SendMessageW__III_3S\n");
#endif

    if (lParam)
        lParam1 = (*env)->GetShortArrayElements(env, lParam, NULL);

    rc = (jint) SendMessageW((HWND)hWnd, Msg, wParam, (LPARAM)lParam1);

    if (lParam)
        (*env)->ReleaseShortArrayElements(env, lParam, lParam1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SendMessageA
 * Signature: (IIII)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SendMessageA__IIII
  (JNIEnv *env, jclass that, jint hWnd, jint Msg, jint wParam, jint lParam)
{

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SendMessageA__IIII\n");
#endif

    return (jint) SendMessageA((HWND)hWnd, Msg, wParam, lParam);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SendMessageW
 * Signature: (IIII)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SendMessageW__IIII
  (JNIEnv *env, jclass that, jint hWnd, jint Msg, jint wParam, jint lParam)
{

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SendMessageW__IIII\n");
#endif

    return (jint) SendMessageW((HWND)hWnd, Msg, wParam, lParam);
}


/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SendMessage
 * Signature: (IIILorg/eclipse/swt/internal/win32/CHARFORMAT2;)I
 */
/*
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SendMessage__IIILorg_eclipse_swt_internal_win32_CHARFORMAT2_2
  (JNIEnv *env, jclass that, jint hWnd, jint Msg, jint wParam, jobject lParam)
{
	DECL_GLOB(pGlob)
    CHARFORMAT2 charformat2, *lParam1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SendMessage__IIILorg_eclipse_swt_internal_win32_CHARFORMAT2_2\n");
#endif

    if (lParam) {
        lParam1 = &charformat2;
        cacheCharformat2Fids(env, lParam, &PGLOB(Charformat2Fc));
        getCharformat2Fields(env, lParam, lParam1, &PGLOB(Charformat2Fc));
    }

    rc = (jint) SendMessage((HWND)hWnd, Msg, wParam, (LPARAM)lParam1);
    if (lParam) {
        setCharformat2Fields(env, lParam, lParam1, &PGLOB(Charformat2Fc));
    }
    return rc;
}
*/

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SendMessageA
 * Signature: (IIILorg/eclipse/swt/internal/win32/LVCOLUMN;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SendMessageA__IIILorg_eclipse_swt_internal_win32_LVCOLUMN_2
  (JNIEnv *env, jclass that, jint hWnd, jint Msg, jint wParam, jobject lParam)
{
	DECL_GLOB(pGlob)
    LVCOLUMN lvcolumn, *lpParam1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SendMessageA__IIILorg_eclipse_swt_internal_win32_LVCOLUMN_2\n");
#endif

    if (lParam) {
        lpParam1 = &lvcolumn;
        cacheLvcolumnFids(env, lParam, &PGLOB(LvcolumnFc));
        getLvcolumnFields(env, lParam, lpParam1, &PGLOB(LvcolumnFc));
    }
    
    rc = (jint) SendMessageA((HWND)hWnd, Msg, wParam, (LPARAM)lpParam1);

    if (lParam) {
        setLvcolumnFields(env, lParam, lpParam1, &PGLOB(LvcolumnFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SendMessageW
 * Signature: (IIILorg/eclipse/swt/internal/win32/LVCOLUMN;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SendMessageW__IIILorg_eclipse_swt_internal_win32_LVCOLUMN_2
  (JNIEnv *env, jclass that, jint hWnd, jint Msg, jint wParam, jobject lParam)
{
	DECL_GLOB(pGlob)
    LVCOLUMN lvcolumn, *lpParam1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SendMessageW__IIILorg_eclipse_swt_internal_win32_LVCOLUMN_2\n");
#endif

    if (lParam) {
        lpParam1 = &lvcolumn;
        cacheLvcolumnFids(env, lParam, &PGLOB(LvcolumnFc));
        getLvcolumnFields(env, lParam, lpParam1, &PGLOB(LvcolumnFc));
    }
    
    rc = (jint) SendMessageW((HWND)hWnd, Msg, wParam, (LPARAM)lpParam1);

    if (lParam) {
        setLvcolumnFields(env, lParam, lpParam1, &PGLOB(LvcolumnFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SendMessageA
 * Signature: (IIILorg/eclipse/swt/internal/win32/LVHITTESTINFO;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SendMessageA__IIILorg_eclipse_swt_internal_win32_LVHITTESTINFO_2
  (JNIEnv *env, jclass that, jint hWnd, jint Msg, jint wParam, jobject lParam)
{
	DECL_GLOB(pGlob)
    LVHITTESTINFO lvhittestinfo, *lParam1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SendMessageA__IIILorg_eclipse_swt_internal_win32_LVHITTESTINFO_2\n");
#endif

    if (lParam) {
        lParam1 = &lvhittestinfo;
        cacheLvhittestinfoFids(env, lParam, &PGLOB(LvhittestinfoFc));
        getLvhittestinfoFields(env, lParam, lParam1, &PGLOB(LvhittestinfoFc));
    }
    
    rc = (jint) SendMessageA((HWND)hWnd, Msg, wParam, (LPARAM)lParam1);

    if (lParam) {
        setLvhittestinfoFields(env, lParam, lParam1, &PGLOB(LvhittestinfoFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SendMessageW
 * Signature: (IIILorg/eclipse/swt/internal/win32/LVHITTESTINFO;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SendMessageW__IIILorg_eclipse_swt_internal_win32_LVHITTESTINFO_2
  (JNIEnv *env, jclass that, jint hWnd, jint Msg, jint wParam, jobject lParam)
{
	DECL_GLOB(pGlob)
    LVHITTESTINFO lvhittestinfo, *lParam1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SendMessageW__IIILorg_eclipse_swt_internal_win32_LVHITTESTINFO_2\n");
#endif

    if (lParam) {
        lParam1 = &lvhittestinfo;
        cacheLvhittestinfoFids(env, lParam, &PGLOB(LvhittestinfoFc));
        getLvhittestinfoFields(env, lParam, lParam1, &PGLOB(LvhittestinfoFc));
    }
    
    rc = (jint) SendMessageW((HWND)hWnd, Msg, wParam, (LPARAM)lParam1);

    if (lParam) {
        setLvhittestinfoFields(env, lParam, lParam1, &PGLOB(LvhittestinfoFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SendMessageA
 * Signature: (IIILorg/eclipse/swt/internal/win32/LVITEM;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SendMessageA__IIILorg_eclipse_swt_internal_win32_LVITEM_2
  (JNIEnv *env, jclass that, jint hWnd, jint Msg, jint wParam, jobject lParam)
{
	DECL_GLOB(pGlob)
    LVITEM lvitem, *lpParam1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SendMessageA__IIILorg_eclipse_swt_internal_win32_LVITEM_2\n");
#endif

    if (lParam) {
        lpParam1 = &lvitem;
        cacheLvitemFids(env, lParam, &PGLOB(LvitemFc));
        getLvitemFields(env, lParam, lpParam1, &PGLOB(LvitemFc));
    }
    rc = (jint) SendMessageA((HWND)hWnd, Msg, wParam, (LPARAM)lpParam1);
    if (lParam) {
        setLvitemFields(env, lParam, lpParam1, &PGLOB(LvitemFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SendMessageW
 * Signature: (IIILorg/eclipse/swt/internal/win32/LVITEM;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SendMessageW__IIILorg_eclipse_swt_internal_win32_LVITEM_2
  (JNIEnv *env, jclass that, jint hWnd, jint Msg, jint wParam, jobject lParam)
{
	DECL_GLOB(pGlob)
    LVITEM lvitem, *lpParam1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SendMessageW__IIILorg_eclipse_swt_internal_win32_LVITEM_2\n");
#endif

    if (lParam) {
        lpParam1 = &lvitem;
        cacheLvitemFids(env, lParam, &PGLOB(LvitemFc));
        getLvitemFields(env, lParam, lpParam1, &PGLOB(LvitemFc));
    }
    rc = (jint) SendMessageW((HWND)hWnd, Msg, wParam, (LPARAM)lpParam1);
    if (lParam) {
        setLvitemFields(env, lParam, lpParam1, &PGLOB(LvitemFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SendMessage
 * Signature: (IIILorg/eclipse/swt/internal/win32/PARAFORMAT;)I
 */
/*
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SendMessage__IIILorg_eclipse_swt_internal_win32_PARAFORMAT_2
  (JNIEnv *env, jclass that, jint hWnd, jint Msg, jint wParam, jobject lParam)
{
	DECL_GLOB(pGlob)
    PARAFORMAT paraformat, *lpParam1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SendMessage__IIILorg_eclipse_swt_internal_win32_PARAFORMAT_2\n");
#endif

    if (lParam) {
        lpParam1 = &paraformat;
        cacheParaformatFids(env, lParam, &PGLOB(ParaformatFc));
        getParaformatFields(env, lParam, lpParam1, &PGLOB(ParaformatFc));
    }

    rc = (jint) SendMessage((HWND)hWnd, Msg, wParam, (LPARAM)lpParam1);

    if (lParam) {
        setParaformatFields(env, lParam, lpParam1, &PGLOB(ParaformatFc));
    }
    return rc;
}
*/

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SendMessageA
 * Signature: (IIILorg/eclipse/swt/internal/win32/REBARBANDINFO;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SendMessageA__IIILorg_eclipse_swt_internal_win32_REBARBANDINFO_2
  (JNIEnv *env, jclass that, jint hWnd, jint Msg, jint wParam, jobject lParam)
{
	DECL_GLOB(pGlob)
    REBARBANDINFO rebarbandinfo, *lpParam1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SendMessageA__IIILorg_eclipse_swt_internal_win32_REBARBANDINFO_2\n");
#endif

    if (lParam) {
        lpParam1 = &rebarbandinfo;
        cacheRebarbandinfoFids(env, lParam, &PGLOB(RebarbandinfoFc));
        getRebarbandinfoFields(env, lParam, lpParam1, &PGLOB(RebarbandinfoFc));
    }

    rc = (jint) SendMessageA((HWND)hWnd, Msg, wParam, (LPARAM)lpParam1);

    if (lParam) {
        setRebarbandinfoFields(env, lParam, lpParam1, &PGLOB(RebarbandinfoFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SendMessageW
 * Signature: (IIILorg/eclipse/swt/internal/win32/REBARBANDINFO;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SendMessageW__IIILorg_eclipse_swt_internal_win32_REBARBANDINFO_2
  (JNIEnv *env, jclass that, jint hWnd, jint Msg, jint wParam, jobject lParam)
{
	DECL_GLOB(pGlob)
    REBARBANDINFO rebarbandinfo, *lpParam1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SendMessageW__IIILorg_eclipse_swt_internal_win32_REBARBANDINFO_2\n");
#endif

    if (lParam) {
        lpParam1 = &rebarbandinfo;
        cacheRebarbandinfoFids(env, lParam, &PGLOB(RebarbandinfoFc));
        getRebarbandinfoFields(env, lParam, lpParam1, &PGLOB(RebarbandinfoFc));
    }

    rc = (jint) SendMessageW((HWND)hWnd, Msg, wParam, (LPARAM)lpParam1);

    if (lParam) {
        setRebarbandinfoFields(env, lParam, lpParam1, &PGLOB(RebarbandinfoFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SendMessageA
 * Signature: (IIILorg/eclipse/swt/internal/win32/RECT;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SendMessageA__IIILorg_eclipse_swt_internal_win32_RECT_2
  (JNIEnv *env, jclass that, jint hWnd, jint Msg, jint wParam, jobject lParam)
{
	DECL_GLOB(pGlob)
    RECT rect, *lpParam1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SendMessageA__IIILorg_eclipse_swt_internal_win32_RECT_2\n");
#endif

    if (lParam) {
        lpParam1 = &rect;
        cacheRectFids(env, lParam, &PGLOB(RectFc));
        getRectFields(env, lParam, lpParam1, &PGLOB(RectFc));
    }
    rc = (jint) SendMessageA((HWND)hWnd, Msg, wParam, (LPARAM)lpParam1);
    if (lParam) {
        setRectFields(env, lParam, lpParam1, &PGLOB(RectFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SendMessageW
 * Signature: (IIILorg/eclipse/swt/internal/win32/RECT;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SendMessageW__IIILorg_eclipse_swt_internal_win32_RECT_2
  (JNIEnv *env, jclass that, jint hWnd, jint Msg, jint wParam, jobject lParam)
{
	DECL_GLOB(pGlob)
    RECT rect, *lpParam1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SendMessageW__IIILorg_eclipse_swt_internal_win32_RECT_2\n");
#endif

    if (lParam) {
        lpParam1 = &rect;
        cacheRectFids(env, lParam, &PGLOB(RectFc));
        getRectFields(env, lParam, lpParam1, &PGLOB(RectFc));
    }
    rc = (jint) SendMessageW((HWND)hWnd, Msg, wParam, (LPARAM)lpParam1);
    if (lParam) {
        setRectFields(env, lParam, lpParam1, &PGLOB(RectFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SendMessageA
 * Signature: (IIILorg/eclipse/swt/internal/win32/TBBUTTON;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SendMessageA__IIILorg_eclipse_swt_internal_win32_TBBUTTON_2
  (JNIEnv *env, jclass that, jint hWnd, jint Msg, jint wParam, jobject lParam)
{
	DECL_GLOB(pGlob)
    TBBUTTON tbbutton, *lpParam1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SendMessageA__IIILorg_eclipse_swt_internal_win32_TBBUTTON_2\n");
#endif

    if (lParam) {
        lpParam1 = &tbbutton;
        cacheTbbuttonFids(env, lParam, &PGLOB(TbbuttonFc));
        getTbbuttonFields(env, lParam, lpParam1, &PGLOB(TbbuttonFc));
    }
    rc = (jint) SendMessageA((HWND)hWnd, Msg, wParam, (LPARAM)lpParam1);
    if (lParam) {
        setTbbuttonFields(env, lParam, lpParam1, &PGLOB(TbbuttonFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SendMessageW
 * Signature: (IIILorg/eclipse/swt/internal/win32/TBBUTTON;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SendMessageW__IIILorg_eclipse_swt_internal_win32_TBBUTTON_2
  (JNIEnv *env, jclass that, jint hWnd, jint Msg, jint wParam, jobject lParam)
{
	DECL_GLOB(pGlob)
    TBBUTTON tbbutton, *lpParam1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SendMessageW__IIILorg_eclipse_swt_internal_win32_TBBUTTON_2\n");
#endif

    if (lParam) {
        lpParam1 = &tbbutton;
        cacheTbbuttonFids(env, lParam, &PGLOB(TbbuttonFc));
        getTbbuttonFields(env, lParam, lpParam1, &PGLOB(TbbuttonFc));
    }
    rc = (jint) SendMessageW((HWND)hWnd, Msg, wParam, (LPARAM)lpParam1);
    if (lParam) {
        setTbbuttonFields(env, lParam, lpParam1, &PGLOB(TbbuttonFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SendMessageA
 * Signature: (IIILorg/eclipse/swt/internal/win32/TBBUTTONINFO;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SendMessageA__IIILorg_eclipse_swt_internal_win32_TBBUTTONINFO_2
  (JNIEnv *env, jclass that, jint hWnd, jint Msg, jint wParam, jobject lParam)
{
	DECL_GLOB(pGlob)
    TBBUTTONINFO tbbuttoninfo, *lpParam1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SendMessageA__IIILorg_eclipse_swt_internal_win32_TBBUTTONINFO_2\n");
#endif

    if (lParam) {
        lpParam1 = &tbbuttoninfo;
        cacheTbbuttoninfoFids(env, lParam, &PGLOB(TbbuttoninfoFc));
        getTbbuttoninfoFields(env, lParam, lpParam1, &PGLOB(TbbuttoninfoFc));
    }
    rc = (jint) SendMessageA((HWND)hWnd, Msg, wParam, (LPARAM)lpParam1);

    if (lParam) {
        setTbbuttoninfoFields(env, lParam, lpParam1, &PGLOB(TbbuttoninfoFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SendMessageW
 * Signature: (IIILorg/eclipse/swt/internal/win32/TBBUTTONINFO;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SendMessageW__IIILorg_eclipse_swt_internal_win32_TBBUTTONINFO_2
  (JNIEnv *env, jclass that, jint hWnd, jint Msg, jint wParam, jobject lParam)
{
	DECL_GLOB(pGlob)
    TBBUTTONINFO tbbuttoninfo, *lpParam1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SendMessageW__IIILorg_eclipse_swt_internal_win32_TBBUTTONINFO_2\n");
#endif

    if (lParam) {
        lpParam1 = &tbbuttoninfo;
        cacheTbbuttoninfoFids(env, lParam, &PGLOB(TbbuttoninfoFc));
        getTbbuttoninfoFields(env, lParam, lpParam1, &PGLOB(TbbuttoninfoFc));
    }
    rc = (jint) SendMessageW((HWND)hWnd, Msg, wParam, (LPARAM)lpParam1);

    if (lParam) {
        setTbbuttoninfoFields(env, lParam, lpParam1, &PGLOB(TbbuttoninfoFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SendMessageA
 * Signature: (IIILorg/eclipse/swt/internal/win32/TCITEM;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SendMessageA__IIILorg_eclipse_swt_internal_win32_TCITEM_2
  (JNIEnv *env, jclass that, jint hWnd, jint Msg, jint wParam, jobject lParam)
{
	DECL_GLOB(pGlob)
    TCITEM tcitem, *lpParam1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SendMessageA__IIILorg_eclipse_swt_internal_win32_TCITEM_2\n");
#endif

    if (lParam) {
        lpParam1 = &tcitem;
        cacheTcitemFids(env, lParam, &PGLOB(TcitemFc));
        getTcitemFields(env, lParam, lpParam1, &PGLOB(TcitemFc));
    }
    rc = (jint) SendMessageA((HWND)hWnd, Msg, wParam, (LPARAM)lpParam1);
    if (lParam) {
        setTcitemFields(env, lParam, lpParam1, &PGLOB(TcitemFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SendMessageW
 * Signature: (IIILorg/eclipse/swt/internal/win32/TCITEM;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SendMessageW__IIILorg_eclipse_swt_internal_win32_TCITEM_2
  (JNIEnv *env, jclass that, jint hWnd, jint Msg, jint wParam, jobject lParam)
{
	DECL_GLOB(pGlob)
    TCITEM tcitem, *lpParam1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SendMessageW__IIILorg_eclipse_swt_internal_win32_TCITEM_2\n");
#endif

    if (lParam) {
        lpParam1 = &tcitem;
        cacheTcitemFids(env, lParam, &PGLOB(TcitemFc));
        getTcitemFields(env, lParam, lpParam1, &PGLOB(TcitemFc));
    }
    rc = (jint) SendMessageW((HWND)hWnd, Msg, wParam, (LPARAM)lpParam1);
    if (lParam) {
        setTcitemFields(env, lParam, lpParam1, &PGLOB(TcitemFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SendMessageA
 * Signature: (IIILorg/eclipse/swt/internal/win32/TVHITTESTINFO;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SendMessageA__IIILorg_eclipse_swt_internal_win32_TVHITTESTINFO_2
  (JNIEnv *env, jclass that, jint hWnd, jint Msg, jint wParam, jobject lParam)
{
	DECL_GLOB(pGlob)
    TVHITTESTINFO tvhittestinfo, *lpParam1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SendMessageA__IIILorg_eclipse_swt_internal_win32_TVHITTESTINFO_2\n");
#endif

    if (lParam) {
        lpParam1 = &tvhittestinfo;
        cacheTvhittestinfoFids(env, lParam, &PGLOB(TvhittestinfoFc));
        getTvhittestinfoFields(env, lParam, lpParam1, &PGLOB(TvhittestinfoFc));
    }
    rc = (jint) SendMessageA((HWND)hWnd, Msg, wParam, (LPARAM)lpParam1);
    if (lParam) {
        setTvhittestinfoFields(env, lParam, lpParam1, &PGLOB(TvhittestinfoFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SendMessageW
 * Signature: (IIILorg/eclipse/swt/internal/win32/TVHITTESTINFO;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SendMessageW__IIILorg_eclipse_swt_internal_win32_TVHITTESTINFO_2
  (JNIEnv *env, jclass that, jint hWnd, jint Msg, jint wParam, jobject lParam)
{
	DECL_GLOB(pGlob)
    TVHITTESTINFO tvhittestinfo, *lpParam1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SendMessageW__IIILorg_eclipse_swt_internal_win32_TVHITTESTINFO_2\n");
#endif

    if (lParam) {
        lpParam1 = &tvhittestinfo;
        cacheTvhittestinfoFids(env, lParam, &PGLOB(TvhittestinfoFc));
        getTvhittestinfoFields(env, lParam, lpParam1, &PGLOB(TvhittestinfoFc));
    }
    rc = (jint) SendMessageW((HWND)hWnd, Msg, wParam, (LPARAM)lpParam1);
    if (lParam) {
        setTvhittestinfoFields(env, lParam, lpParam1, &PGLOB(TvhittestinfoFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SendMessageA
 * Signature: (IIILorg/eclipse/swt/internal/win32/TVINSERTSTRUCT;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SendMessageA__IIILorg_eclipse_swt_internal_win32_TVINSERTSTRUCT_2
  (JNIEnv *env, jclass that, jint hWnd, jint Msg, jint wParam, jobject lParam)
{
	DECL_GLOB(pGlob)
    TVINSERTSTRUCT tvinsertstruct, *lpParam1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SendMessageA__IIILorg_eclipse_swt_internal_win32_TVINSERTSTRUCT_2\n");
#endif

    if (lParam) {
        lpParam1 = &tvinsertstruct;
        cacheTvinsertstructFids(env, lParam, &PGLOB(TvinsertstructFc));
        getTvinsertstructFields(env, lParam, lpParam1, &PGLOB(TvinsertstructFc));
    }
    rc = (jint) SendMessageA((HWND)hWnd, Msg, wParam, (LPARAM)lpParam1);
    if (lParam) {
        setTvinsertstructFields(env, lParam, lpParam1, &PGLOB(TvinsertstructFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SendMessageW
 * Signature: (IIILorg/eclipse/swt/internal/win32/TVINSERTSTRUCT;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SendMessageW__IIILorg_eclipse_swt_internal_win32_TVINSERTSTRUCT_2
  (JNIEnv *env, jclass that, jint hWnd, jint Msg, jint wParam, jobject lParam)
{
	DECL_GLOB(pGlob)
    TVINSERTSTRUCT tvinsertstruct, *lpParam1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SendMessageW__IIILorg_eclipse_swt_internal_win32_TVINSERTSTRUCT_2\n");
#endif

    if (lParam) {
        lpParam1 = &tvinsertstruct;
        cacheTvinsertstructFids(env, lParam, &PGLOB(TvinsertstructFc));
        getTvinsertstructFields(env, lParam, lpParam1, &PGLOB(TvinsertstructFc));
    }
    rc = (jint) SendMessageW((HWND)hWnd, Msg, wParam, (LPARAM)lpParam1);
    if (lParam) {
        setTvinsertstructFields(env, lParam, lpParam1, &PGLOB(TvinsertstructFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SendMessageA
 * Signature: (IIILorg/eclipse/swt/internal/win32/TVITEM;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SendMessageA__IIILorg_eclipse_swt_internal_win32_TVITEM_2
  (JNIEnv *env, jclass that, jint hWnd, jint Msg, jint wParam, jobject lParam)
{
	DECL_GLOB(pGlob)
    TVITEM tvitem, *lpParam1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SendMessageA__IIILorg_eclipse_swt_internal_win32_TVITEM_2\n");
#endif

    if (lParam) {
        lpParam1 = &tvitem;
        cacheTvitemFids(env, lParam, &PGLOB(TvitemFc));
        getTvitemFields(env, lParam, lpParam1, &PGLOB(TvitemFc));
    }
    rc = (jint) SendMessageA((HWND)hWnd, Msg, wParam, (LPARAM)lpParam1);
    if (lParam) {
        setTvitemFields(env, lParam, lpParam1, &PGLOB(TvitemFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SendMessageW
 * Signature: (IIILorg/eclipse/swt/internal/win32/TVITEM;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SendMessageW__IIILorg_eclipse_swt_internal_win32_TVITEM_2
  (JNIEnv *env, jclass that, jint hWnd, jint Msg, jint wParam, jobject lParam)
{
	DECL_GLOB(pGlob)
    TVITEM tvitem, *lpParam1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SendMessageW__IIILorg_eclipse_swt_internal_win32_TVITEM_2\n");
#endif

    if (lParam) {
        lpParam1 = &tvitem;
        cacheTvitemFids(env, lParam, &PGLOB(TvitemFc));
        getTvitemFields(env, lParam, lpParam1, &PGLOB(TvitemFc));
    }
    rc = (jint) SendMessageW((HWND)hWnd, Msg, wParam, (LPARAM)lpParam1);
    if (lParam) {
        setTvitemFields(env, lParam, lpParam1, &PGLOB(TvitemFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SetActiveWindow
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SetActiveWindow
  (JNIEnv *env, jclass that, jint hWnd)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SetActiveWindow\n");
#endif

    return (jint) SetActiveWindow((HWND) hWnd);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SetBkColor
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SetBkColor
  (JNIEnv *env, jclass that, jint hdc, jint crColor)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SetBkColor\n");
#endif

    return (jint) SetBkColor((HDC)hdc, (COLORREF)crColor);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SetBkMode
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SetBkMode
  (JNIEnv *env, jclass that, jint hdc, jint iBkMode)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SetBkMode\n");
#endif
    return (jint) SetBkMode((HDC)hdc, iBkMode);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SetCapture
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SetCapture
  (JNIEnv *env, jclass that, jint hWnd)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SetCapture\n");
#endif

    return (jint) SetCapture((HWND)hWnd);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SetCaretPos
 * Signature: (II)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_SetCaretPos
  (JNIEnv *env, jclass that, jint X, jint Y)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SetCaretPos\n");
#endif

    return (jboolean) SetCaretPos(X, Y);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SetClipboardData
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SetClipboardData
  (JNIEnv *env,  jclass that, jint uFormat, jint hMem)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SetClipboardData\n");
#endif
    return (jint) SetClipboardData(uFormat, (HANDLE)hMem);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SetCursor
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SetCursor
  (JNIEnv *env, jclass that, jint hCursor)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SetCursor\n");
#endif

    return (jint) SetCursor((HCURSOR)hCursor);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SetFocus
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SetFocus
  (JNIEnv *env, jclass that, jint hWnd)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SetFocus\n");
#endif

    return (jint) SetFocus((HWND)hWnd);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SetMenuItemInfoA
 * Signature: (IIZLorg/eclipse/swt/internal/win32/MENUITEMINFO;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_SetMenuItemInfoA
  (JNIEnv *env, jclass that, jint hMenu, jint uItem, jboolean fByPosition, jobject lpmii)
{
	DECL_GLOB(pGlob)
    MENUITEMINFO mii1, *lpmii1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SetMenuItemInfoA\n");
#endif

    if (lpmii) {
        lpmii1 = &mii1;
        cacheMenuiteminfoFids(env, lpmii, &PGLOB(MenuiteminfoFc));
        getMenuiteminfoFields(env, lpmii, lpmii1, &PGLOB(MenuiteminfoFc));
    }
    rc = (jboolean) SetMenuItemInfoA((HMENU)hMenu, uItem, fByPosition, lpmii1);
    if (lpmii) {
        setMenuiteminfoFields(env, lpmii, lpmii1, &PGLOB(MenuiteminfoFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SetMenuItemInfoW
 * Signature: (IIZLorg/eclipse/swt/internal/win32/MENUITEMINFO;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_SetMenuItemInfoW
  (JNIEnv *env, jclass that, jint hMenu, jint uItem, jboolean fByPosition, jobject lpmii)
{
	DECL_GLOB(pGlob)
    MENUITEMINFO mii1, *lpmii1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SetMenuItemInfoW\n");
#endif

    if (lpmii) {
        lpmii1 = &mii1;
        cacheMenuiteminfoFids(env, lpmii, &PGLOB(MenuiteminfoFc));
        getMenuiteminfoFields(env, lpmii, lpmii1, &PGLOB(MenuiteminfoFc));
    }
    rc = (jboolean) SetMenuItemInfoW((HMENU)hMenu, uItem, fByPosition, (LPMENUITEMINFOW)lpmii1);
    if (lpmii) {
        setMenuiteminfoFields(env, lpmii, lpmii1, &PGLOB(MenuiteminfoFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SetPaletteEntries
 * Signature: (III[B)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SetPaletteEntries
  (JNIEnv *env, jclass that, jint hPal, jint iStart, jint cEntries, jbyteArray lppe)
{
    PALETTEENTRY *lppe1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SetPaletteEntries\n");
#endif

    if (lppe)
        lppe1 = (PALETTEENTRY *)(*env)->GetByteArrayElements(env, lppe, NULL);

    rc = (jint) SetPaletteEntries((HPALETTE)hPal, iStart, cEntries, lppe1);

    if (lppe)
        (*env)->ReleaseByteArrayElements(env, lppe, (jbyte *)lppe1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SetParent
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SetParent
  (JNIEnv *env, jclass that, jint hWndChild, jint hWndNewParent)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SetParent\n");
#endif

    return (jint) SetParent((HWND)hWndChild, (HWND)hWndNewParent);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SetPixel
 * Signature: (IIII)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SetPixel
  (JNIEnv *env, jclass that, jint hDC, jint X, jint Y, jint crColor)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SetPixel\n");
#endif

    return (jint) SetPixel((HDC) hDC, X, Y, crColor);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SetRect
 * Signature: (Lorg/eclipse/swt/internal/win32/RECT;IIII)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_SetRect
  (JNIEnv *env, jclass that, jobject lprc, jint xLeft, jint yTop, jint xRight, jint yBottom)
{
	DECL_GLOB(pGlob)
    RECT rect, *lprc1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SetRect\n");
#endif

    if (lprc) {
        lprc1 = &rect;
        cacheRectFids(env, lprc, &PGLOB(RectFc));
        getRectFields(env, lprc, lprc1, &PGLOB(RectFc));
    }
    rc = (jboolean) SetRect(lprc1, xLeft, yTop, xRight, yBottom);

    if (lprc) {
        setRectFields(env, lprc, lprc1, &PGLOB(RectFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SetRectRgn
 * Signature: (IIIII)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_SetRectRgn
  (JNIEnv *env, jclass that, jint hrgn, jint nLeftRect, jint nTopRect, jint nRightRect, jint nBottomRect)
{
    return (jboolean) SetRectRgn((HRGN)hrgn, nLeftRect, nTopRect, nRightRect, nBottomRect);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SetROP2
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SetROP2
  (JNIEnv *env, jclass that, jint hdc, jint fnDrawMode)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SetROP2\n");
#endif
    return (jint) SetROP2((HDC)hdc, fnDrawMode);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SetScrollInfo
 * Signature: (IILorg/eclipse/swt/internal/win32/SCROLLINFO;Z)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_SetScrollInfo
  (JNIEnv *env, jclass that, jint hWnd, jint fnBar, jobject lpsi, jboolean fRedraw)
{
	DECL_GLOB(pGlob)
    SCROLLINFO si1, *lpsi1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SetScrollInfo\n");
#endif

    if (lpsi) {
        lpsi1 = &si1;
        cacheScrollinfoFids(env, lpsi, &PGLOB(ScrollinfoFc));
        getScrollinfoFields(env, lpsi, lpsi1, &PGLOB(ScrollinfoFc));
    }
    rc = (jboolean) SetScrollInfo((HWND)hWnd, fnBar, lpsi1, fRedraw);
    if (lpsi) {
        setScrollinfoFields(env, lpsi, lpsi1, &PGLOB(ScrollinfoFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SetTextColor
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SetTextColor
  (JNIEnv *env, jclass that, jint hdc, jint crColor)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SetTextColor\n");
#endif

    return (jint) SetTextColor((HDC)hdc, (COLORREF)crColor);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SetWindowLongA
 * Signature: (III)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SetWindowLongA
  (JNIEnv *env, jclass that, jint hWnd, jint nIndex, jint dwNewLong)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SetWindowLongA\n");
#endif

     return (jint) SetWindowLongA((HWND)hWnd, nIndex,dwNewLong);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SetWindowLongW
 * Signature: (III)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SetWindowLongW
  (JNIEnv *env, jclass that, jint hWnd, jint nIndex, jint dwNewLong)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SetWindowLongW\n");
#endif

     return (jint) SetWindowLongW((HWND)hWnd, nIndex,dwNewLong);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SetWindowPos
 * Signature: (IIIIIII)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_SetWindowPos
  (JNIEnv *env, jclass that, jint hWnd, jint hWndInsertAfter, jint X, jint Y, jint cx, jint cy, jint uFlags)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SetWindowPos\n");
#endif

    return (jboolean) SetWindowPos((HWND)hWnd, (HWND)hWndInsertAfter, X, Y, cx, cy, uFlags);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SetWindowTextA
 * Signature: (I[B)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_SetWindowTextA
  (JNIEnv *env, jclass that, jint hWnd, jbyteArray lpString)
{
    jbyte* lpString1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SetWindowTextA\n");
#endif

    if (lpString)
        lpString1 = (*env)->GetByteArrayElements(env, lpString, NULL);

    rc = (jboolean) SetWindowTextA((HWND)hWnd, (LPSTR)lpString1);

    if (lpString)
        (*env)->ReleaseByteArrayElements(env, lpString, lpString1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SetWindowTextW
 * Signature: (I[C)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_SetWindowTextW
  (JNIEnv *env, jclass that, jint hWnd, jcharArray lpString)
{
    jchar* lpString1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SetWindowTextW\n");
#endif

    if (lpString)
        lpString1 = (*env)->GetCharArrayElements(env, lpString, NULL);

    rc = (jboolean) SetWindowTextW((HWND)hWnd, (LPWSTR)lpString1);

    if (lpString)
        (*env)->ReleaseCharArrayElements(env, lpString, lpString1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SHGetMalloc
 * Signature: ([I)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SHGetMalloc
  (JNIEnv *env, jclass that, jintArray ppMalloc)
{
    LPMALLOC *ppMalloc1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SHGetMalloc\n");
#endif

    if (ppMalloc)
        ppMalloc1 = (LPMALLOC *)(*env)->GetIntArrayElements(env, ppMalloc, NULL);

    rc = (jint) SHGetMalloc(ppMalloc1);

    if (ppMalloc)
        (*env)->ReleaseIntArrayElements(env, ppMalloc, (jint *)ppMalloc1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SHGetPathFromIDListA
 * Signature: (I[B)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_SHGetPathFromIDListA
  (JNIEnv *env, jclass that, jint pidl, jbyteArray pszPath)
{
    jbyte* pszPath1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SHGetPathFromIDList\n");
#endif

    if (pszPath)
        pszPath1 = (*env)->GetByteArrayElements(env,pszPath, NULL);

    rc = (jboolean)SHGetPathFromIDList((LPCITEMIDLIST)pidl, (LPSTR)pszPath1);

    if (pszPath)
        (*env)->ReleaseByteArrayElements(env, pszPath, pszPath1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ShowCaret
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_ShowCaret
  (JNIEnv *env, jclass that, jint hWnd)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "ShowCaret\n");
#endif

    return (jboolean) ShowCaret((HWND)hWnd);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ShowWindow
 * Signature: (II)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_ShowWindow
  (JNIEnv *env, jclass that, jint hWnd, jint nCmdShow)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "ShowWindow\n");
#endif

    return (jboolean) ShowWindow((HWND)hWnd, nCmdShow);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    StretchBlt
 * Signature: (IIIIIIIIIII)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_StretchBlt
  (JNIEnv *env, jclass that, jint hdcDest, jint nxOriginDest, jint nyOriginDest, jint nWidthDest, jint nHeightDest,
                             jint hdcSrc, jint nXOriginSrc, jint nYOriginSrc, jint nWidthSrc, jint nHeightSrc, jint dwRop)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "StretchBlt\n");
#endif

    return (jboolean) StretchBlt((HDC)hdcDest, nxOriginDest, nyOriginDest, nWidthDest, nHeightDest,
                                 (HDC)hdcSrc, nXOriginSrc, nYOriginSrc, nWidthSrc, nHeightSrc, dwRop);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    TrackPopupMenu
 * Signature: (IIIIIILorg/eclipse/swt/internal/win32/RECT;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_TrackPopupMenu
  (JNIEnv *env, jclass that, jint hMenu, jint uFlags, jint x, jint y, jint nReserved, jint hWnd, jobject lpRect)
{
	DECL_GLOB(pGlob)
    RECT rect, *lpRect1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "TrackPopupMenu\n");
#endif

    if (lpRect) {
        lpRect1 = &rect;
        cacheRectFids(env, lpRect, &PGLOB(RectFc));
        getRectFields(env, lpRect, lpRect1, &PGLOB(RectFc));
    }
    rc = (jboolean) TrackPopupMenu((HMENU)hMenu, uFlags, x, y, nReserved, (HWND)hWnd, lpRect1);
    if (lpRect) {
        setRectFields(env, lpRect, lpRect1, &PGLOB(RectFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    TranslateAcceleratorA
 * Signature: (IILorg/eclipse/swt/internal/win32/MSG;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_TranslateAcceleratorA
  (JNIEnv *env, jclass that, jint hWnd, jint hAccTable, jobject lpMsg)
{
	DECL_GLOB(pGlob)
    MSG callBack, *lpMsg1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "TranslateAcceleratorA\n");
#endif

    if (lpMsg) {
        lpMsg1 = &callBack;
        cacheMsgFids(env, lpMsg, &PGLOB(MsgFc));
        getMsgFields(env, lpMsg, lpMsg1, &PGLOB(MsgFc));
    }
    rc = (jint)TranslateAcceleratorA((HWND)hWnd, (HACCEL)hAccTable, lpMsg1);
    if (lpMsg) {
        setMsgFields(env, lpMsg, lpMsg1, &PGLOB(MsgFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    TranslateAcceleratorW
 * Signature: (IILorg/eclipse/swt/internal/win32/MSG;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_TranslateAcceleratorW
  (JNIEnv *env, jclass that, jint hWnd, jint hAccTable, jobject lpMsg)
{
	DECL_GLOB(pGlob)
    MSG callBack, *lpMsg1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "TranslateAcceleratorW\n");
#endif

    if (lpMsg) {
        lpMsg1 = &callBack;
        cacheMsgFids(env, lpMsg, &PGLOB(MsgFc));
        getMsgFields(env, lpMsg, lpMsg1, &PGLOB(MsgFc));
    }
    rc = (jint)TranslateAcceleratorW((HWND)hWnd, (HACCEL)hAccTable, lpMsg1);
    if (lpMsg) {
        setMsgFields(env, lpMsg, lpMsg1, &PGLOB(MsgFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    TranslateMessage
 * Signature: (Lorg/eclipse/swt/internal/win32/MSG;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_TranslateMessage
  (JNIEnv *env, jclass that, jobject lpMsg)
{
	DECL_GLOB(pGlob)
    MSG callBack, *lpMsg1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "TranslateMessage\n");
#endif

    if (lpMsg) {
        lpMsg1 = &callBack;
        cacheMsgFids(env, lpMsg, &PGLOB(MsgFc));
        getMsgFields(env, lpMsg, lpMsg1, &PGLOB(MsgFc));
    }
    rc = (jboolean)TranslateMessage(lpMsg1);
    if (lpMsg) {
        setMsgFields(env, lpMsg, lpMsg1, &PGLOB(MsgFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    UnregisterClassA
 * Signature: ([BI)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_UnregisterClassA
  (JNIEnv *env, jclass that, jbyteArray lpClassName, jint hInstance)
{
    jbyte* lpClassName1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "UnregisterClassA\n");
#endif

    if (lpClassName)
        lpClassName1 = (*env)->GetByteArrayElements(env,lpClassName, NULL);

    rc = (jboolean)UnregisterClassA((LPSTR)lpClassName1, (HINSTANCE)hInstance);

    if (lpClassName)
        (*env)->ReleaseByteArrayElements(env, lpClassName, lpClassName1, 0);
    return rc;
}


/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    UnregisterClassW
 * Signature: ([BI)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_UnregisterClassW
  (JNIEnv *env, jclass that, jcharArray lpClassName, jint hInstance)
{
    jchar* lpClassName1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "UnregisterClassW\n");
#endif

    if (lpClassName)
        lpClassName1 = (*env)->GetCharArrayElements(env,lpClassName, NULL);

    rc = (jboolean)UnregisterClassW((LPWSTR)lpClassName1, (HINSTANCE)hInstance);

    if (lpClassName)
        (*env)->ReleaseCharArrayElements(env, lpClassName, lpClassName1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    UpdateWindow
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_UpdateWindow
  (JNIEnv *env, jclass that, jint hWnd)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "UpdateWindow\n");
#endif

    return (jboolean) UpdateWindow((HWND) hWnd);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ValidateRect
 * Signature: (ILorg/eclipse/swt/internal/win32/RECT;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_ValidateRect
  (JNIEnv *env, jclass that, jint hWnd, jobject lpRect)
{
	DECL_GLOB(pGlob)
    RECT rect, *lpRect1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "ValidateRect\n");
#endif

    if (lpRect) {
        lpRect1 = &rect;
        cacheRectFids(env, lpRect, &PGLOB(RectFc));
        getRectFields(env, lpRect, lpRect1, &PGLOB(RectFc));
    }
    rc = (jboolean) ValidateRect((HWND)hWnd, lpRect1);
    if (lpRect) {
        setRectFields(env, lpRect, lpRect1, &PGLOB(RectFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    WideCharToMultiByte
 * Signature: (II[CI[BI[B[Z)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_WideCharToMultiByte
  (JNIEnv *env, jclass that,
   jint CodePage,  jint dwFlags, jcharArray lpWideCharStr, jint cchWideChar, 
   jbyteArray lpMultiByteCharStr, jint cchMultiByte, jbyteArray lpDefaultChar,
   jbooleanArray lpUsedDefaultChar)
{
    LPCWSTR lpWideCharStr1=NULL;
    LPSTR lpMultiByteCharStr1=NULL;
    LPCSTR lpDefaultChar1=NULL;
    LPBOOL lpUsedDefaultChar1=NULL;
    
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "WideCharToMultiByte\n");
#endif

    if (lpWideCharStr)
        lpWideCharStr1 = (LPWSTR)(*env)->GetCharArrayElements(env, lpWideCharStr, NULL);
    if (lpMultiByteCharStr)
        lpMultiByteCharStr1 = (LPSTR)(*env)->GetByteArrayElements(env, lpMultiByteCharStr, NULL);
    if (lpDefaultChar)
        lpDefaultChar1 = (*env)->GetByteArrayElements(env, lpDefaultChar, NULL);
    if (lpUsedDefaultChar)
        lpUsedDefaultChar1 = (LPBOOL)(*env)->GetBooleanArrayElements(env,lpUsedDefaultChar, NULL);

    rc = (jint) WideCharToMultiByte(CodePage, (DWORD)dwFlags, lpWideCharStr1, cchWideChar, lpMultiByteCharStr1,
                                        cchMultiByte, lpDefaultChar1, lpUsedDefaultChar1);
    if (lpWideCharStr)
        (*env)->ReleaseCharArrayElements(env, lpWideCharStr, (jchar *)lpWideCharStr1, 0);
    if (lpMultiByteCharStr)
        (*env)->ReleaseByteArrayElements(env, lpMultiByteCharStr, (jbyte *)lpMultiByteCharStr1, 0);
    if (lpDefaultChar)
        (*env)->ReleaseByteArrayElements(env, lpDefaultChar, (jbyte *)lpDefaultChar1, 0);
    if (lpUsedDefaultChar)
        (*env)->ReleaseBooleanArrayElements(env, lpUsedDefaultChar, (jboolean *)lpUsedDefaultChar1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    WindowFromPoint
 * Signature: (Lorg/eclipse/swt/internal/win32/POINT;)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_WindowFromPoint
  (JNIEnv *env, jclass that, jobject lpPoint)
{
	DECL_GLOB(pGlob)
    POINT point, *lpPoint1=NULL;
    jint rc;
    
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "WindowFromPoint\n");
#endif

    if (lpPoint) {
        lpPoint1 = &point;
        cachePointFids(env, lpPoint, &PGLOB(PointFc));
        getPointFields(env, lpPoint, lpPoint1, &PGLOB(PointFc));
    }
    rc = (jint) WindowFromPoint(point);
    if (lpPoint) {
        setPointFields(env, lpPoint, lpPoint1, &PGLOB(PointFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ChildWindowFromPoint
 * Signature: (ILorg/eclipse/swt/internal/win32/POINT;)I
 */
/*
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_ChildWindowFromPoint
  (JNIEnv *env, jclass that, jint hWndParent, jobject lpPoint)
{
    POINT point, *lpPoint1=NULL;
    jint rc;
    
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "ChildWindowFromPoint\n");
#endif

    if (lpPoint) {
        lpPoint1 = &point;
        cachePointFids(env, lpPoint, &PointFc);
        getPointFields(env, lpPoint, lpPoint1, &PointFc);
    }
    rc = (jint) ChildWindowFromPoint((HWND)hWndParent, point);
    if (lpPoint) {
        setPointFields(env, lpPoint, lpPoint1, &PointFc);
    }
    return rc;
}
*/

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetClassLong
 * Signature: (II)I
 */
/* JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetClassLong
  (JNIEnv *env, jclass that, jint hWnd, jint nIndex)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetClassLong\n");
#endif

    return (jint)GetClassLong((HWND)hWnd, nIndex);
}
*/
/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetCaretBlinkTime
 * Signature: ()I
 */
/* JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetCaretBlinkTime
  (JNIEnv *env, jclass that)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetCaretBlinkTime\n");
#endif

    return (jint)GetCaretBlinkTime();
}
*/
/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    CopyAcceleratorTable
 * Signature: (I[BI)I
 */
/* JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_CopyAcceleratorTable
  (JNIEnv *env, jclass that, jint hAccelSrc, jbyteArray lpAccelDst, jint cAccelEntries)
{
    LPACCEL lpAccelDst1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "CopyAcceleratorTable\n");
#endif

    if (lpAccelDst)
        lpAccelDst1 = (LPACCEL)(*env)->GetByteArrayElements(env,lpAccelDst, NULL);

    rc = (jint)CopyAcceleratorTable((HACCEL)hAccelSrc, (LPACCEL)lpAccelDst1, cAccelEntries);

    if (lpAccelDst)
        (*env)->ReleaseByteArrayElements(env, lpAccelDst, (jbyte *)lpAccelDst1, 0);
    return rc;
}
*/
/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    EqualRect
 * Signature: (Lorg/eclipse/swt/internal/win32/RECT;Lorg/eclipse/swt/internal/win32/RECT;)Z
 */
/* JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_EqualRect
  (JNIEnv *env, jclass that, jobject lprc1, jobject lprc2)
{
    RECT rect1, rect2, *lprc11=NULL, *lprc21=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "EqualRect\n");
#endif

    if (lprc1 || lprc2) {
        if (lprc1) {
            cacheRectFids(env, lprc1, &RectFc);
        } 
        else if (lprc2) {
            cacheRectFids(env, lprc2, &RectFc);
        }
    }

    if (lprc1) {
        lprc11 = &rect1;
        getRectFields(env, lprc1, lprc11, &RectFc);
    }
    if (lprc2) {
        lprc21 = &rect2;
        getRectFields(env, lprc2, lprc21, &RectFc);
    }
    rc = (jboolean) EqualRect(lprc11, lprc21);
    if (lprc1) {
        setRectFields(env, lprc1, lprc11, &RectFc);
    }
    if (lprc2) {
        setRectFields(env, lprc2, lprc21, &RectFc);
    }
    return rc;
}
*/

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetDlgCtrlID
 * Signature: (I)I
 */
/* JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetDlgCtrlID
  (JNIEnv *env, jclass that, jint hwndCtl)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetDlgCtrlID\n");
#endif

    return (jint)GetDlgCtrlID((HWND)hwndCtl);
}
*/

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetTextExtentPoint32A
 * Signature: (I[BILorg/eclipse/swt/internal/win32/SIZE;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_GetTextExtentPoint32A
  (JNIEnv *env, jclass that, jint hdc, jbyteArray lpString, jint cbString, jobject lpSize)
{
	DECL_GLOB(pGlob)
    jbyte* lpString1=NULL;
    SIZE size, *lpSize1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetTextExtentPoint32A\n");
#endif

    if (lpString)
        lpString1 = (*env)->GetByteArrayElements(env, lpString, NULL);

    if (lpSize) {
        lpSize1=&size;
        cacheSizeFids(env, lpSize, &PGLOB(SizeFc));
        getSizeFields(env, lpSize, lpSize1, &PGLOB(SizeFc));
    }
    rc = (jboolean) GetTextExtentPoint32A((HDC)hdc, (LPSTR)lpString1, cbString, lpSize1);

    if (lpSize) {
        setSizeFields(env, lpSize, lpSize1, &PGLOB(SizeFc));
    }
    
    if (lpString)
        (*env)->ReleaseByteArrayElements(env, lpString, lpString1, 0);
    return rc;    
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetTextExtentPoint32W
 * Signature: (I[CILorg/eclipse/swt/internal/win32/SIZE;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_GetTextExtentPoint32W
  (JNIEnv *env, jclass that, jint hdc, jcharArray lpString, jint cbString, jobject lpSize)
{
	DECL_GLOB(pGlob)
    jchar* lpString1=NULL;
    SIZE size, *lpSize1=NULL;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetTextExtentPoint32W\n");
#endif

    if (lpString)
        lpString1 = (*env)->GetCharArrayElements(env, lpString, NULL);

    if (lpSize) {
        lpSize1=&size;
        cacheSizeFids(env, lpSize, &PGLOB(SizeFc));
        getSizeFields(env, lpSize, lpSize1, &PGLOB(SizeFc));
    }
    rc = (jboolean) GetTextExtentPoint32W((HDC)hdc, (LPWSTR)lpString1, cbString, lpSize1);

    if (lpSize) {
        setSizeFields(env, lpSize, lpSize1, &PGLOB(SizeFc));
    }
    
    if (lpString)
        (*env)->ReleaseCharArrayElements(env, lpString, lpString1, 0);
    return rc;    
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    IntersectRect
 * Signature: (Lorg/eclipse/swt/internal/win32/RECT;Lorg/eclipse/swt/internal/win32/RECT;Lorg/eclipse/swt/internal/win32/RECT;)Z
 */
/* JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_IntersectRect
  (JNIEnv *env, jclass that, jobject lprcDst, jobject lprcSrc1, jobject lprcSrc2)
{
    RECT rect1, rect2, rect3;
    RECT *lprcDst1=NULL, *lprcSrc11=NULL, *lprcSrc21=NULL;
    jobject lpRect;
    jboolean rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "IntersectRect\n");
#endif

    if (lprcDst || lprcSrc1 || lprcSrc2) {
        if (lprcDst) {
            lpRect = lprcDst;
        } 
        else if (lprcSrc1) {
            lpRect = lprcSrc1;
        }
        else if (lprcSrc2) {
            lpRect = lprcSrc2;
        }
        cacheRectFids(env, lpRect, &RectFc);
    }

    if (lprcDst) {
        lprcDst1 = &rect1;

        lprcDst1->left = (*env)->GetIntField(env,lprcDst,RectFc.left);
        lprcDst1->top = (*env)->GetIntField(env,lprcDst,RectFc.top);
        lprcDst1->right = (*env)->GetIntField(env,lprcDst,RectFc.right);
        lprcDst1->bottom = (*env)->GetIntField(env,lprcDst,RectFc.bottom);
    }
    if (lprcSrc1) {
        lprcSrc11 = &rect2;

        lprcSrc11->left = (*env)->GetIntField(env,lprcSrc1,RectFc.left);
        lprcSrc11->top = (*env)->GetIntField(env,lprcSrc1,RectFc.top);
        lprcSrc11->right = (*env)->GetIntField(env,lprcSrc1,RectFc.right);
        lprcSrc11->bottom = (*env)->GetIntField(env,lprcSrc1,RectFc.bottom);
    }
    if (lprcSrc2) {
        lprcSrc21 = &rect3;

        lprcSrc21->left = (*env)->GetIntField(env,lprcSrc2,RectFc.left);
        lprcSrc21->top = (*env)->GetIntField(env,lprcSrc2,RectFc.top);
        lprcSrc21->right = (*env)->GetIntField(env,lprcSrc2,RectFc.right);
        lprcSrc21->bottom = (*env)->GetIntField(env,lprcSrc2,RectFc.bottom);
    }
    rc = (jboolean) IntersectRect(lprcDst1, lprcSrc11, lprcSrc21);
    if (lprcDst) {
        (*env)->SetIntField(env,lprcDst,RectFc.left,lprcDst1->left);
        (*env)->SetIntField(env,lprcDst,RectFc.top,lprcDst1->top);
        (*env)->SetIntField(env,lprcDst,RectFc.right, lprcDst1->right);
        (*env)->SetIntField(env,lprcDst,RectFc.bottom, lprcDst1->bottom);
    }
    if (lprcSrc1) {
        (*env)->SetIntField(env,lprcSrc1,RectFc.left,lprcSrc11->left);
        (*env)->SetIntField(env,lprcSrc1,RectFc.top,lprcSrc11->top);
        (*env)->SetIntField(env,lprcSrc1,RectFc.right, lprcSrc11->right);
        (*env)->SetIntField(env,lprcSrc1,RectFc.bottom, lprcSrc11->bottom);
    }
    if (lprcSrc2) {
        (*env)->SetIntField(env,lprcSrc2,RectFc.left,lprcSrc21->left);
        (*env)->SetIntField(env,lprcSrc2,RectFc.top,lprcSrc21->top);
        (*env)->SetIntField(env,lprcSrc2,RectFc.right, lprcSrc21->right);
        (*env)->SetIntField(env,lprcSrc2,RectFc.bottom, lprcSrc21->bottom);
    }
    return rc;
}
*/
/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    IsMenu
 * Signature: (I)Z
 */
/* JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_IsMenu
  (JNIEnv *env, jclass that, jint hMenu)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "IsMenu\n");
#endif

    return (jboolean) IsMenu((HMENU)hMenu);
}
*/
/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    IsWindow
 * Signature: (I)Z
 */
/* JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_IsWindow
  (JNIEnv *env, jclass that, jint hWnd)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "IsWindow\n");
#endif

    return (jboolean) IsWindow((HWND)hWnd);
}
*/
/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    KillTimer
 * Signature: (II)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_KillTimer
  (JNIEnv *env, jclass that, jint hWnd, jint uIDEvent)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "KillTimern\n");
#endif

    return (jboolean) KillTimer((HWND)hWnd, uIDEvent);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    LoadBitmap
 * Signature: (I[B)I
 */
/* JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_LoadBitmap__I_3B
  (JNIEnv *env, jclass that, jint hInstance, jbyteArray lpBitmapName)
{
    LPCTSTR lpBitmapName1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "LoadBitmap__I_3B\n");
#endif

    if (lpBitmapName)
        lpBitmapName1 = (*env)->GetByteArrayElements(env, lpBitmapName, NULL);

    rc = (jint) LoadBitmap((HINSTANCE)hInstance, lpBitmapName1);

    if (lpBitmapName)
        (*env)->ReleaseByteArrayElements(env, lpBitmapName, (jbyte *)lpBitmapName1, 0);
    return rc;
}
*/
/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    LoadCursor
 * Signature: (I[B)I
 */
/* JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_LoadCursor__I_3B
  (JNIEnv *env, jclass that, jint hInstance, jbyteArray lpCursorName)
{
    LPCTSTR lpCursorName1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "LoadCursor__I_3B\n");
#endif

    if (lpCursorName)
        lpCursorName1 = (*env)->GetByteArrayElements(env, lpCursorName, NULL);

    rc = (jint) LoadCursor((HINSTANCE)hInstance, lpCursorName1);

    if (lpCursorName)
        (*env)->ReleaseByteArrayElements(env, lpCursorName, (jbyte *)lpCursorName1, 0);
        
    return rc;
}
*/
/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    LoadIcon
 * Signature: (I[B)I
 */
/* JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_LoadIcon__I_3B
  (JNIEnv *env, jclass that, jint hInstance, jbyteArray lpIconName)
{
    LPCTSTR lpIconName1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "LoadIcon__I_3B\n");
#endif

    if (lpIconName)
        lpIconName1 = (*env)->GetByteArrayElements(env, lpIconName, NULL);

    rc = (jint) LoadIcon((HINSTANCE)hInstance, lpIconName1);

    if (lpIconName)
        (*env)->ReleaseByteArrayElements(env, lpIconName, (jbyte *)lpIconName1, 0);
    return rc;
}
*/

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    LoadImageA
 * Signature: (I[BIIII)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_LoadImageA__I_3BIIII
  (JNIEnv *env, jclass that, jint hinst, jbyteArray lpszName, jint uType, jint cxDesired, jint cyDesired, jint fuLoad)
{
    jbyte* lpszName1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "LoadImageA__I_3BIIII\n");
#endif

    if (lpszName)
        lpszName1 = (*env)->GetByteArrayElements(env, lpszName, NULL);

    rc = (jint) LoadImageA((HINSTANCE)hinst, (LPSTR)lpszName1, uType, cxDesired, cyDesired, fuLoad);

    if (lpszName)
        (*env)->ReleaseByteArrayElements(env, lpszName, lpszName1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    LoadImageW
 * Signature: (I[CIIII)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_LoadImageW__I_3BIIII
  (JNIEnv *env, jclass that, jint hinst, jbyteArray lpszName, jint uType, jint cxDesired, jint cyDesired, jint fuLoad)
{
    jchar* lpszName1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "LoadImageW__I_3BIIII\n");
#endif

    if (lpszName)
        lpszName1 = (*env)->GetCharArrayElements(env, lpszName, NULL);

    rc = (jint) LoadImageW((HINSTANCE)hinst, (LPWSTR)lpszName1, uType, cxDesired, cyDesired, fuLoad);

    if (lpszName)
        (*env)->ReleaseCharArrayElements(env, lpszName, lpszName1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    LoadImage
 * Signature: (IIIIII)I
 */
/* JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_LoadImage__IIIIII
  (JNIEnv *env, jclass that, jint hinst, jint lpszName, jint uType, jint cxDesired, jint cyDesired, jint fuLoad)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "LoadImage__IIIIII\n");
#endif

    return (jint) LoadImage((HINSTANCE)hinst, (LPCTSTR)lpszName, uType, cxDesired, cyDesired, fuLoad);
}
*/
/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    MoveMemory
 * Signature: (Lorg/eclipse/swt/internal/win32/ACCEL;[BI)V
 */
/* JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_win32_OS_MoveMemory__Lorg_eclipse_swt_internal_win32_ACCEL_2_3BI
  (JNIEnv *env, jclass that, jobject lpDestination, jbyteArray lpSource, jint Length)
{
    PVOID lpSource1=NULL;
    ACCEL destination, *lpDestination1=NULL;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "MoveMemory__Lorg_eclipse_swt_internal_win32_ACCEL_2_3BI\n");
#endif

    if (lpSource)
        lpSource1 = (PVOID)(*env)->GetByteArrayElements(env, lpSource, NULL);

    if (lpDestination) {
        cacheAccelFids(env, lpDestination, &AccelFc);
        lpDestination1 = &destination;
    }
    
    if (lpSource && lpDestination)
           MoveMemory(lpDestination1, (CONST VOID *)lpSource1, Length);

    if (lpSource)
        (*env)->ReleaseByteArrayElements(env, lpSource, (jbyte *)lpSource1, 0);

    if (lpDestination) {
        setAccelFields(env, lpDestination, lpDestination1, &AccelFc);
    }
}
*/

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    MoveMemory
 * Signature: (Lorg/eclipse/swt/internal/win32/NMTVCUSTOMDRAW;II)V
 */
/* JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_win32_OS_MoveMemory__Lorg_eclipse_swt_internal_win32_NMTVCUSTOMDRAW_2II
  (JNIEnv *env, jclass that, jobject Destination, jint Source, jint Length)
{
    NMTVCUSTOMDRAW nmtvcustomdraw, *lpDestination1=NULL;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "MoveMemory__Lorg_eclipse_swt_internal_win32_NMTVCUSTOMDRAW_2II\n");
#endif

       MoveMemory((PVOID)&nmtvcustomdraw, (CONST VOID *)Source, Length);

    if (Destination) {
        lpDestination1 = &nmtvcustomdraw;
        cacheNmtvcustomdrawFids(env, Destination, &NmtvcustomdrawFc);
        setNmtvcustomdrawFields(env, Destination, lpDestination1, &NmtvcustomdrawFc);
    }
}
*/
/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    MoveMemory
 * Signature: (Lorg/eclipse/swt/internal/win32/RECT;II)V
 */
/* JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_win32_OS_MoveMemory__Lorg_eclipse_swt_internal_win32_RECT_2II
  (JNIEnv *env, jclass that, jobject Destination, jint Source, jint Length)
{
    RECT rect, *lpDestination1=NULL;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "MoveMemory__Lorg_eclipse_swt_internal_win32_RECT_2II\n");
#endif

       MoveMemory((PVOID)&rect, (CONST VOID *)Source, Length);

    if (Destination) {
        lpDestination1 = &rect;
        cacheRectFids(env, Destination, &RectFc);
        setRectFields(env, Destination, lpDestination1, &RectFc);
    }
}
*/
/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    PostQuitMessage
 * Signature: (I)V
 */
/* JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_win32_OS_PostQuitMessage
  (JNIEnv *env, jclass that, jint nExitCode)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "PostQuitMessage\n");
#endif

     PostQuitMessage(nExitCode);
}
*/
/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SendMessage
 * Signature: (IIILorg/eclipse/swt/internal/win32/MSG;)I
 */
/* JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SendMessage__IIILorg_eclipse_swt_internal_win32_MSG_2
  (JNIEnv * env, jclass that, jint hWnd, jint Msg, jint wParam, jobject lParam)
{
    MSG msg, *lpParam1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SendMessage__IIILorg_eclipse_swt_internal_win32_MSG_2\n");
#endif

    if (lParam) {
        lpParam1 = &msg;
        cacheMsgFids(env, lParam, &MsgFc);
        getMsgFields(env, lParam, lpParam1, &MsgFc);
    }
    rc = (jint) SendMessage((HWND)hWnd, Msg, wParam, (LPARAM)lpParam1);
    if (lParam) {
        setMsgFields(env, lParam, lpParam1, &MsgFc);
    }
    return rc;
}
*/

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SetCaretBlinkTime
 * Signature: (I)Z
 */
/* JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_SetCaretBlinkTime
  (JNIEnv *env, jclass that, jint uMSeconds)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SetCaretBlinkTime\n");
#endif

    return (jboolean) SetCaretBlinkTime(uMSeconds);
}
*/
/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SetTimer
 * Signature: (IIII)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SetTimer
  (JNIEnv *env, jclass that, jint hWnd, jint nIDEvent, jint uElapse, jint lpTimerFunc)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SetTimer\n");
#endif

    return (jint) SetTimer((HWND)hWnd, nIDEvent, uElapse, (TIMERPROC)lpTimerFunc);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ExtractIcon
 * Signature: (I[BI)I
 */
/*JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_ExtractIcon
  (JNIEnv *env, jclass that, jint hinst, jbyteArray lpszFile, jint nIconIndex)
{
    LPCTSTR lpszFile1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "ExtractIcon\n");
#endif

    if (lpszFile)
        lpszFile1 = (*env)->GetByteArrayElements(env, lpszFile, NULL);

    rc = (jint) ExtractIcon( (HINSTANCE)hinst, lpszFile1, nIconIndex);

    if (lpszFile)
        (*env)->ReleaseByteArrayElements(env, lpszFile, (jbyte *)lpszFile1, 0);
    return rc;
}
*/

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    MoveMemory
 * Signature: (ILorg/eclipse/swt/internal/win32/MSGFILTER;I)V
 */
/*
JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_win32_OS_MoveMemory__ILorg_eclipse_swt_internal_win32_MSGFILTER_2I
  (JNIEnv *env, jclass that, jint Destination, jobject Source, jint Length)
{
    MSGFILTER msgfilter, *Source1=NULL;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "MoveMemory__ILorg_eclipse_swt_internal_win32_MSGFILTER_2I\n");
#endif
    if (Source) {
        Source1 = &msgfilter;
        cacheMsgfilterFids(env, Source, &MsgfilterFc);
        getMsgfilterFields(env, Source, Source1, &MsgfilterFc);
    }
    MoveMemory((PVOID)Destination, (CONST VOID *)Source1, Length);
}
*/

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    MoveMemory
 * Signature: (Lorg/eclipse/swt/internal/win32/MSGFILTER;II)V
 */
/*JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_win32_OS_MoveMemory__Lorg_eclipse_swt_internal_win32_MSGFILTER_2II
  (JNIEnv *env, jclass that, jobject Destination, jint Source, jint Length)
{
    MSGFILTER msgfilter, *Destination1=NULL;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "MoveMemory__Lorg_eclipse_swt_internal_win32_MSGFILTER_2II\n");
#endif
    MoveMemory((PVOID)Destination1, (CONST VOID *)Source, Length);
    if (Destination) {
        Destination1 = &msgfilter;
        cacheMsgfilterFids(env, Destination, &MsgfilterFc);
        setMsgfilterFields(env, Destination, Destination1, &MsgfilterFc);
    }
}
*/

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetNearestColor
 * Signature: (II)I
 */
/*JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetNearestColor
  (JNIEnv *env, jclass that, jint hdc, jint crColor)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetNearestColor\n");
#endif

    return (jint) GetNearestColor((HDC)hdc, (COLORREF)crColor);
}
*/

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SendMessage
 * Signature: (IIILorg/eclipse/swt/internal/win32/CHARFORMAT;)I
 */
/*
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SendMessage__IIILorg_eclipse_swt_internal_win32_CHARFORMAT_2
  (JNIEnv *env, jclass that, jint hWnd, jint Msg, jint wParam, jobject lParam)
{
    CHARFORMAT charformat, *lpParam1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SendMessage__IIILorg_eclipse_swt_internal_win32_CHARFORMAT_2\n");
#endif

    if (lParam) {
        lpParam1 = &charformat;
        cacheCharformatFids(env, lParam, &CharformatFc);
        getCharformatFields(env, lParam, lpParam1, &CharformatFc);
    }
    rc = (jint) SendMessage((HWND)hWnd, Msg, wParam, (LPARAM)lpParam1);
    if (lParam) {
        setCharformatFields(env, lParam, lpParam1, &CharformatFc);
    }
    return rc;
}
*/


/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    VtblCall
 * Signature: (III)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_VtblCall
  (JNIEnv *env, jclass that, jint fnNumber, jint ppVtbl, jint arg0)
{
    P_OLE_FN_2 fn; /* this is a function that returns int */
    jint rc;
    
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "OS_VtblCall\n");
#endif

    fn = (P_OLE_FN_2)(*(int **)ppVtbl)[fnNumber];

    rc = fn(ppVtbl, arg0); /* cast it to an OLE function returning int */
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SHGetFileInfo
 * Signature: ([BILorg/eclipse/swt/internal/win32/SHFILEINFO;II)I
 */
/*
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_SHGetFileInfo
  (JNIEnv * env, jclass that, jbyteArray pszPath, jint dwFileAttributes, jobject psfi, jint cbFileInfo, jint uFlags)
{
	DECL_GLOB(pGlob)
	LPCTSTR pszPath1=NULL;
	SHFILEINFO shellinfo, *psfi1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SHGetFileInfo\n");
#endif

	if (pszPath)
        pszPath1 = (*env)->GetByteArrayElements(env, pszPath, NULL);
    if (psfi) {
        psfi1 = &shellinfo;
        cacheShfileinfoFids(env, psfi, &PGLOB(ShfileinfoFc));
        getShfileinfoFields(env, psfi, psfi1, &PGLOB(ShfileinfoFc));
    }
    
    rc = (jint) SHGetFileInfo (pszPath1, dwFileAttributes, psfi1, cbFileInfo, uFlags);

    if (pszPath)
        (*env)->ReleaseByteArrayElements(env, pszPath, (jbyte *)pszPath1, 0);
    if (psfi) {
        setShfileinfoFields(env, psfi, psfi1, &PGLOB(ShfileinfoFc));
    } 
 
    return rc;
}
*/

/*
 * Class:     org_eclipse_swt_internal_OS
 * Method:    MoveMemory
 * Signature: ([CII)V
 */
JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_win32_OS_MoveMemory___3CII
  (JNIEnv *env, jclass that, jcharArray DestinationPtr, jint Source, jint Length)
{
    jchar *DestinationPtr1=NULL;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "MoveMemory___3CII\n");
#endif

    if (DestinationPtr)
        DestinationPtr1 = (*env)->GetCharArrayElements(env, DestinationPtr, NULL);

    MoveMemory(DestinationPtr1, (CONST VOID *)Source, Length);

    if (DestinationPtr)
        (*env)->ReleaseCharArrayElements(env, DestinationPtr, DestinationPtr1, 0);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    MoveMemory
 * Signature: (Lorg/eclipse/swt/internal/win32/MSG;II)V
 */
JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_win32_OS_MoveMemory__Lorg_eclipse_swt_internal_win32_MSG_2II
  (JNIEnv *env, jclass that, jobject Destination, jint Source, jint Length)
{
	DECL_GLOB(pGlob)
    MSG msg, *lpDestination1=NULL;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "MoveMemory__Lorg_eclipse_swt_internal_win32_MSG_2II\n");
#endif

       MoveMemory((PVOID)&msg, (CONST VOID *)Source, Length);

    if (Destination) {
        lpDestination1 = &msg;
        cacheMsgFids(env, Destination, &PGLOB(MsgFc));
        setMsgFields(env, Destination, lpDestination1, &PGLOB(MsgFc));
    }
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ExtTextOutA
 * Signature: 
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_ExtTextOutA
  (JNIEnv *env, jclass that, jint hdc, jint X, jint Y, jint fuOptions, jobject lprc, jbyteArray lpString, jint cbCount, jintArray lpDx)
{
	DECL_GLOB(pGlob)
    RECT rect, *lpRect1=NULL;
    jbyte* lpString1=NULL;
	CONST INT* lpDx1 = NULL;
    jboolean rc;
    
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "ExtTextOutA\n");
#endif

    if (lpString)
        lpString1 = (*env)->GetByteArrayElements(env, lpString, NULL);
    if (lprc) {
        lpRect1 = &rect;
        cacheRectFids(env, lprc, &PGLOB(RectFc));
        getRectFields(env, lprc, lpRect1, &PGLOB(RectFc));
    }
    if (lpDx)
        lpDx1 = (CONST INT*)(*env)->GetIntArrayElements(env, lpDx, NULL);
    
    rc = (jboolean) ExtTextOutA((HDC)hdc, X, Y, fuOptions, lpRect1, (LPSTR)lpString1, cbCount, lpDx1);
    
    if (lpString)
        (*env)->ReleaseByteArrayElements(env, lpString, (jbyte *)lpString1, 0);
    if (lprc) {
        setRectFields(env, lprc, lpRect1, &PGLOB(RectFc));
    }
    if (lpDx)
        (*env)->ReleaseIntArrayElements(env, lpDx, (jint *)lpDx1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ExtTextOutW
 * Signature: 
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_ExtTextOutW
  (JNIEnv *env, jclass that, jint hdc, jint X, jint Y, jint fuOptions, jobject lprc, jcharArray lpString, jint cbCount, jintArray lpDx)
{
	DECL_GLOB(pGlob)
    RECT rect, *lpRect1=NULL;
    jchar* lpString1=NULL;
	CONST INT* lpDx1 = NULL;
    jboolean rc;
    
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "ExtTextOutW\n");
#endif

    if (lpString)
        lpString1 = (*env)->GetCharArrayElements(env, lpString, NULL);
    if (lprc) {
        lpRect1 = &rect;
        cacheRectFids(env, lprc, &PGLOB(RectFc));
        getRectFields(env, lprc, lpRect1, &PGLOB(RectFc));
    }
    if (lpDx)
        lpDx1 = (CONST INT*)(*env)->GetIntArrayElements(env, lpDx, NULL);
    
    rc = (jboolean) ExtTextOutW((HDC)hdc, X, Y, fuOptions, lpRect1, (LPWSTR)lpString1, cbCount, lpDx1);
    
    if (lpString)
        (*env)->ReleaseCharArrayElements(env, lpString, lpString1, 0);
    if (lprc) {
        setRectFields(env, lprc, lpRect1, &PGLOB(RectFc));
    }
    if (lpDx)
        (*env)->ReleaseIntArrayElements(env, lpDx, (jint *)lpDx1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    TranslateCharsetInfo
 * Signature: 
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_TranslateCharsetInfo
  (JNIEnv *env, jclass that, jint lpSrc, jintArray lpCs, jint dwFlags)
{
	LPCHARSETINFO lpCs1 =NULL;
    jboolean rc;
    
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "TranslateCharsetInfo\n");
#endif

    if (lpCs)
        lpCs1 = (LPCHARSETINFO)(*env)->GetIntArrayElements(env, lpCs, NULL);

    rc = (jboolean)TranslateCharsetInfo((DWORD *)lpSrc, lpCs1, dwFlags);
    
    if (lpCs)
        (*env)->ReleaseIntArrayElements(env, lpCs, (jint *)lpCs1, 0);
        
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetLocaleInfoA
 * Signature: (II[BI)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetLocaleInfoA
  (JNIEnv *env, jclass that, jint Locale, jint LCType, jbyteArray lpLCData, jint cchData)
{
    jbyte* lpLCData1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetLocaleInfoA\n");
#endif

    if (lpLCData)
        lpLCData1 = (*env)->GetByteArrayElements(env, lpLCData, NULL);

    rc = (jint) GetLocaleInfoA(Locale, LCType, (LPSTR)lpLCData1, cchData);

    if (lpLCData)
        (*env)->ReleaseByteArrayElements(env, lpLCData, lpLCData1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetLocaleInfoW
 * Signature: (II[CI)I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetLocaleInfoW
  (JNIEnv *env, jclass that, jint Locale, jint LCType, jcharArray lpLCData, jint cchData)
{
    jchar* lpLCData1=NULL;
    jint rc;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetLocaleInfoW\n");
#endif

    if (lpLCData)
        lpLCData1 = (*env)->GetCharArrayElements(env, lpLCData, NULL);

    rc = (jint) GetLocaleInfoW(Locale, LCType, (LPWSTR)lpLCData1, cchData);

    if (lpLCData)
        (*env)->ReleaseCharArrayElements(env, lpLCData, lpLCData1, 0);
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    EnumSystemLocalesA
 * Signature: (II)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_EnumSystemLocalesA
  (JNIEnv *env, jclass that, jint lpLocaleEnumProc, jint dwFlags)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "EnumSystemLocalesA\n");
#endif

    return (jboolean) EnumSystemLocalesA((LOCALE_ENUMPROCA)lpLocaleEnumProc, (DWORD)dwFlags);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    EnumSystemLocalesW
 * Signature: (II)Z
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_EnumSystemLocalesW
  (JNIEnv *env, jclass that, jint lpLocaleEnumProc, jint dwFlags)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "EnumSystemLocalesW\n");
#endif

    return (jboolean) EnumSystemLocalesW((LOCALE_ENUMPROCW)lpLocaleEnumProc, (DWORD)dwFlags);
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SystemParametersInfoA
 * Signature: 
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_SystemParametersInfoA
  (JNIEnv *env, jclass that, jint uiAction, jint uiName, jobject pvParam, jint fWinIni)
{
	DECL_GLOB(pGlob)
    RECT rect, *pvParam1=NULL;
    jboolean rc;
    
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SystemParametersInfoA\n");
#endif

     if (pvParam) {
        pvParam1 = &rect;
        cacheRectFids(env, pvParam, &PGLOB(RectFc));
        getRectFields(env, pvParam, pvParam1, &PGLOB(RectFc));
    }
    
    rc = (jboolean) SystemParametersInfoA(uiAction, uiName, pvParam1, fWinIni);
    
    if (pvParam) {
        setRectFields(env, pvParam, pvParam1, &PGLOB(RectFc));
    }

    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    SystemParametersInfoW
 * Signature: 
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_SystemParametersInfoW
  (JNIEnv *env, jclass that, jint uiAction, jint uiName, jobject pvParam, jint fWinIni)
{
	DECL_GLOB(pGlob)
    RECT rect, *pvParam1=NULL;
    jboolean rc;
    
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "SystemParametersInfoW\n");
#endif

     if (pvParam) {
        pvParam1 = &rect;
        cacheRectFids(env, pvParam, &PGLOB(RectFc));
        getRectFields(env, pvParam, pvParam1, &PGLOB(RectFc));
    }
    
    rc = (jboolean) SystemParametersInfoW(uiAction, uiName, pvParam1, fWinIni);
    
    if (pvParam) {
        setRectFields(env, pvParam, pvParam1, &PGLOB(RectFc));
    }

    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    InsertMenuA
 * Signature: (IIZLorg/eclipse/swt/internal/win32/MENUITEMINFO;)Z
 */

JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_InsertMenuA
  (JNIEnv *env, jclass that, jint hMenu, jint uPosition, jint uFlags, jint uIDNewItem, jbyteArray lpNewItem)
{
    jboolean rc;
    jbyte* lpNewItem1=NULL;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "InsertMenuW\n");
#endif

    if (lpNewItem)
        lpNewItem1 = (*env)->GetByteArrayElements(env, lpNewItem, NULL);

	rc = (jboolean) InsertMenuA((HMENU)hMenu, uPosition, uFlags, uIDNewItem, lpNewItem1); 

    if (lpNewItem)
        (*env)->ReleaseByteArrayElements(env, lpNewItem, lpNewItem1, 0);
        
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    InsertMenuW
 * Signature: (IIZLorg/eclipse/swt/internal/win32/MENUITEMINFO;)Z
 */

JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_InsertMenuW
  (JNIEnv *env, jclass that, jint hMenu, jint uPosition, jint uFlags, jint uIDNewItem, jcharArray lpNewItem)
{
    jboolean rc;
    jchar* lpNewItem1=NULL;

#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "InsertMenuW\n");
#endif

    if (lpNewItem)
        lpNewItem1 = (*env)->GetCharArrayElements(env, lpNewItem, NULL);

	rc = (jboolean) InsertMenuW((HMENU)hMenu, uPosition, uFlags, uIDNewItem, lpNewItem1); 

    if (lpNewItem)
        (*env)->ReleaseCharArrayElements(env, lpNewItem, lpNewItem1, 0);
        
    return rc;
}
/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetVersionExA
 * Signature: ()I
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_GetVersionExA
  (JNIEnv *env, jclass that, jobject lpVersionInfo)
{
	DECL_GLOB(pGlob)
    OSVERSIONINFO versionInfo={0}, *lpVersionInfo1=NULL;
	jboolean rc;
	
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetVersionExA\n");
#endif

    if (lpVersionInfo) {
        lpVersionInfo1 = &versionInfo;
        cacheOsversioninfoFids(env, lpVersionInfo, &PGLOB(OsversioninfoFc));
        getOsversioninfoFields(env, lpVersionInfo, lpVersionInfo1, &PGLOB(OsversioninfoFc));
    }
    rc = GetVersionExA (lpVersionInfo1);
	if (lpVersionInfo) {
        setOsversioninfoFields(env, lpVersionInfo, lpVersionInfo1, &PGLOB(OsversioninfoFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetVersionExW
 * Signature: ()I
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_GetVersionExW
  (JNIEnv *env, jclass that, jobject lpVersionInfo)
{
	DECL_GLOB(pGlob)
    OSVERSIONINFOW versionInfo={0}, *lpVersionInfo1=NULL;
	jboolean rc;
	
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetVersionExW\n");
#endif

    if (lpVersionInfo) {
        lpVersionInfo1 = &versionInfo;
        cacheOsversioninfoFids(env, lpVersionInfo, &PGLOB(OsversioninfoFc));
        getOsversioninfoFields(env, lpVersionInfo, lpVersionInfo1, &PGLOB(OsversioninfoFc));
    }
    rc = GetVersionExW ((LPOSVERSIONINFOW)lpVersionInfo1);
	if (lpVersionInfo) {
        setOsversioninfoFields(env, lpVersionInfo, lpVersionInfo1, &PGLOB(OsversioninfoFc));
    }
    return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    GetTickCount
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_win32_OS_GetTickCount
  (JNIEnv *env, jclass that)
{
#ifdef DEBUG_CALL_PRINTS
    fprintf(stderr, "GetTickCount\n");
#endif

    return (jint) GetTickCount();
}


/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ShellExecuteExA
 * Signature:
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_ShellExecuteExA
   (JNIEnv *env, jclass that, jobject lpShellexecuteinfo)
{
	DECL_GLOB(pGlob)
	SHELLEXECUTEINFO shellexecuteinfo, *lpShellexecuteinfo1=NULL;
	jboolean rc;

#ifdef DEBUG_CALL_PRINTS
	fprintf(stderr, "ShellExecuteExA\n");
#endif

    if (lpShellexecuteinfo) {
        lpShellexecuteinfo1 = &shellexecuteinfo;
        cacheShellexecuteinfoFids(env, lpShellexecuteinfo, &PGLOB(ShellexecuteinfoFc));
        getShellexecuteinfoFields(env, lpShellexecuteinfo, lpShellexecuteinfo1, &PGLOB(ShellexecuteinfoFc));
    }

	rc = (jint)ShellExecuteExA(lpShellexecuteinfo1);

	if (lpShellexecuteinfo) {
        setShellexecuteinfoFields(env, lpShellexecuteinfo, lpShellexecuteinfo1, &PGLOB(ShellexecuteinfoFc));
    }

	return rc;
}

/*
 * Class:     org_eclipse_swt_internal_win32_OS
 * Method:    ShellExecuteExW
 * Signature:
 */
JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_win32_OS_ShellExecuteExW
   (JNIEnv *env, jclass that, jobject lpShellexecuteinfo)
{
	DECL_GLOB(pGlob)
	SHELLEXECUTEINFO shellexecuteinfo, *lpShellexecuteinfo1=NULL;
	jboolean rc;

#ifdef DEBUG_CALL_PRINTS
	fprintf(stderr, "ShellExecuteExW\n");
#endif

    if (lpShellexecuteinfo) {
        lpShellexecuteinfo1 = &shellexecuteinfo;
        cacheShellexecuteinfoFids(env, lpShellexecuteinfo, &PGLOB(ShellexecuteinfoFc));
        getShellexecuteinfoFields(env, lpShellexecuteinfo, lpShellexecuteinfo1, &PGLOB(ShellexecuteinfoFc));
    }

	rc = (jint)ShellExecuteExW(lpShellexecuteinfo1);

	if (lpShellexecuteinfo) {
        setShellexecuteinfoFields(env, lpShellexecuteinfo, lpShellexecuteinfo1, &PGLOB(ShellexecuteinfoFc));
    }

	return rc;
}
