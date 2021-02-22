#pragma once

#ifndef FASTFETCH_INCLUDED
#define FASTFETCH_INCLUDED

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>

#define FASTFETCH_TEXT_MODIFIER_BOLT  "\033[1m"
#define FASTFETCH_TEXT_MODIFIER_ERROR "\033[1;31m"
#define FASTFETCH_TEXT_MODIFIER_RESET "\033[0m"

typedef struct FFlogo
{
    uint8_t width;
    uint8_t height;
    char    chars[256][256];
    char    name[128];
    char    color[32];
} FFlogo;

typedef struct FFstate
{
    //Actual state stuff
    uint8_t current_row;

    //Configuration stuff
    FFlogo logo;
    uint16_t logo_seperator;
    char color[32];
    uint8_t titleLength;
    bool showErrors;
    bool recache;

    //Common stuff
    struct passwd* passwd;
    struct utsname utsname;
    struct sysinfo sysinfo;
} FFstate;

//Helper functions
void ffPrintLogoLine(FFstate* state);
void ffPrintKey(FFstate* state, const char* key);
void ffPrintLogoAndKey(FFstate* state, const char* key);
void ffParsePropFile(const char* file, const char* regex, char* buffer);
void ffParsePropFileHome(FFstate* state, const char* relativeFile, const char* regex, char* buffer);
void ffPrintGtkPretty(const char* gtk2, const char* gtk3, const char* gtk4);
void ffPrintError(FFstate* state, const char* key, const char* message);
bool ffPrintCachedValue(FFstate* state, const char* key);
void ffSaveCachedValue(FFstate* state, const char* key, const char* value);

void ffLoadLogoSet(FFstate* state, const char* logo);
void ffLoadLogo(FFstate* state);
void ffListLogos();
void ffPrintLogos();

void ffPrintBreak(FFstate* state);
void ffPrintTitle(FFstate* state);
void ffPrintSeperator(FFstate* state);
void ffPrintOS(FFstate* state);
void ffPrintHost(FFstate* state);
void ffPrintKernel(FFstate* state);
void ffPrintUptime(FFstate* state);
void ffPrintPackages(FFstate* state);
void ffPrintShell(FFstate* state);
void ffPrintResolution(FFstate* state);
void ffPrintDesktopEnvironment(FFstate* state);
void ffPrintTheme(FFstate* state);
void ffPrintIcons(FFstate* state);
void ffPrintFont(FFstate* state);
void ffPrintTerminal(FFstate* state);
void ffPrintCPU(FFstate* state);
void ffPrintGPU(FFstate* state);
void ffPrintMemory(FFstate* state);
void ffPrintDisk(FFstate* state);
void ffPrintBattery(FFstate* state);
void ffPrintLocale(FFstate* state);
void ffPrintColors(FFstate* state);

#endif