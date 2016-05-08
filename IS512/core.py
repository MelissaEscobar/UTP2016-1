#!/usr/bin/env python
# -*- coding: utf-8 -*-
#Project Details: This file is part of the final project of statistics
#Team members : Eliana Osorio, Sebastian Idarraga, Hector F. Jimenez
#File Details: Contains Colors, And Core functions
# url: github.com/heticor915/UTP2016-1/IS512Statistics
#   License Details:
#    Copyright (C) 2016  Hector F. Jimenez S.
#    This program is free software; you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation; Applies version 2 of the License.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program; if not, write to the Free Software
#    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

import os, sys
import string
import random
fwpath = os.getcwd()
sys.path.append(fwpath+"src")
# Location for logs, modules and storage
ActivityLog = ("Logs")

# Pretty colors
reset = '\x1b[0m'    # reset all colors to white on black
bold = '\x1b[1m'     # enable bold text
uline = '\x1b[4m'    # enable underlined text
nobold = '\x1b[22m'  # disable bold text
nouline = '\x1b[24m' # disable underlined text
red = '\x1b[31m'     # red text
green = '\x1b[32m'   # green text
blue = '\x1b[34m'    # blue text
cyan = '\x1b[36m'    # cyan text
white = '\x1b[37m'   # white text (use reset unless it's only temporary)
warning = "%s[!]%s" % (red, reset)
info = "%s[*]%s" % (green, reset)
# catch for ctrl+c so we can exit smoothly
def signalHandler(signal, frame):
    warning("Ctrl-C caught, Shutting down now!")
    logging.info("[!] Ctrl+C signal caught. Shutting down Intersect!")

def banner():
    target = random.randrange(1,5)
    if target == 1:
        print """%s%s
        ######   #####
        #     # #     #   ##   #    #  ####   ####
        #     # #        #  #  #    # #      #
        #     # #  #### #    # #    #  ####   ####
        #     # #     # ###### #    #      #      #
        #     # #     # #    # #    # #    # #    #
        ######   #####  #    #  ####   ####   ####
            feedback:hfjimenez@utp.edu.co
		%sUniversidad Tecnologica de Pereira, ISC%s
        """ % (bold, blue, white, reset)

    elif target == 2:
        print """%s%s
        d8888b.  d888b   .d8b.  db    db .d8888. .d8888.
        88  `8D 88' Y8b d8' `8b 88    88 88'  YP 88'  YP
        88   88 88      88ooo88 88    88 `8bo.   `8bo.
        88   88 88  ooo 88~~~88 88    88   `Y8b.   `Y8b.
        88  .8D 88. ~8~ 88   88 88b  d88 db   8D db   8D
        Y8888D'  Y888P  YP   YP ~Y8888P' `8888Y' `8888Y'
            feedback:hfjimenez@utp.edu.co
        %sUniversidad Tecnologica de Pereira, ISC %s
        """ % (bold, green, white, reset)

    elif target == 3:
        print """%s%s
        8""""8 8""""8
        8    8 8    " eeeee e   e eeeee eeeee
        8e   8 8e     8   8 8   8 8   " 8   "
        88   8 88  ee 8eee8 8e  8 8eeee 8eeee
        88   8 88   8 88  8 88  8    88    88
        88eee8 88eee8 88  8 88ee8 8ee88 8ee88
            feedback:hfjimenez@utp.edu.co
         %sUniversidad Tecnologica de Pereira, ISC%s
""" % (bold, green, white, reset)
    elif target == 4:
        print """%s%s
        8""""8 8""""8
        8    8 8    " eeeee e   e eeeee eeeee
        8e   8 8e     8   8 8   8 8   " 8   "
        88   8 88  ee 8eee8 8e  8 8eeee 8eeee
        88   8 88   8 88  8 88  8    88    88
        88eee8 88eee8 88  8 88ee8 8ee88 8ee88
         feedback:hfjimenez@utp.edu.co
        %sUniversidad Tecnologica de Pereira, ISC%s
""" % (bold, green, white, reset)
    elif target == 5:
        print """%s%s
        @@@@@@@   @@@@@@@   @@@@@@  @@@  @@@  @@@@@@  @@@@@@
        @@!  @@@ !@@       @@!  @@@ @@!  @@@ !@@     !@@
        @!@  !@! !@! @!@!@ @!@!@!@! @!@  !@!  !@@!!   !@@!!
        !!:  !!! :!!   !!: !!:  !!! !!:  !!!     !:!     !:!
        :: :  :   :: :: :   :   : :  :.:: :  ::.: :  ::.: :
         feedback:hfjimenez@utp.edu.co
        %sUniversidad Tecnologica de Pereira, ISC%s
""" % (bold, green, white, reset)

#Taken from darkoperator's github: DnsRecon
def print_status(message=""):                   #Normal Status
    if sys.stdout.isatty() and platform.system() != "Windows":
        print("\033[1;34m[*]\033[1;m {0}".format(message))
    else:
        print("[*] {0}".format(message))

def print_good(message=""):                     #Normal OK Status
    if sys.stdout.isatty() and platform.system() != "Windows":
        print("\033[1;32m[+]\033[1;m {0}".format(message))
    else:
        print("[+] {0}".format(message))


def print_error(message=""):                    # Status Error ,Faile During Code Exec..
    if sys.stdout.isatty() and platform.system() != "Windows":
        print("\033[1;31m[-]\033[1;m {0}".format(message))
    else:
        print("[-] {0}".format(message))


def print_debug(message=""):                          #Debug Platform
    if sys.stdout.isatty() and platform.system() != "Windows":
        print("\033[1;31m[!]\033[1;m {0}".format(message))
    else:
        print("[!] {0}".format(message))


def print_line(message=""):                             #Line
    print("{0}".format(message))
