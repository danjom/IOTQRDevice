#ifndef OPTIONS_H
#define OPTIONS_H

extern int state;
extern int event;

enum uiblock {QRCODE, SYMBOL, DIGITS};
enum options {MENU, SCAN, SELECT, EVENT, DONE};
enum nextion {OPTIONS, PAYMENT, QRIMAGE, SUCCESS, REFUSED, WARNING, HISTORY, REDEEM};
enum signals {SETUP, LOADING, READY, NETWORK, WRONG, CORRECT, REJECT, AwAIT, ERROR};

#endif