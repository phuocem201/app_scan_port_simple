#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <iomanip>
#include <sstream>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <future>
#include <errno.h>
#include <fcntl.h>

static bool port_is_open(std::string &ip, int port)
{
    struct sockaddr_in address;
    short int sock = 1; /* file descriptor for the network socket */

    // thiet lap dia chi ket noi
    address.sin_family = AF_INET;                    // default
    address.sin_addr.s_addr = inet_addr(ip.c_str()); // assign the ip address
    address.sin_port = htons(port);                  // port number

    // tao socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    // fcntl(sock, F_SETFL, O_NONBLOCK); // setup non blocking socket

    int connection_status = connect(sock, (struct sockaddr *)&address, sizeof(address));
    if (connection_status == -1)
    {
        close(sock);
        return false;
    }
    else if (connection_status == 0)
    {
        close(sock);
        return true;
    };

    return false;
}

/*********
//
// ShowPortNumberInfo() - get a port number and print the common service that use the port (example: 80 = http).
//
*********/
void ShowPortNumberInfo(unsigned int port)
{
    switch (port)
    {
    case 1:
        printf("TCP Port Service Multiplexer.");
        break;
    case 2:
        printf("Management Utility.");
        break;
    case 3:
        printf("Compression Process.");
        break;
    case 5:
        printf("Remote Job Entry.");
        break;
    case 7:
        printf("Echo.");
        break;
    case 9:
        printf("Discard.");
        break;
    case 11:
        printf("Active Users.");
        break;
    case 13:
        printf("Daytime.");
        break;
    case 15:
        printf("Unassigned [was netstat].");
        break;
    case 17:
        printf("Quote of the Day.");
        break;
    case 18:
        printf("Message Send Protocol (historic).");
        break;
    case 19:
        printf("Character Generator.");
        break;
    case 20:
        printf("File Transfer [Default Data].");
        break;
    case 21:
        printf("File Transfer Protocol [Control].");
        break;
    case 22:
        printf("The Secure Shell (SSH) Protocol.");
        break;
    case 23:
        printf("Telnet.");
        break;
    case 24:
        printf("any private mail system.");
        break;
    case 25:
        printf("Simple Mail Transfer.");
        break;
    case 27:
        printf("NSW User System FE.");
        break;
    case 29:
        printf("MSG ICP.");
        break;
    case 31:
        printf("MSG Authentication.");
        break;
    case 33:
        printf("Display Support Protocol.");
        break;
    case 35:
        printf("any private printer server.");
        break;
    case 37:
        printf("Time.");
        break;
    case 38:
        printf("Route Access Protocol.");
        break;
    case 39:
        printf("Resource Location Protocol.");
        break;
    case 41:
        printf("Graphics.");
        break;
    case 42:
        printf("Host Name Server.");
        break;
    case 43:
        printf("Who Is.");
        break;
    case 44:
        printf("MPM FLAGS Protocol.");
        break;
    case 45:
        printf("Message Processing Module [recv].");
        break;
    case 46:
        printf("MPM [default send].");
        break;
    case 48:
        printf("Digital Audit Daemon.");
        break;
    case 49:
        printf("Login Host Protocol (TACACS).");
        break;
    case 50:
        printf("Remote Mail Checking Protocol.");
        break;
    case 52:
        printf("XNS Time Protocol.");
        break;
    case 53:
        printf("Domain Name Server.");
        break;
    case 54:
        printf("XNS Clearinghouse.");
        break;
    case 55:
        printf("ISI Graphics Language.");
        break;
    case 56:
        printf("XNS Authentication.");
        break;
    case 57:
        printf("any private terminal access.");
        break;
    case 58:
        printf("XNS Mail.");
        break;
    case 59:
        printf("any private file service.");
        break;
    case 62:
        printf("ACA Services.");
        break;
    case 63:
        printf("whois++.");
        break;
    case 64:
        printf("Communications Integrator (CI).");
        break;
    case 65:
        printf("TACACS-Database Service.");
        break;
    case 66:
        printf("Oracle SQL*NET.");
        break;
    case 67:
        printf("Bootstrap Protocol Server.");
        break;
    case 68:
        printf("Bootstrap Protocol Client.");
        break;
    case 69:
        printf("Trivial File Transfer.");
        break;
    case 70:
        printf("Gopher.");
        break;
    case 71:
        printf("Remote Job Service.");
        break;
    case 72:
        printf("Remote Job Service.");
        break;
    case 73:
        printf("Remote Job Service.");
        break;
    case 74:
        printf("Remote Job Service.");
        break;
    case 75:
        printf("any private dial out service.");
        break;
    case 76:
        printf("Distributed External Object Store.");
        break;
    case 77:
        printf("any private RJE service.");
        break;
    case 78:
        printf("vettcp.");
        break;
    case 79:
        printf("Finger.");
        break;
    case 80:
        printf("World Wide Web HTTP.");
        break;
    case 82:
        printf("XFER Utility.");
        break;
    case 83:
        printf("MIT ML Device.");
        break;
    case 84:
        printf("Common Trace Facility.");
        break;
    case 85:
        printf("MIT ML Device.");
        break;
    case 86:
        printf("Micro Focus Cobol.");
        break;
    case 87:
        printf("any private terminal link.");
        break;
    case 88:
        printf("Kerberos.");
        break;
    case 89:
        printf("SU/MIT Telnet Gateway.");
        break;
    case 90:
        printf("DNSIX Securit Attribute Token Map.");
        break;
    case 91:
        printf("MIT Dover Spooler.");
        break;
    case 92:
        printf("Network Printing Protocol.");
        break;
    case 93:
        printf("Device Control Protocol.");
        break;
    case 94:
        printf("Tivoli Object Dispatcher.");
        break;
    case 95:
        printf("SUPDUP.");
        break;
    case 96:
        printf("DIXIE Protocol Specification.");
        break;
    case 97:
        printf("Swift Remote Virtural File Protocol.");
        break;
    case 98:
        printf("TAC News.");
        break;
    case 99:
        printf("Metagram Relay.");
        break;
    case 101:
        printf("NIC Host Name Server.");
        break;
    case 102:
        printf("ISO-TSAP Class 0.");
        break;
    case 103:
        printf("Genesis Point-to-Point Trans Net.");
        break;
    case 104:
        printf("ACR-NEMA Digital Imag. & Comm. 300.");
        break;
    case 105:
        printf("CCSO name server protocol / Mailbox Name Nameserver.");
        break;
    case 106:
        printf("3COM-TSMUX.");
        break;
    case 107:
        printf("Remote Telnet Service.");
        break;
    case 108:
        printf("SNA Gateway Access Server.");
        break;
    case 109:
        printf("Post Office Protocol - Version 2.");
        break;
    case 110:
        printf("Post Office Protocol - Version 3.");
        break;
    case 111:
        printf("SUN Remote Procedure Call.");
        break;
    case 112:
        printf("McIDAS Data Transmission Protocol.");
        break;
    case 113:
        printf("Authentication Service.");
        break;
    case 115:
        printf("Simple File Transfer Protocol.");
        break;
    case 116:
        printf("ANSA REX Notify.");
        break;
    case 117:
        printf("UUCP Path Service.");
        break;
    case 118:
        printf("SQL Services.");
        break;
    case 119:
        printf("Network News Transfer Protocol.");
        break;
    case 120:
        printf("CFDPTKT.");
        break;
    case 121:
        printf("Encore Expedited Remote Pro.Call.");
        break;
    case 122:
        printf("SMAKYNET.");
        break;
    case 123:
        printf("Network Time Protocol.");
        break;
    case 124:
        printf("ANSA REX Trader.");
        break;
    case 125:
        printf("Locus PC-Interface Net Map Ser.");
        break;
    case 126:
        printf("NXEdit.");
        break;
    case 127:
        printf("Locus PC-Interface Conn Server.");
        break;
    case 128:
        printf("GSS X License Verification.");
        break;
    case 129:
        printf("Password Generator Protocol.");
        break;
    case 130:
        printf("cisco FNATIVE.");
        break;
    case 131:
        printf("cisco TNATIVE.");
        break;
    case 132:
        printf("cisco SYSMAINT.");
        break;
    case 133:
        printf("Statistics Service.");
        break;
    case 134:
        printf("INGRES-NET Service.");
        break;
    case 135:
        printf("DCE endpoint resolution.");
        break;
    case 136:
        printf("PROFILE Naming System.");
        break;
    case 137:
        printf("NETBIOS Name Service.");
        break;
    case 138:
        printf("NETBIOS Datagram Service.");
        break;
    case 139:
        printf("NETBIOS Session Service.");
        break;
    case 140:
        printf("EMFIS Data Service.");
        break;
    case 141:
        printf("EMFIS Control Service.");
        break;
    case 142:
        printf("Britton-Lee IDM.");
        break;
    case 143:
        printf("Internet Message Access Protocol.");
        break;
    case 144:
        printf("Universal Management Architecture.");
        break;
    case 145:
        printf("UAAC Protocol.");
        break;
    case 146:
        printf("ISO-IP0.");
        break;
    case 147:
        printf("ISO-IP.");
        break;
    case 148:
        printf("Jargon.");
        break;
    case 149:
        printf("AED 512 Emulation Service.");
        break;
    case 150:
        printf("SQL-NET.");
        break;
    case 151:
        printf("HEMS.");
        break;
    case 152:
        printf("Background File Transfer Program.");
        break;
    case 153:
        printf("SGMP.");
        break;
    case 154:
        printf("NETSC.");
        break;
    case 155:
        printf("NETSC.");
        break;
    case 156:
        printf("SQL Service.");
        break;
    case 157:
        printf("KNET/VM Command/Message Protocol.");
        break;
    case 158:
        printf("PCMail Server.");
        break;
    case 159:
        printf("NSS-Routing.");
        break;
    case 160:
        printf("SGMP-TRAPS.");
        break;
    case 161:
        printf("SNMP.");
        break;
    case 162:
        printf("SNMPTRAP.");
        break;
    case 163:
        printf("CMIP/TCP Manager.");
        break;
    case 164:
        printf("CMIP/TCP Agent.");
        break;
    case 165:
        printf("Xerox.");
        break;
    case 166:
        printf("Sirius Systems.");
        break;
    case 167:
        printf("NAMP.");
        break;
    case 168:
        printf("RSVD.");
        break;
    case 169:
        printf("SEND.");
        break;
    case 170:
        printf("Network PostScript.");
        break;
    case 171:
        printf("Network Innovations Multiplex.");
        break;
    case 172:
        printf("Network Innovations CL/1.");
        break;
    case 173:
        printf("Xyplex.");
        break;
    case 174:
        printf("MAILQ.");
        break;
    case 175:
        printf("VMNET.");
        break;
    case 176:
        printf("GENRAD-MUX.");
        break;
    case 177:
        printf("X Display Manager Control Protocol.");
        break;
    case 178:
        printf("NextStep Window Server.");
        break;
    case 179:
        printf("Border Gateway Protocol.");
        break;
    case 180:
        printf("Intergraph.");
        break;
    case 181:
        printf("Unify.");
        break;
    case 182:
        printf("Unisys Audit SITP.");
        break;
    case 183:
        printf("OCBinder.");
        break;
    case 184:
        printf("OCServer.");
        break;
    case 185:
        printf("Remote-KIS.");
        break;
    case 186:
        printf("KIS Protocol.");
        break;
    case 187:
        printf("Application Communication Interface.");
        break;
    case 188:
        printf("Plus Five's MUMPS.");
        break;
    case 189:
        printf("Queued File Transport.");
        break;
    case 190:
        printf("Gateway Access Control Protocol.");
        break;
    case 191:
        printf("Prospero Directory Service.");
        break;
    case 192:
        printf("OSU Network Monitoring System.");
        break;
    case 193:
        printf("Spider Remote Monitoring Protocol.");
        break;
    case 194:
        printf("Internet Relay Chat Protocol.");
        break;
    case 195:
        printf("DNSIX Network Level Module Audit.");
        break;
    case 196:
        printf("DNSIX Session Mgt Module Audit Redir.");
        break;
    case 197:
        printf("Directory Location Service.");
        break;
    case 198:
        printf("Directory Location Service Monitor.");
        break;
    case 199:
        printf("SMUX.");
        break;
    case 200:
        printf("IBM System Resource Controller.");
        break;
    case 201:
        printf("AppleTalk Routing Maintenance.");
        break;
    case 202:
        printf("AppleTalk Name Binding.");
        break;
    case 203:
        printf("AppleTalk Unused.");
        break;
    case 204:
        printf("AppleTalk Echo.");
        break;
    case 205:
        printf("AppleTalk Unused.");
        break;
    case 206:
        printf("AppleTalk Zone Information.");
        break;
    case 207:
        printf("AppleTalk Unused.");
        break;
    case 208:
        printf("AppleTalk Unused.");
        break;
    case 209:
        printf("The Quick Mail Transfer Protocol.");
        break;
    case 210:
        printf("ANSI Z39.50.");
        break;
    case 211:
        printf("Texas Instruments 914C/G Terminal.");
        break;
    case 212:
        printf("ATEXSSTR.");
        break;
    case 213:
        printf("IPX.");
        break;
    case 214:
        printf("VM PWSCS.");
        break;
    case 215:
        printf("Insignia Solutions.");
        break;
    case 216:
        printf("Computer Associates Int'l License Server.");
        break;
    case 217:
        printf("dBASE Unix.");
        break;
    case 218:
        printf("Netix Message Posting Protocol.");
        break;
    case 219:
        printf("Unisys ARPs.");
        break;
    case 220:
        printf("Interactive Mail Access Protocol v3.");
        break;
    case 221:
        printf("Berkeley rlogind with SPX auth.");
        break;
    case 222:
        printf("Berkeley rshd with SPX auth.");
        break;
    case 223:
        printf("Certificate Distribution Center.");
        break;
    case 224:
        printf("masqdialer.");
        break;
    case 242:
        printf("Direct.");
        break;
    case 243:
        printf("Survey Measurement.");
        break;
    case 244:
        printf("inbusiness.");
        break;
    case 245:
        printf("LINK.");
        break;
    case 246:
        printf("Display Systems Protocol.");
        break;
    case 247:
        printf("SUBNTBCST_TFTP.");
        break;
    case 248:
        printf("bhfhs.");
        break;
    case 256:
        printf("RAP.");
        break;
    case 257:
        printf("Secure Electronic Transaction.");
        break;
    case 259:
        printf("Efficient Short Remote Operations.");
        break;
    case 260:
        printf("Openport.");
        break;
    case 261:
        printf("IIOP Name Service over TLS/SSL.");
        break;
    case 262:
        printf("Arcisdms.");
        break;
    case 263:
        printf("HDAP.");
        break;
    case 264:
        printf("BGMP.");
        break;
    case 265:
        printf("X-Bone CTL.");
        break;
    case 266:
        printf("SCSI on ST.");
        break;
    case 267:
        printf("Tobit David Service Layer.");
        break;
    case 268:
        printf("Tobit David Replica.");
        break;
    case 269:
        printf("MANET Protocols.");
        break;
    case 271:
        printf("IETF Network Endpoint Assessment (NEA) Posture Transport Protocol over TLS (PT-TLS).");
        break;
    case 280:
        printf("http-mgmt.");
        break;
    case 281:
        printf("Personal Link.");
        break;
    case 282:
        printf("Cable Port A/X.");
        break;
    case 283:
        printf("rescap.");
        break;
    case 284:
        printf("corerjd.");
        break;
    case 286:
        printf("FXP Communication.");
        break;
    case 287:
        printf("K-BLOCK.");
        break;
    case 308:
        printf("Novastor Backup.");
        break;
    case 309:
        printf("EntrustTime.");
        break;
    case 310:
        printf("bhmds.");
        break;
    case 311:
        printf("AppleShare IP WebAdmin.");
        break;
    case 312:
        printf("VSLMP.");
        break;
    case 313:
        printf("Magenta Logic.");
        break;
    case 314:
        printf("Opalis Robot.");
        break;
    case 315:
        printf("DPSI.");
        break;
    case 316:
        printf("decAuth.");
        break;
    case 317:
        printf("Zannet.");
        break;
    case 318:
        printf("PKIX TimeStamp.");
        break;
    case 319:
        printf("PTP Event.");
        break;
    case 320:
        printf("PTP General.");
        break;
    case 321:
        printf("PIP.");
        break;
    case 322:
        printf("RTSPS.");
        break;
    case 323:
        printf("Resource PKI to Router Protocol.");
        break;
    case 324:
        printf("Resource PKI to Router Protocol over TLS.");
        break;
    case 333:
        printf("Texar Security Port.");
        break;
    case 344:
        printf("Prospero Data Access Protocol.");
        break;
    case 345:
        printf("Perf Analysis Workbench.");
        break;
    case 346:
        printf("Zebra server.");
        break;
    case 347:
        printf("Fatmen Server.");
        break;
    case 348:
        printf("Cabletron Management Protocol.");
        break;
    case 349:
        printf("mftp.");
        break;
    case 350:
        printf("MATIP Type A.");
        break;
    case 351:
        printf("MATIP Type B / bhoetty.");
        break;
    case 352:
        printf("DTAG / bhoedap4.");
        break;
    case 353:
        printf("NDSAUTH.");
        break;
    case 354:
        printf("bh611.");
        break;
    case 355:
        printf("DATEX-ASN.");
        break;
    case 356:
        printf("Cloanto Net 1.");
        break;
    case 357:
        printf("bhevent.");
        break;
    case 358:
        printf("Shrinkwrap.");
        break;
    case 359:
        printf("Network Security Risk Management Protocol.");
        break;
    case 360:
        printf("scoi2odialog.");
        break;
    case 361:
        printf("Semantix.");
        break;
    case 362:
        printf("SRS Send.");
        break;
    case 363:
        printf("RSVP Tunnel.");
        break;
    case 364:
        printf("Aurora CMGR.");
        break;
    case 365:
        printf("DTK.");
        break;
    case 366:
        printf("ODMR.");
        break;
    case 367:
        printf("MortgageWare.");
        break;
    case 368:
        printf("QbikGDP.");
        break;
    case 369:
        printf("rpc2portmap.");
        break;
    case 370:
        printf("codaauth2.");
        break;
    case 371:
        printf("Clearcase.");
        break;
    case 372:
        printf("ListProcessor.");
        break;
    case 373:
        printf("Legent Corporation.");
        break;
    case 374:
        printf("Legent Corporation.");
        break;
    case 375:
        printf("Hassle.");
        break;
    case 376:
        printf("Amiga Envoy Network Inquiry Proto.");
        break;
    case 377:
        printf("NEC Corporation.");
        break;
    case 378:
        printf("NEC Corporation.");
        break;
    case 379:
        printf("TIA/EIA/IS-99 modem client.");
        break;
    case 380:
        printf("TIA/EIA/IS-99 modem server.");
        break;
    case 381:
        printf("hp performance data collector.");
        break;
    case 382:
        printf("hp performance data managed node.");
        break;
    case 383:
        printf("hp performance data alarm manager.");
        break;
    case 384:
        printf("A Remote Network Server System.");
        break;
    case 385:
        printf("IBM Application.");
        break;
    case 386:
        printf("ASA Message Router Object Def..");
        break;
    case 387:
        printf("Appletalk Update-Based Routing Pro..");
        break;
    case 388:
        printf("Unidata LDM.");
        break;
    case 389:
        printf("Lightweight Directory Access Protocol.");
        break;
    case 390:
        printf("UIS.");
        break;
    case 391:
        printf("SynOptics SNMP Relay Port.");
        break;
    case 392:
        printf("SynOptics Port Broker Port.");
        break;
    case 393:
        printf("Meta5.");
        break;
    case 394:
        printf("EMBL Nucleic Data Transfer.");
        break;
    case 395:
        printf("NetScout Control Protocol.");
        break;
    case 396:
        printf("Novell Netware over IP.");
        break;
    case 397:
        printf("Multi Protocol Trans. Net..");
        break;
    case 398:
        printf("Kryptolan.");
        break;
    case 399:
        printf("ISO Transport Class 2 Non-Control over TCP.");
        break;
    case 400:
        printf("Oracle Secure Backup.");
        break;
    case 401:
        printf("Uninterruptible Power Supply.");
        break;
    case 402:
        printf("Genie Protocol.");
        break;
    case 403:
        printf("decap.");
        break;
    case 404:
        printf("nced.");
        break;
    case 405:
        printf("ncld.");
        break;
    case 406:
        printf("Interactive Mail Support Protocol.");
        break;
    case 407:
        printf("Timbuktu.");
        break;
    case 408:
        printf("Prospero Resource Manager Sys. Man..");
        break;
    case 409:
        printf("Prospero Resource Manager Node Man..");
        break;
    case 410:
        printf("DECLadebug Remote Debug Protocol.");
        break;
    case 411:
        printf("Remote MT Protocol.");
        break;
    case 412:
        printf("Trap Convention Port.");
        break;
    case 413:
        printf("Storage Management Services Protocol.");
        break;
    case 414:
        printf("InfoSeek.");
        break;
    case 415:
        printf("BNet.");
        break;
    case 416:
        printf("Silverplatter.");
        break;
    case 417:
        printf("Onmux.");
        break;
    case 418:
        printf("Hyper-G.");
        break;
    case 419:
        printf("Ariel 1.");
        break;
    case 420:
        printf("SMPTE.");
        break;
    case 421:
        printf("Ariel 2.");
        break;
    case 422:
        printf("Ariel 3.");
        break;
    case 423:
        printf("IBM Operations Planning and Control Start.");
        break;
    case 424:
        printf("IBM Operations Planning and Control Track.");
        break;
    case 425:
        printf("ICAD.");
        break;
    case 426:
        printf("smartsdp.");
        break;
    case 427:
        printf("Server Location.");
        break;
    case 428:
        printf("OCS_CMU.");
        break;
    case 429:
        printf("OCS_AMU.");
        break;
    case 430:
        printf("UTMPSD.");
        break;
    case 431:
        printf("UTMPCD.");
        break;
    case 432:
        printf("IASD.");
        break;
    case 433:
        printf("NNTP for transit servers (NNSP).");
        break;
    case 434:
        printf("MobileIP-Agent.");
        break;
    case 435:
        printf("MobilIP-MN.");
        break;
    case 436:
        printf("DNA-CML.");
        break;
    case 437:
        printf("comscm.");
        break;
    case 438:
        printf("dsfgw.");
        break;
    case 439:
        printf("dasp.");
        break;
    case 440:
        printf("sgcp.");
        break;
    case 441:
        printf("decvms-sysmgt.");
        break;
    case 442:
        printf("cvc_hostd.");
        break;
    case 443:
        printf("http protocol over TLS/SSL.");
        break;
    case 444:
        printf("Simple Network Paging Protocol.");
        break;
    case 445:
        printf("Microsoft-DS.");
        break;
    case 446:
        printf("DDM-Remote Relational Database Access.");
        break;
    case 447:
        printf("DDM-Distributed File Management.");
        break;
    case 448:
        printf("DDM-Remote DB Access Using Secure Sockets.");
        break;
    case 449:
        printf("AS Server Mapper.");
        break;
    case 450:
        printf("Computer Supported Telecomunication Applications.");
        break;
    case 451:
        printf("Cray Network Semaphore server.");
        break;
    case 452:
        printf("Cray SFS config server.");
        break;
    case 453:
        printf("CreativeServer.");
        break;
    case 454:
        printf("ContentServer.");
        break;
    case 455:
        printf("CreativePartnr.");
        break;
    case 456:
        printf("macon-tcp.");
        break;
    case 457:
        printf("scohelp.");
        break;
    case 458:
        printf("apple quick time.");
        break;
    case 459:
        printf("ampr-rcmd.");
        break;
    case 460:
        printf("skronk.");
        break;
    case 461:
        printf("DataRampSrv.");
        break;
    case 462:
        printf("DataRampSrvSec.");
        break;
    case 463:
        printf("alpes.");
        break;
    case 464:
        printf("kpasswd.");
        break;
    case 465:
        printf("URL Rendezvous Directory for SSM / Message Submission over TLS protocol.");
        break;
    case 466:
        printf("digital-vrc.");
        break;
    case 467:
        printf("mylex-mapd.");
        break;
    case 468:
        printf("proturis.");
        break;
    case 469:
        printf("Radio Control Protocol.");
        break;
    case 470:
        printf("scx-proxy.");
        break;
    case 471:
        printf("Mondex.");
        break;
    case 472:
        printf("ljk-login.");
        break;
    case 473:
        printf("hybrid-pop.");
        break;
    case 474:
        printf("tn-tl-w1.");
        break;
    case 475:
        printf("tcpnethaspsrv.");
        break;
    case 476:
        printf("tn-tl-fd1.");
        break;
    case 477:
        printf("ss7ns.");
        break;
    case 478:
        printf("spsc.");
        break;
    case 479:
        printf("iafserver.");
        break;
    case 480:
        printf("iafdbase.");
        break;
    case 481:
        printf("Ph service.");
        break;
    case 482:
        printf("bgs-nsi.");
        break;
    case 483:
        printf("ulpnet.");
        break;
    case 484:
        printf("Integra Software Management Environment.");
        break;
    case 485:
        printf("Air Soft Power Burst.");
        break;
    case 486:
        printf("avian.");
        break;
    case 487:
        printf("saft Simple Asynchronous File Transfer.");
        break;
    case 488:
        printf("gss-http.");
        break;
    case 489:
        printf("nest-protocol.");
        break;
    case 490:
        printf("micom-pfs.");
        break;
    case 491:
        printf("go-login.");
        break;
    case 492:
        printf("Transport Independent Convergence for FNA.");
        break;
    case 493:
        printf("Transport Independent Convergence for FNA.");
        break;
    case 494:
        printf("POV-Ray.");
        break;
    case 495:
        printf("intecourier.");
        break;
    case 496:
        printf("PIM-RP-DISC.");
        break;
    case 497:
        printf("Retrospect backup and restore service.");
        break;
    case 498:
        printf("siam.");
        break;
    case 499:
        printf("ISO ILL Protocol.");
        break;
    case 500:
        printf("isakmp.");
        break;
    case 501:
        printf("STMF.");
        break;
    case 502:
        printf("Modbus Application Protocol.");
        break;
    case 503:
        printf("Intrinsa.");
        break;
    case 504:
        printf("citadel.");
        break;
    case 505:
        printf("mailbox-lm.");
        break;
    case 506:
        printf("ohimsrv.");
        break;
    case 507:
        printf("crs.");
        break;
    case 508:
        printf("xvttp.");
        break;
    case 509:
        printf("snare.");
        break;
    case 510:
        printf("FirstClass Protocol.");
        break;
    case 511:
        printf("PassGo.");
        break;
    case 512:
        printf("remote process execution; authentication performed using passwords and UNIX login names.");
        break;
    case 514:
        printf("cmd like exec, but automatic authentication is performed as for login server.");
        break;
    case 515:
        printf("spooler.");
        break;
    case 516:
        printf("videotex.");
        break;
    case 517:
        printf("like tenex link, but across machine - unfortunately, doesn't use link protocol (this is actually just a rendezvous port from which a tcp connection is established).");
        break;
    case 519:
        printf("unixtime.");
        break;
    case 520:
        printf("extended file name server.");
        break;
    case 521:
        printf("ripng.");
        break;
    case 522:
        printf("ULP.");
        break;
    case 523:
        printf("IBM-DB2.");
        break;
    case 524:
        printf("NCP.");
        break;
    case 525:
        printf("timeserver.");
        break;
    case 526:
        printf("newdate.");
        break;
    case 527:
        printf("Stock IXChange.");
        break;
    case 528:
        printf("Customer IXChange.");
        break;
    case 529:
        printf("IRC-SERV.");
        break;
    case 530:
        printf("rpc.");
        break;
    case 531:
        printf("chat.");
        break;
    case 532:
        printf("readnews.");
        break;
    case 533:
        printf("for emergency broadcasts.");
        break;
    case 534:
        printf("windream Admin.");
        break;
    case 535:
        printf("iiop.");
        break;
    case 536:
        printf("opalis-rdv.");
        break;
    case 537:
        printf("Networked Media Streaming Protocol.");
        break;
    case 538:
        printf("gdomap.");
        break;
    case 539:
        printf("Apertus Technologies Load Determination.");
        break;
    case 540:
        printf("uucpd.");
        break;
    case 541:
        printf("uucp-rlogin.");
        break;
    case 542:
        printf("commerce.");
        break;
    case 544:
        printf("krcmd.");
        break;
    case 545:
        printf("appleqtcsrvr.");
        break;
    case 546:
        printf("DHCPv6 Client.");
        break;
    case 547:
        printf("DHCPv6 Server.");
        break;
    case 548:
        printf("AFP over TCP.");
        break;
    case 549:
        printf("IDFP.");
        break;
    case 550:
        printf("new-who.");
        break;
    case 551:
        printf("cybercash.");
        break;
    case 552:
        printf("DeviceShare.");
        break;
    case 553:
        printf("pirp.");
        break;
    case 554:
        printf("Real Time Streaming Protocol (RTSP).");
        break;
    case 556:
        printf("rfs server.");
        break;
    case 557:
        printf("openvms-sysipc.");
        break;
    case 558:
        printf("SDNSKMP.");
        break;
    case 559:
        printf("TEEDTAP.");
        break;
    case 560:
        printf("rmonitord.");
        break;
    case 562:
        printf("chcmd.");
        break;
    case 563:
        printf("nntp protocol over TLS/SSL (was snntp).");
        break;
    case 564:
        printf("plan 9 file service.");
        break;
    case 565:
        printf("whoami.");
        break;
    case 566:
        printf("streettalk.");
        break;
    case 567:
        printf("banyan-rpc.");
        break;
    case 568:
        printf("microsoft shuttle.");
        break;
    case 569:
        printf("microsoft rome.");
        break;
    case 570:
        printf("demon.");
        break;
    case 571:
        printf("udemon.");
        break;
    case 572:
        printf("sonar.");
        break;
    case 573:
        printf("banyan-vip.");
        break;
    case 574:
        printf("FTP Software Agent System.");
        break;
    case 575:
        printf("VEMMI.");
        break;
    case 576:
        printf("ipcd.");
        break;
    case 577:
        printf("vnas.");
        break;
    case 578:
        printf("ipdd.");
        break;
    case 579:
        printf("decbsrv.");
        break;
    case 580:
        printf("SNTP HEARTBEAT.");
        break;
    case 581:
        printf("Bundle Discovery Protocol.");
        break;
    case 582:
        printf("SCC Security.");
        break;
    case 583:
        printf("Philips Video-Conferencing.");
        break;
    case 584:
        printf("Key Server.");
        break;
    case 586:
        printf("Password Change.");
        break;
    case 587:
        printf("Message Submission.");
        break;
    case 588:
        printf("CAL.");
        break;
    case 589:
        printf("EyeLink.");
        break;
    case 590:
        printf("TNS CML.");
        break;
    case 591:
        printf("FileMaker, Inc. - HTTP Alternate (see Port 80).");
        break;
    case 592:
        printf("Eudora Set.");
        break;
    case 593:
        printf("HTTP RPC Ep Map.");
        break;
    case 594:
        printf("TPIP.");
        break;
    case 595:
        printf("CAB Protocol.");
        break;
    case 596:
        printf("SMSD.");
        break;
    case 597:
        printf("PTC Name Service.");
        break;
    case 598:
        printf("SCO Web Server Manager 3.");
        break;
    case 599:
        printf("Aeolon Core Protocol.");
        break;
    case 600:
        printf("Sun IPC server.");
        break;
    case 601:
        printf("Reliable Syslog Service.");
        break;
    case 602:
        printf("XML-RPC over BEEP.");
        break;
    case 603:
        printf("IDXP.");
        break;
    case 604:
        printf("TUNNEL.");
        break;
    case 605:
        printf("SOAP over BEEP.");
        break;
    case 606:
        printf("Cray Unified Resource Manager.");
        break;
    case 607:
        printf("nqs.");
        break;
    case 608:
        printf("Sender-Initiated/Unsolicited File Transfer.");
        break;
    case 609:
        printf("npmp-trap.");
        break;
    case 610:
        printf("npmp-local.");
        break;
    case 611:
        printf("npmp-gui.");
        break;
    case 612:
        printf("HMMP Indication.");
        break;
    case 613:
        printf("HMMP Operation.");
        break;
    case 614:
        printf("SSLshell.");
        break;
    case 615:
        printf("Internet Configuration Manager.");
        break;
    case 616:
        printf("SCO System Administration Server.");
        break;
    case 617:
        printf("SCO Desktop Administration Server.");
        break;
    case 618:
        printf("DEI-ICDA.");
        break;
    case 619:
        printf("Compaq EVM.");
        break;
    case 620:
        printf("SCO WebServer Manager.");
        break;
    case 621:
        printf("ESCP.");
        break;
    case 622:
        printf("Collaborator.");
        break;
    case 623:
        printf("DMTF out-of-band web services management protocol.");
        break;
    case 624:
        printf("Crypto Admin.");
        break;
    case 625:
        printf("DEC DLM.");
        break;
    case 626:
        printf("ASIA.");
        break;
    case 627:
        printf("PassGo Tivoli.");
        break;
    case 628:
        printf("QMQP.");
        break;
    case 629:
        printf("3Com AMP3.");
        break;
    case 630:
        printf("RDA.");
        break;
    case 631:
        printf("IPP (Internet Printing Protocol).");
        break;
    case 632:
        printf("bmpp.");
        break;
    case 633:
        printf("Service Status update (Sterling Software).");
        break;
    case 634:
        printf("ginad.");
        break;
    case 635:
        printf("RLZ DBase.");
        break;
    case 636:
        printf("ldap protocol over TLS/SSL (was sldap).");
        break;
    case 637:
        printf("lanserver.");
        break;
    case 638:
        printf("mcns-sec.");
        break;
    case 639:
        printf("MSDP.");
        break;
    case 640:
        printf("entrust-sps.");
        break;
    case 641:
        printf("repcmd.");
        break;
    case 642:
        printf("ESRO-EMSDP V1.3.");
        break;
    case 643:
        printf("SANity.");
        break;
    case 644:
        printf("dwr.");
        break;
    case 645:
        printf("PSSC.");
        break;
    case 646:
        printf("LDP.");
        break;
    case 647:
        printf("DHCP Failover.");
        break;
    case 648:
        printf("Registry Registrar Protocol (RRP).");
        break;
    case 649:
        printf("Cadview-3d - streaming 3d models over the internet.");
        break;
    case 650:
        printf("OBEX.");
        break;
    case 651:
        printf("IEEE MMS.");
        break;
    case 652:
        printf("HELLO_PORT.");
        break;
    case 653:
        printf("RepCmd.");
        break;
    case 654:
        printf("AODV.");
        break;
    case 655:
        printf("TINC.");
        break;
    case 656:
        printf("SPMP.");
        break;
    case 657:
        printf("RMC.");
        break;
    case 658:
        printf("TenFold.");
        break;
    case 660:
        printf("MacOS Server Admin.");
        break;
    case 661:
        printf("HAP.");
        break;
    case 662:
        printf("PFTP.");
        break;
    case 663:
        printf("PureNoise.");
        break;
    case 664:
        printf("DMTF out-of-band secure web services management protocol.");
        break;
    case 665:
        printf("Sun DR.");
        break;
    case 666:
        printf("doom Id Software.");
        break;
    case 667:
        printf("campaign contribution disclosures - SDR Technologies.");
        break;
    case 668:
        printf("MeComm.");
        break;
    case 669:
        printf("MeRegister.");
        break;
    case 670:
        printf("VACDSM-SWS.");
        break;
    case 671:
        printf("VACDSM-APP.");
        break;
    case 672:
        printf("VPPS-QUA.");
        break;
    case 673:
        printf("CIMPLEX.");
        break;
    case 674:
        printf("ACAP.");
        break;
    case 675:
        printf("DCTP.");
        break;
    case 676:
        printf("VPPS Via.");
        break;
    case 677:
        printf("Virtual Presence Protocol.");
        break;
    case 678:
        printf("GNU Generation Foundation NCP.");
        break;
    case 679:
        printf("MRM.");
        break;
    case 680:
        printf("entrust-aaas.");
        break;
    case 681:
        printf("entrust-aams.");
        break;
    case 682:
        printf("XFR.");
        break;
    case 683:
        printf("CORBA IIOP.");
        break;
    case 684:
        printf("CORBA IIOP SSL.");
        break;
    case 685:
        printf("MDC Port Mapper.");
        break;
    case 686:
        printf("Hardware Control Protocol Wismar.");
        break;
    case 687:
        printf("asipregistry.");
        break;
    case 688:
        printf("ApplianceWare managment protocol.");
        break;
    case 689:
        printf("NMAP.");
        break;
    case 690:
        printf("Velneo Application Transfer Protocol.");
        break;
    case 691:
        printf("MS Exchange Routing.");
        break;
    case 692:
        printf("Hyperwave-ISP.");
        break;
    case 693:
        printf("almanid Connection Endpoint.");
        break;
    case 694:
        printf("ha-cluster.");
        break;
    case 695:
        printf("IEEE-MMS-SSL.");
        break;
    case 696:
        printf("RUSHD.");
        break;
    case 697:
        printf("UUIDGEN.");
        break;
    case 698:
        printf("OLSR.");
        break;
    case 699:
        printf("Access Network.");
        break;
    case 700:
        printf("Extensible Provisioning Protocol.");
        break;
    case 701:
        printf("Link Management Protocol (LMP).");
        break;
    case 702:
        printf("IRIS over BEEP.");
        break;
    case 704:
        printf("errlog copy/server daemon.");
        break;
    case 705:
        printf("AgentX.");
        break;
    case 706:
        printf("SILC.");
        break;
    case 707:
        printf("Borland DSJ.");
        break;
    case 709:
        printf("Entrust Key Management Service Handler.");
        break;
    case 710:
        printf("Entrust Administration Service Handler.");
        break;
    case 711:
        printf("Cisco TDP.");
        break;
    case 712:
        printf("TBRPF.");
        break;
    case 713:
        printf("IRIS over XPC.");
        break;
    case 714:
        printf("IRIS over XPCS.");
        break;
    case 715:
        printf("IRIS-LWZ.");
        break;
    case 729:
        printf("IBM NetView DM/6000 Server/Client.");
        break;
    case 730:
        printf("IBM NetView DM/6000 send/tcp.");
        break;
    case 731:
        printf("IBM NetView DM/6000 receive/tcp.");
        break;
    case 741:
        printf("netGW.");
        break;
    case 742:
        printf("Network based Rev. Cont. Sys..");
        break;
    case 744:
        printf("Flexible License Manager.");
        break;
    case 747:
        printf("Fujitsu Device Control.");
        break;
    case 748:
        printf("Russell Info Sci Calendar Manager.");
        break;
    case 749:
        printf("kerberos administration.");
        break;
    case 754:
        printf("send.");
        break;
    case 767:
        printf("phone.");
        break;
    case 777:
        printf("Multiling HTTP.");
        break;
    case 800:
        printf("mdbs_daemon .");
        break;
    case 802:
        printf("Modbus Application Protocol Secure.");
        break;
    case 810:
        printf("FCP.");
        break;
    case 828:
        printf("itm-mcell-s.");
        break;
    case 829:
        printf("PKIX-3 CA/RA.");
        break;
    case 830:
        printf("NETCONF over SSH.");
        break;
    case 831:
        printf("NETCONF over BEEP.");
        break;
    case 832:
        printf("NETCONF for SOAP over HTTPS.");
        break;
    case 833:
        printf("NETCONF for SOAP over BEEP.");
        break;
    case 847:
        printf("dhcp-failover 2.");
        break;
    case 848:
        printf("GDOI.");
        break;
    case 853:
        printf("DNS query-response protocol run over TLS/DTLS.");
        break;
    case 854:
        printf("Dynamic Link Exchange Protocol (DLEP).");
        break;
    case 860:
        printf("iSCSI.");
        break;
    case 861:
        printf("OWAMP-Control.");
        break;
    case 862:
        printf("Two-way Active Measurement Protocol (TWAMP) Control.");
        break;
    case 873:
        printf("rsync.");
        break;
    case 886:
        printf("ICL coNETion locate server.");
        break;
    case 887:
        printf("ICL coNETion server info.");
        break;
    case 888:
        printf("AccessBuilder / CD Database Protocol.");
        break;
    case 900:
        printf("OMG Initial Refs.");
        break;
    case 901:
        printf("SMPNAMERES.");
        break;
    case 902:
        printf("self documenting Telnet Door.");
        break;
    case 903:
        printf("self documenting Telnet Panic Door.");
        break;
    case 910:
        printf("Kerberized Internet Negotiation of Keys (KINK).");
        break;
    case 911:
        printf("xact-backup.");
        break;
    case 912:
        printf("APEX relay-relay service.");
        break;
    case 913:
        printf("APEX endpoint-relay service.");
        break;
    case 953:
        printf("BIND9 remote name daemon controller.");
        break;
    case 989:
        printf("ftp protocol, data, over TLS/SSL.");
        break;
    case 990:
        printf("ftp protocol, control, over TLS/SSL.");
        break;
    case 991:
        printf("Netnews Administration System.");
        break;
    case 992:
        printf("telnet protocol over TLS/SSL.");
        break;
    case 993:
        printf("IMAP over TLS protocol.");
        break;
    case 995:
        printf("POP3 over TLS protocol.");
        break;
    case 996:
        printf("vsinet.");
        break;
    case 1001:
        printf("HTTP Web Push.");
        break;
    case 1010:
        printf("surf.");
        break;
    case 1021:
        printf("RFC3692-style Experiment 1.");
        break;
    case 1022:
        printf("RFC3692-style Experiment 2.");
        break;
    case 1025:
        printf("network blackjack.");
        break;
    case 1026:
        printf("Calendar Access Protocol.");
        break;
    case 1029:
        printf("Solid Mux Server.");
        break;
    case 1033:
        printf("local netinfo port.");
        break;
    case 1034:
        printf("ActiveSync Notifications.");
        break;
    case 1035:
        printf("MX-XR RPC.");
        break;
    case 1036:
        printf("Nebula Secure Segment Transfer Protocol.");
        break;
    case 1037:
        printf("AMS.");
        break;
    case 1038:
        printf("Message Tracking Query Protocol.");
        break;
    case 1039:
        printf("Streamlined Blackhole.");
        break;
    case 1040:
        printf("Netarx Netcare.");
        break;
    case 1041:
        printf("AK2 Product.");
        break;
    case 1042:
        printf("Subnet Roaming.");
        break;
    case 1043:
        printf("BOINC Client Control.");
        break;
    case 1044:
        printf("Dev Consortium Utility.");
        break;
    case 1045:
        printf("Fingerprint Image Transfer Protocol.");
        break;
    case 1046:
        printf("WebFilter Remote Monitor.");
        break;
    case 1047:
        printf("Sun's NEO Object Request Broker.");
        break;
    case 1048:
        printf("Sun's NEO Object Request Broker.");
        break;
    case 1049:
        printf("Tobit David Postman VPMN.");
        break;
    case 1050:
        printf("CORBA Management Agent.");
        break;
    case 1051:
        printf("Optima VNET.");
        break;
    case 1052:
        printf("Dynamic DNS Tools.");
        break;
    case 1053:
        printf("Remote Assistant (RA).");
        break;
    case 1054:
        printf("BRVREAD.");
        break;
    case 1055:
        printf("ANSYS - License Manager.");
        break;
    case 1056:
        printf("VFO.");
        break;
    case 1057:
        printf("STARTRON.");
        break;
    case 1058:
        printf("nim.");
        break;
    case 1059:
        printf("nimreg.");
        break;
    case 1060:
        printf("POLESTAR.");
        break;
    case 1061:
        printf("KIOSK.");
        break;
    case 1062:
        printf("Veracity.");
        break;
    case 1063:
        printf("KyoceraNetDev.");
        break;
    case 1064:
        printf("JSTEL.");
        break;
    case 1065:
        printf("SYSCOMLAN.");
        break;
    case 1066:
        printf("FPO-FNS.");
        break;
    case 1067:
        printf("Installation Bootstrap Proto. Serv..");
        break;
    case 1068:
        printf("Installation Bootstrap Proto. Cli..");
        break;
    case 1069:
        printf("COGNEX-INSIGHT.");
        break;
    case 1070:
        printf("GMRUpdateSERV.");
        break;
    case 1071:
        printf("BSQUARE-VOIP.");
        break;
    case 1072:
        printf("CARDAX.");
        break;
    case 1073:
        printf("Bridge Control.");
        break;
    case 1074:
        printf("Warmspot Management Protocol.");
        break;
    case 1075:
        printf("RDRMSHC.");
        break;
    case 1076:
        printf("DAB STI-C.");
        break;
    case 1077:
        printf("IMGames.");
        break;
    case 1078:
        printf("Avocent Proxy Protocol.");
        break;
    case 1079:
        printf("ASPROVATalk.");
        break;
    case 1080:
        printf("Socks.");
        break;
    case 1081:
        printf("PVUNIWIEN.");
        break;
    case 1082:
        printf("AMT-ESD-PROT.");
        break;
    case 1083:
        printf("Anasoft License Manager.");
        break;
    case 1084:
        printf("Anasoft License Manager.");
        break;
    case 1085:
        printf("Web Objects.");
        break;
    case 1086:
        printf("CPL Scrambler Logging.");
        break;
    case 1087:
        printf("CPL Scrambler Internal.");
        break;
    case 1088:
        printf("CPL Scrambler Alarm Log.");
        break;
    case 1089:
        printf("FF Annunciation.");
        break;
    case 1090:
        printf("FF Fieldbus Message Specification.");
        break;
    case 1091:
        printf("FF System Management.");
        break;
    case 1092:
        printf("Open Business Reporting Protocol.");
        break;
    case 1093:
        printf("PROOFD.");
        break;
    case 1094:
        printf("ROOTD.");
        break;
    case 1095:
        printf("NICELink.");
        break;
    case 1096:
        printf("Common Name Resolution Protocol.");
        break;
    case 1097:
        printf("Sun Cluster Manager.");
        break;
    case 1098:
        printf("RMI Activation.");
        break;
    case 1099:
        printf("RMI Registry.");
        break;
    case 1100:
        printf("MCTP.");
        break;
    case 1101:
        printf("PT2-DISCOVER.");
        break;
    case 1102:
        printf("ADOBE SERVER 1.");
        break;
    case 1103:
        printf("ADOBE SERVER 2.");
        break;
    case 1104:
        printf("XRL.");
        break;
    case 1105:
        printf("FTRANHC.");
        break;
    case 1106:
        printf("ISOIPSIGPORT-1.");
        break;
    case 1107:
        printf("ISOIPSIGPORT-2.");
        break;
    case 1108:
        printf("ratio-adp.");
        break;
    case 1110:
        printf("Start web admin server.");
        break;
    case 1111:
        printf("LM Social Server.");
        break;
    case 1112:
        printf("Intelligent Communication Protocol.");
        break;
    case 1113:
        printf("Licklider Transmission Protocol.");
        break;
    case 1114:
        printf("Mini SQL.");
        break;
    case 1115:
        printf("ARDUS Transfer.");
        break;
    case 1116:
        printf("ARDUS Control.");
        break;
    case 1117:
        printf("ARDUS Multicast Transfer.");
        break;
    case 1118:
        printf("SACRED.");
        break;
    case 1119:
        printf("Battle.net Chat/Game Protocol.");
        break;
    case 1120:
        printf("Battle.net File Transfer Protocol.");
        break;
    case 1121:
        printf("Datalode RMPP.");
        break;
    case 1122:
        printf("availant-mgr.");
        break;
    case 1123:
        printf("Murray.");
        break;
    case 1124:
        printf("HP VMM Control.");
        break;
    case 1125:
        printf("HP VMM Agent.");
        break;
    case 1126:
        printf("HP VMM Agent.");
        break;
    case 1127:
        printf("KWDB Remote Communication.");
        break;
    case 1128:
        printf("SAPHostControl over SOAP/HTTP.");
        break;
    case 1129:
        printf("SAPHostControl over SOAP/HTTPS.");
        break;
    case 1130:
        printf("CAC App Service Protocol.");
        break;
    case 1131:
        printf("CAC App Service Protocol Encripted.");
        break;
    case 1132:
        printf("KVM-via-IP Management Service.");
        break;
    case 1133:
        printf("Data Flow Network.");
        break;
    case 1134:
        printf("MicroAPL APLX.");
        break;
    case 1135:
        printf("OmniVision Communication Service.");
        break;
    case 1136:
        printf("HHB Gateway Control.");
        break;
    case 1137:
        printf("TRIM Workgroup Service.");
        break;
    case 1138:
        printf("encrypted admin requests.");
        break;
    case 1139:
        printf("Enterprise Virtual Manager.");
        break;
    case 1140:
        printf("AutoNOC Network Operations Protocol.");
        break;
    case 1141:
        printf("User Message Service.");
        break;
    case 1142:
        printf("User Discovery Service.");
        break;
    case 1143:
        printf("Infomatryx Exchange.");
        break;
    case 1144:
        printf("Fusion Script.");
        break;
    case 1145:
        printf("X9 iCue Show Control.");
        break;
    case 1146:
        printf("audit transfer.");
        break;
    case 1147:
        printf("CAPIoverLAN.");
        break;
    case 1148:
        printf("Elfiq Replication Service.");
        break;
    case 1149:
        printf("BlueView Sonar Service.");
        break;
    case 1150:
        printf("Blaze File Server.");
        break;
    case 1151:
        printf("Unizensus Login Server.");
        break;
    case 1152:
        printf("Winpopup LAN Messenger.");
        break;
    case 1153:
        printf("ANSI C12.22 Port.");
        break;
    case 1154:
        printf("Community Service.");
        break;
    case 1155:
        printf("Network File Access.");
        break;
    case 1156:
        printf("iasControl OMS.");
        break;
    case 1157:
        printf("Oracle iASControl.");
        break;
    case 1158:
        printf("dbControl OMS.");
        break;
    case 1159:
        printf("Oracle OMS.");
        break;
    case 1160:
        printf("DB Lite Mult-User Server.");
        break;
    case 1161:
        printf("Health Polling.");
        break;
    case 1162:
        printf("Health Trap.");
        break;
    case 1163:
        printf("SmartDialer Data Protocol.");
        break;
    case 1164:
        printf("QSM Proxy Service.");
        break;
    case 1165:
        printf("QSM GUI Service.");
        break;
    case 1166:
        printf("QSM RemoteExec.");
        break;
    case 1167:
        printf("Cisco IP SLAs Control Protocol.");
        break;
    case 1168:
        printf("VChat Conference Service.");
        break;
    case 1169:
        printf("TRIPWIRE.");
        break;
    case 1170:
        printf("AT+C License Manager.");
        break;
    case 1171:
        printf("AT+C FmiApplicationServer.");
        break;
    case 1172:
        printf("DNA Protocol.");
        break;
    case 1173:
        printf("D-Cinema Request-Response.");
        break;
    case 1174:
        printf("FlashNet Remote Admin.");
        break;
    case 1175:
        printf("Dossier Server.");
        break;
    case 1176:
        printf("Indigo Home Server.");
        break;
    case 1177:
        printf("DKMessenger Protocol.");
        break;
    case 1178:
        printf("SGI Storage Manager.");
        break;
    case 1179:
        printf("Backup To Neighbor.");
        break;
    case 1180:
        printf("Millicent Client Proxy.");
        break;
    case 1181:
        printf("3Com Net Management.");
        break;
    case 1182:
        printf("AcceleNet Control.");
        break;
    case 1183:
        printf("LL Surfup HTTP.");
        break;
    case 1184:
        printf("LL Surfup HTTPS.");
        break;
    case 1185:
        printf("Catchpole port.");
        break;
    case 1186:
        printf("MySQL Cluster Manager.");
        break;
    case 1187:
        printf("Alias Service.");
        break;
    case 1188:
        printf("HP Web Admin.");
        break;
    case 1189:
        printf("Unet Connection.");
        break;
    case 1190:
        printf("CommLinx GPS / AVL System.");
        break;
    case 1191:
        printf("General Parallel File System.");
        break;
    case 1192:
        printf("caids sensors channel.");
        break;
    case 1193:
        printf("Five Across Server.");
        break;
    case 1194:
        printf("OpenVPN.");
        break;
    case 1195:
        printf("RSF-1 clustering.");
        break;
    case 1196:
        printf("Network Magic.");
        break;
    case 1197:
        printf("Carrius Remote Access.");
        break;
    case 1198:
        printf("cajo reference discovery.");
        break;
    case 1199:
        printf("DMIDI.");
        break;
    case 1200:
        printf("SCOL.");
        break;
    case 1201:
        printf("Nucleus Sand Database Server.");
        break;
    case 1202:
        printf("caiccipc.");
        break;
    case 1203:
        printf("License Validation.");
        break;
    case 1204:
        printf("Log Request Listener.");
        break;
    case 1205:
        printf("Accord-MGC.");
        break;
    case 1206:
        printf("Anthony Data.");
        break;
    case 1207:
        printf("MetaSage.");
        break;
    case 1208:
        printf("SEAGULL AIS.");
        break;
    case 1209:
        printf("IPCD3.");
        break;
    case 1210:
        printf("EOSS.");
        break;
    case 1211:
        printf("Groove DPP.");
        break;
    case 1212:
        printf("lupa.");
        break;
    case 1213:
        printf("Medtronic/Physio-Control LIFENET.");
        break;
    case 1214:
        printf("KAZAA.");
        break;
    case 1215:
        printf("scanSTAT 1.0.");
        break;
    case 1216:
        printf("ETEBAC 5.");
        break;
    case 1217:
        printf("HPSS NonDCE Gateway.");
        break;
    case 1218:
        printf("AeroFlight-ADs.");
        break;
    case 1219:
        printf("AeroFlight-Ret.");
        break;
    case 1220:
        printf("QT SERVER ADMIN.");
        break;
    case 1221:
        printf("SweetWARE Apps.");
        break;
    case 1222:
        printf("SNI R&D network.");
        break;
    case 1223:
        printf("TrulyGlobal Protocol.");
        break;
    case 1224:
        printf("VPNz.");
        break;
    case 1225:
        printf("SLINKYSEARCH.");
        break;
    case 1226:
        printf("STGXFWS.");
        break;
    case 1227:
        printf("DNS2Go.");
        break;
    case 1228:
        printf("FLORENCE.");
        break;
    case 1229:
        printf("ZENworks Tiered Electronic Distribution.");
        break;
    case 1230:
        printf("Periscope.");
        break;
    case 1231:
        printf("menandmice-lpm.");
        break;
    case 1232:
        printf("Remote systems monitoring.");
        break;
    case 1233:
        printf("Universal App Server.");
        break;
    case 1234:
        printf("Infoseek Search Agent.");
        break;
    case 1235:
        printf("mosaicsyssvc1.");
        break;
    case 1236:
        printf("bvcontrol.");
        break;
    case 1237:
        printf("tsdos390.");
        break;
    case 1238:
        printf("hacl-qs.");
        break;
    case 1239:
        printf("NMSD.");
        break;
    case 1240:
        printf("Instantia.");
        break;
    case 1241:
        printf("nessus.");
        break;
    case 1242:
        printf("NMAS over IP.");
        break;
    case 1243:
        printf("SerialGateway.");
        break;
    case 1244:
        printf("isbconference1.");
        break;
    case 1245:
        printf("isbconference2.");
        break;
    case 1246:
        printf("payrouter.");
        break;
    case 1247:
        printf("VisionPyramid.");
        break;
    case 1248:
        printf("hermes.");
        break;
    case 1249:
        printf("Mesa Vista Co.");
        break;
    case 1250:
        printf("swldy-sias.");
        break;
    case 1251:
        printf("servergraph.");
        break;
    case 1252:
        printf("bspne-pcc.");
        break;
    case 1253:
        printf("q55-pcc.");
        break;
    case 1254:
        printf("de-noc.");
        break;
    case 1255:
        printf("de-cache-query.");
        break;
    case 1256:
        printf("de-server.");
        break;
    case 1257:
        printf("Shockwave 2.");
        break;
    case 1258:
        printf("Open Network Library.");
        break;
    case 1259:
        printf("Open Network Library Voice.");
        break;
    case 1260:
        printf("ibm-ssd.");
        break;
    case 1261:
        printf("mpshrsv.");
        break;
    case 1262:
        printf("QNTS-ORB.");
        break;
    case 1263:
        printf("dka.");
        break;
    case 1264:
        printf("PRAT.");
        break;
    case 1265:
        printf("DSSIAPI.");
        break;
    case 1266:
        printf("DELLPWRAPPKS.");
        break;
    case 1267:
        printf("eTrust Policy Compliance.");
        break;
    case 1268:
        printf("PROPEL-MSGSYS.");
        break;
    case 1269:
        printf("WATiLaPP.");
        break;
    case 1270:
        printf("Microsoft Operations Manager.");
        break;
    case 1271:
        printf("eXcW.");
        break;
    case 1272:
        printf("CSPMLockMgr.");
        break;
    case 1273:
        printf("EMC-Gateway.");
        break;
    case 1274:
        printf("t1distproc.");
        break;
    case 1275:
        printf("ivcollector.");
        break;
    case 1277:
        printf("mqs.");
        break;
    case 1278:
        printf("Dell Web Admin 1.");
        break;
    case 1279:
        printf("Dell Web Admin 2.");
        break;
    case 1280:
        printf("Pictrography.");
        break;
    case 1281:
        printf("healthd.");
        break;
    case 1282:
        printf("Emperion.");
        break;
    case 1283:
        printf("Product Information.");
        break;
    case 1284:
        printf("IEE-QFX.");
        break;
    case 1285:
        printf("neoiface.");
        break;
    case 1286:
        printf("netuitive.");
        break;
    case 1287:
        printf("RouteMatch Com.");
        break;
    case 1288:
        printf("NavBuddy.");
        break;
    case 1289:
        printf("JWalkServer.");
        break;
    case 1290:
        printf("WinJaServer.");
        break;
    case 1291:
        printf("SEAGULLLMS.");
        break;
    case 1292:
        printf("dsdn.");
        break;
    case 1293:
        printf("PKT-KRB-IPSec.");
        break;
    case 1294:
        printf("CMMdriver.");
        break;
    case 1295:
        printf("End-by-Hop Transmission Protocol.");
        break;
    case 1296:
        printf("dproxy.");
        break;
    case 1297:
        printf("sdproxy.");
        break;
    case 1298:
        printf("lpcp.");
        break;
    case 1299:
        printf("hp-sci.");
        break;
    case 1300:
        printf("H.323 Secure Call Control Signalling.");
        break;
    case 1301:
        printf("CI3-Software-1.");
        break;
    case 1302:
        printf("CI3-Software-2.");
        break;
    case 1303:
        printf("sftsrv.");
        break;
    case 1304:
        printf("Boomerang.");
        break;
    case 1305:
        printf("pe-mike.");
        break;
    case 1306:
        printf("RE-Conn-Proto.");
        break;
    case 1307:
        printf("Pacmand.");
        break;
    case 1308:
        printf("Optical Domain Service Interconnect (ODSI).");
        break;
    case 1309:
        printf("JTAG server.");
        break;
    case 1310:
        printf("Husky.");
        break;
    case 1311:
        printf("RxMon.");
        break;
    case 1312:
        printf("STI Envision.");
        break;
    case 1313:
        printf("BMC_PATROLDB.");
        break;
    case 1314:
        printf("Photoscript Distributed Printing System.");
        break;
    case 1315:
        printf("E.L.S., Event Listener Service.");
        break;
    case 1316:
        printf("Exbit-ESCP.");
        break;
    case 1317:
        printf("vrts-ipcserver.");
        break;
    case 1318:
        printf("krb5gatekeeper.");
        break;
    case 1319:
        printf("AMX-ICSP.");
        break;
    case 1320:
        printf("AMX-AXBNET.");
        break;
    case 1321:
        printf("PIP.");
        break;
    case 1322:
        printf("Novation.");
        break;
    case 1323:
        printf("brcd.");
        break;
    case 1324:
        printf("delta-mcp.");
        break;
    case 1325:
        printf("DX-Instrument.");
        break;
    case 1326:
        printf("WIMSIC.");
        break;
    case 1327:
        printf("Ultrex.");
        break;
    case 1328:
        printf("EWALL.");
        break;
    case 1329:
        printf("netdb-export.");
        break;
    case 1330:
        printf("StreetPerfect.");
        break;
    case 1331:
        printf("intersan.");
        break;
    case 1332:
        printf("PCIA RXP-B.");
        break;
    case 1333:
        printf("Password Policy.");
        break;
    case 1334:
        printf("writesrv.");
        break;
    case 1335:
        printf("Digital Notary Protocol.");
        break;
    case 1336:
        printf("Instant Service Chat.");
        break;
    case 1337:
        printf("menandmice DNS.");
        break;
    case 1338:
        printf("WMC-log-svr.");
        break;
    case 1339:
        printf("kjtsiteserver.");
        break;
    case 1340:
        printf("NAAP.");
        break;
    case 1341:
        printf("QuBES.");
        break;
    case 1342:
        printf("ESBroker.");
        break;
    case 1343:
        printf("re101.");
        break;
    case 1344:
        printf("ICAP.");
        break;
    case 1345:
        printf("VPJP.");
        break;
    case 1346:
        printf("Alta Analytics License Manager.");
        break;
    case 1347:
        printf("multi media conferencing.");
        break;
    case 1348:
        printf("multi media conferencing.");
        break;
    case 1349:
        printf("Registration Network Protocol.");
        break;
    case 1350:
        printf("Registration Network Protocol.");
        break;
    case 1351:
        printf("Digital Tool Works (MIT).");
        break;
    case 1352:
        printf("Lotus Note.");
        break;
    case 1353:
        printf("Relief Consulting.");
        break;
    case 1354:
        printf("Five Across XSIP Network.");
        break;
    case 1355:
        printf("Intuitive Edge.");
        break;
    case 1356:
        printf("CuillaMartin Company.");
        break;
    case 1357:
        printf("Electronic PegBoard.");
        break;
    case 1358:
        printf("CONNLCLI.");
        break;
    case 1359:
        printf("FTSRV.");
        break;
    case 1360:
        printf("MIMER.");
        break;
    case 1361:
        printf("LinX.");
        break;
    case 1362:
        printf("TimeFlies.");
        break;
    case 1363:
        printf("Network DataMover Requester.");
        break;
    case 1364:
        printf("Network DataMover Server.");
        break;
    case 1365:
        printf("Network Software Associates.");
        break;
    case 1366:
        printf("Novell NetWare Comm Service Platform.");
        break;
    case 1367:
        printf("DCS.");
        break;
    case 1368:
        printf("ScreenCast.");
        break;
    case 1369:
        printf("GlobalView to Unix Shell.");
        break;
    case 1370:
        printf("Unix Shell to GlobalView.");
        break;
    case 1371:
        printf("Fujitsu Config Protocol.");
        break;
    case 1372:
        printf("Fujitsu Config Protocol.");
        break;
    case 1373:
        printf("Chromagrafx.");
        break;
    case 1374:
        printf("EPI Software Systems.");
        break;
    case 1375:
        printf("Bytex.");
        break;
    case 1376:
        printf("IBM Person to Person Software.");
        break;
    case 1377:
        printf("Cichlid License Manager.");
        break;
    case 1378:
        printf("Elan License Manager.");
        break;
    case 1379:
        printf("Integrity Solutions.");
        break;
    case 1380:
        printf("Telesis Network License Manager.");
        break;
    case 1381:
        printf("Apple Network License Manager.");
        break;
    case 1382:
        printf("udt_os.");
        break;
    case 1383:
        printf("GW Hannaway Network License Manager.");
        break;
    case 1384:
        printf("Objective Solutions License Manager.");
        break;
    case 1385:
        printf("Atex Publishing License Manager.");
        break;
    case 1386:
        printf("CheckSum License Manager.");
        break;
    case 1387:
        printf("Computer Aided Design Software Inc LM.");
        break;
    case 1388:
        printf("Objective Solutions DataBase Cache.");
        break;
    case 1389:
        printf("Document Manager.");
        break;
    case 1390:
        printf("Storage Controller.");
        break;
    case 1391:
        printf("Storage Access Server.");
        break;
    case 1392:
        printf("Print Manager.");
        break;
    case 1393:
        printf("Network Log Server.");
        break;
    case 1394:
        printf("Network Log Client.");
        break;
    case 1395:
        printf("PC Workstation Manager software.");
        break;
    case 1396:
        printf("DVL Active Mail.");
        break;
    case 1397:
        printf("Audio Active Mail.");
        break;
    case 1398:
        printf("Video Active Mail.");
        break;
    case 1399:
        printf("Cadkey License Manager.");
        break;
    case 1400:
        printf("Cadkey Tablet Daemon.");
        break;
    case 1401:
        printf("Goldleaf License Manager.");
        break;
    case 1402:
        printf("Prospero Resource Manager.");
        break;
    case 1403:
        printf("Prospero Resource Manager.");
        break;
    case 1404:
        printf("Infinite Graphics License Manager.");
        break;
    case 1405:
        printf("IBM Remote Execution Starter.");
        break;
    case 1406:
        printf("NetLabs License Manager.");
        break;
    case 1407:
        printf("TIBET Data Server.");
        break;
    case 1408:
        printf("Sophia License Manager.");
        break;
    case 1409:
        printf("Here License Manager.");
        break;
    case 1410:
        printf("HiQ License Manager.");
        break;
    case 1411:
        printf("AudioFile.");
        break;
    case 1412:
        printf("InnoSys.");
        break;
    case 1413:
        printf("Innosys-ACL.");
        break;
    case 1414:
        printf("IBM MQSeries.");
        break;
    case 1415:
        printf("DBStar.");
        break;
    case 1416:
        printf("Novell LU6.2 .");
        break;
    case 1417:
        printf("Timbuktu Service 1 Port.");
        break;
    case 1418:
        printf("Timbuktu Service 2 Port.");
        break;
    case 1419:
        printf("Timbuktu Service 3 Port.");
        break;
    case 1420:
        printf("Timbuktu Service 4 Port.");
        break;
    case 1421:
        printf("Gandalf License Manager.");
        break;
    case 1422:
        printf("Autodesk License Manager.");
        break;
    case 1423:
        printf("Essbase Arbor Software.");
        break;
    case 1424:
        printf("Hybrid Encryption Protocol.");
        break;
    case 1425:
        printf("Zion Software License Manager.");
        break;
    case 1426:
        printf("Satellite-data Acquisition System 1.");
        break;
    case 1427:
        printf("mloadd monitoring tool.");
        break;
    case 1428:
        printf("Informatik License Manager.");
        break;
    case 1429:
        printf("Hypercom NMS.");
        break;
    case 1430:
        printf("Hypercom TPDU.");
        break;
    case 1431:
        printf("Reverse Gossip Transport.");
        break;
    case 1432:
        printf("Blueberry Software License Manager.");
        break;
    case 1433:
        printf("Microsoft-SQL-Server.");
        break;
    case 1434:
        printf("Microsoft-SQL-Monitor.");
        break;
    case 1435:
        printf("IBM CICS.");
        break;
    case 1436:
        printf("Satellite-data Acquisition System 2.");
        break;
    case 1437:
        printf("Tabula.");
        break;
    case 1438:
        printf("Eicon Security Agent/Server.");
        break;
    case 1439:
        printf("Eicon X25/SNA Gateway.");
        break;
    case 1440:
        printf("Eicon Service Location Protocol.");
        break;
    case 1441:
        printf("Cadis License Management.");
        break;
    case 1442:
        printf("Cadis License Management.");
        break;
    case 1443:
        printf("Integrated Engineering Software.");
        break;
    case 1444:
        printf("Marcam  License Management.");
        break;
    case 1445:
        printf("Proxima License Manager.");
        break;
    case 1446:
        printf("Optical Research Associates License Manager.");
        break;
    case 1447:
        printf("Applied Parallel Research LM.");
        break;
    case 1448:
        printf("OpenConnect License Manager.");
        break;
    case 1449:
        printf("PEport.");
        break;
    case 1450:
        printf("Tandem Distributed Workbench Facility.");
        break;
    case 1451:
        printf("IBM Information Management.");
        break;
    case 1452:
        printf("GTE Government Systems License Man.");
        break;
    case 1453:
        printf("Genie License Manager.");
        break;
    case 1454:
        printf("interHDL License Manager.");
        break;
    case 1455:
        printf("ESL License Manager.");
        break;
    case 1456:
        printf("DCA.");
        break;
    case 1457:
        printf("Valisys License Manager.");
        break;
    case 1458:
        printf("Nichols Research Corp..");
        break;
    case 1459:
        printf("Proshare Notebook Application.");
        break;
    case 1460:
        printf("Proshare Notebook Application.");
        break;
    case 1461:
        printf("IBM Wireless LAN.");
        break;
    case 1462:
        printf("World License Manager.");
        break;
    case 1463:
        printf("Nucleus.");
        break;
    case 1464:
        printf("MSL License Manager.");
        break;
    case 1465:
        printf("Pipes Platform.");
        break;
    case 1466:
        printf("Ocean Software License Manager.");
        break;
    case 1467:
        printf("CSDMBASE.");
        break;
    case 1468:
        printf("CSDM.");
        break;
    case 1469:
        printf("Active Analysis Limited License Manager.");
        break;
    case 1470:
        printf("Universal Analytics.");
        break;
    case 1471:
        printf("csdmbase.");
        break;
    case 1472:
        printf("csdm.");
        break;
    case 1473:
        printf("OpenMath.");
        break;
    case 1474:
        printf("Telefinder.");
        break;
    case 1475:
        printf("Taligent License Manager.");
        break;
    case 1476:
        printf("clvm-cfg.");
        break;
    case 1477:
        printf("ms-sna-server.");
        break;
    case 1478:
        printf("ms-sna-base.");
        break;
    case 1479:
        printf("dberegister.");
        break;
    case 1480:
        printf("PacerForum.");
        break;
    case 1481:
        printf("AIRS.");
        break;
    case 1482:
        printf("Miteksys License Manager.");
        break;
    case 1483:
        printf("AFS License Manager.");
        break;
    case 1484:
        printf("Confluent License Manager.");
        break;
    case 1485:
        printf("LANSource.");
        break;
    case 1486:
        printf("nms_topo_serv.");
        break;
    case 1487:
        printf("LocalInfoSrvr.");
        break;
    case 1488:
        printf("DocStor.");
        break;
    case 1489:
        printf("dmdocbroker.");
        break;
    case 1490:
        printf("insitu-conf.");
        break;
    case 1492:
        printf("stone-design-1.");
        break;
    case 1493:
        printf("netmap_lm.");
        break;
    case 1494:
        printf("ica.");
        break;
    case 1495:
        printf("cvc.");
        break;
    case 1496:
        printf("liberty-lm.");
        break;
    case 1497:
        printf("rfx-lm.");
        break;
    case 1498:
        printf("Sybase SQL Any.");
        break;
    case 1499:
        printf("Federico Heinz Consultora.");
        break;
    case 1500:
        printf("VLSI License Manager.");
        break;
    case 1501:
        printf("Satellite-data Acquisition System 3.");
        break;
    case 1502:
        printf("Shiva.");
        break;
    case 1503:
        printf("Databeam.");
        break;
    case 1504:
        printf("EVB Software Engineering License Manager.");
        break;
    case 1505:
        printf("Funk Software, Inc..");
        break;
    case 1506:
        printf("Universal Time daemon (utcd).");
        break;
    case 1507:
        printf("symplex.");
        break;
    case 1508:
        printf("diagmond.");
        break;
    case 1509:
        printf("Robcad, Ltd. License Manager.");
        break;
    case 1510:
        printf("Midland Valley Exploration Ltd. Lic. Man..");
        break;
    case 1511:
        printf("3l-l1.");
        break;
    case 1512:
        printf("Microsoft's Windows Internet Name Service.");
        break;
    case 1513:
        printf("Fujitsu Systems Business of America, Inc.");
        break;
    case 1514:
        printf("Fujitsu Systems Business of America, Inc.");
        break;
    case 1515:
        printf("ifor-protocol.");
        break;
    case 1516:
        printf("Virtual Places Audio data.");
        break;
    case 1517:
        printf("Virtual Places Audio control.");
        break;
    case 1518:
        printf("Virtual Places Video data.");
        break;
    case 1519:
        printf("Virtual Places Video control.");
        break;
    case 1520:
        printf("atm zip office.");
        break;
    case 1521:
        printf("nCube License Manager.");
        break;
    case 1522:
        printf("Ricardo North America License Manager.");
        break;
    case 1523:
        printf("cichild.");
        break;
    case 1524:
        printf("ingres.");
        break;
    case 1525:
        printf("oracle / Prospero Directory Service non-priv.");
        break;
    case 1526:
        printf("Prospero Data Access Prot non-priv.");
        break;
    case 1527:
        printf("oracle.");
        break;
    case 1529:
        printf("oracle.");
        break;
    case 1530:
        printf("rap-service.");
        break;
    case 1531:
        printf("rap-listen.");
        break;
    case 1532:
        printf("miroconnect.");
        break;
    case 1533:
        printf("Virtual Places Software.");
        break;
    case 1534:
        printf("micromuse-lm.");
        break;
    case 1535:
        printf("ampr-info.");
        break;
    case 1536:
        printf("ampr-inter.");
        break;
    case 1537:
        printf("isi-lm.");
        break;
    case 1538:
        printf("3ds-lm.");
        break;
    case 1539:
        printf("Intellistor License Manager.");
        break;
    case 1540:
        printf("rds.");
        break;
    case 1541:
        printf("rds2.");
        break;
    case 1542:
        printf("gridgen-elmd.");
        break;
    case 1543:
        printf("simba-cs.");
        break;
    case 1544:
        printf("aspeclmd.");
        break;
    case 1545:
        printf("vistium-share.");
        break;
    case 1546:
        printf("abbaccuray.");
        break;
    case 1547:
        printf("laplink.");
        break;
    case 1548:
        printf("Axon License Manager.");
        break;
    case 1549:
        printf("Shiva Hose.");
        break;
    case 1550:
        printf("Image Storage license manager 3M Company.");
        break;
    case 1551:
        printf("HECMTL-DB.");
        break;
    case 1552:
        printf("pciarray.");
        break;
    case 1553:
        printf("sna-cs.");
        break;
    case 1554:
        printf("CACI Products Company License Manager.");
        break;
    case 1555:
        printf("livelan.");
        break;
    case 1556:
        printf("VERITAS Private Branch Exchange.");
        break;
    case 1557:
        printf("ArborText License Manager.");
        break;
    case 1558:
        printf("xingmpeg.");
        break;
    case 1559:
        printf("web2host.");
        break;
    case 1560:
        printf("ASCI-RemoteSHADOW.");
        break;
    case 1561:
        printf("facilityview.");
        break;
    case 1562:
        printf("pconnectmgr.");
        break;
    case 1563:
        printf("Cadabra License Manager.");
        break;
    case 1564:
        printf("Pay-Per-View.");
        break;
    case 1565:
        printf("WinDD.");
        break;
    case 1566:
        printf("CORELVIDEO.");
        break;
    case 1567:
        printf("jlicelmd.");
        break;
    case 1568:
        printf("tsspmap.");
        break;
    case 1569:
        printf("ets.");
        break;
    case 1570:
        printf("orbixd.");
        break;
    case 1571:
        printf("Oracle Remote Data Base.");
        break;
    case 1572:
        printf("Chipcom License Manager.");
        break;
    case 1573:
        printf("itscomm-ns.");
        break;
    case 1574:
        printf("mvel-lm.");
        break;
    case 1575:
        printf("oraclenames.");
        break;
    case 1576:
        printf("Moldflow License Manager.");
        break;
    case 1577:
        printf("hypercube-lm.");
        break;
    case 1578:
        printf("Jacobus License Manager.");
        break;
    case 1579:
        printf("ioc-sea-lm.");
        break;
    case 1580:
        printf("tn-tl-r1.");
        break;
    case 1581:
        printf("MIL-2045-47001.");
        break;
    case 1582:
        printf("MSIMS.");
        break;
    case 1583:
        printf("simbaexpress.");
        break;
    case 1584:
        printf("tn-tl-fd2.");
        break;
    case 1585:
        printf("intv.");
        break;
    case 1586:
        printf("ibm-abtact.");
        break;
    case 1587:
        printf("pra_elmd.");
        break;
    case 1588:
        printf("triquest-lm.");
        break;
    case 1589:
        printf("VQP.");
        break;
    case 1590:
        printf("gemini-lm.");
        break;
    case 1591:
        printf("ncpm-pm.");
        break;
    case 1592:
        printf("commonspace.");
        break;
    case 1593:
        printf("mainsoft-lm.");
        break;
    case 1594:
        printf("sixtrak.");
        break;
    case 1595:
        printf("radio.");
        break;
    case 1596:
        printf("radio-sm.");
        break;
    case 1597:
        printf("orbplus-iiop.");
        break;
    case 1598:
        printf("picknfs.");
        break;
    case 1599:
        printf("simbaservices.");
        break;
    case 1600:
        printf("issd.");
        break;
    case 1601:
        printf("aas.");
        break;
    case 1602:
        printf("inspect.");
        break;
    case 1603:
        printf("pickodbc.");
        break;
    case 1604:
        printf("icabrowser.");
        break;
    case 1605:
        printf("Salutation Manager (Salutation Protocol).");
        break;
    case 1606:
        printf("Salutation Manager (SLM-API).");
        break;
    case 1607:
        printf("stt.");
        break;
    case 1608:
        printf("Smart Corp. License Manager.");
        break;
    case 1609:
        printf("isysg-lm.");
        break;
    case 1610:
        printf("taurus-wh.");
        break;
    case 1611:
        printf("Inter Library Loan.");
        break;
    case 1612:
        printf("NetBill Transaction Server.");
        break;
    case 1613:
        printf("NetBill Key Repository.");
        break;
    case 1614:
        printf("NetBill Credential Server.");
        break;
    case 1615:
        printf("NetBill Authorization Server.");
        break;
    case 1616:
        printf("NetBill Product Server.");
        break;
    case 1617:
        printf("Nimrod Inter-Agent Communication.");
        break;
    case 1618:
        printf("skytelnet.");
        break;
    case 1619:
        printf("xs-openstorage.");
        break;
    case 1620:
        printf("faxportwinport.");
        break;
    case 1621:
        printf("softdataphone.");
        break;
    case 1622:
        printf("ontime.");
        break;
    case 1623:
        printf("jaleosnd.");
        break;
    case 1624:
        printf("udp-sr-port.");
        break;
    case 1625:
        printf("svs-omagent.");
        break;
    case 1626:
        printf("Shockwave.");
        break;
    case 1627:
        printf("T.128 Gateway.");
        break;
    case 1628:
        printf("LonTalk normal.");
        break;
    case 1629:
        printf("LonTalk urgent.");
        break;
    case 1630:
        printf("Oracle Net8 Cman.");
        break;
    case 1631:
        printf("Visit view.");
        break;
    case 1632:
        printf("PAMMRATC.");
        break;
    case 1633:
        printf("PAMMRPC.");
        break;
    case 1634:
        printf("Log On America Probe.");
        break;
    case 1635:
        printf("EDB Server 1.");
        break;
    case 1636:
        printf("ISP shared public data control.");
        break;
    case 1637:
        printf("ISP shared local data control.");
        break;
    case 1638:
        printf("ISP shared management control.");
        break;
    case 1639:
        printf("cert-initiator.");
        break;
    case 1640:
        printf("cert-responder.");
        break;
    case 1641:
        printf("InVision.");
        break;
    case 1642:
        printf("isis-am.");
        break;
    case 1643:
        printf("isis-ambc.");
        break;
    case 1644:
        printf("Satellite-data Acquisition System 4.");
        break;
    case 1645:
        printf("SightLine.");
        break;
    case 1646:
        printf("sa-msg-port.");
        break;
    case 1647:
        printf("rsap.");
        break;
    case 1648:
        printf("concurrent-lm.");
        break;
    case 1649:
        printf("kermit.");
        break;
    case 1650:
        printf("nkdn.");
        break;
    case 1651:
        printf("shiva_confsrvr.");
        break;
    case 1652:
        printf("xnmp.");
        break;
    case 1653:
        printf("alphatech-lm.");
        break;
    case 1654:
        printf("stargatealerts.");
        break;
    case 1655:
        printf("dec-mbadmin.");
        break;
    case 1656:
        printf("dec-mbadmin-h.");
        break;
    case 1657:
        printf("fujitsu-mmpdc.");
        break;
    case 1658:
        printf("sixnetudr.");
        break;
    case 1659:
        printf("Silicon Grail License Manager.");
        break;
    case 1660:
        printf("skip-mc-gikreq.");
        break;
    case 1661:
        printf("netview-aix-1.");
        break;
    case 1662:
        printf("netview-aix-2.");
        break;
    case 1663:
        printf("netview-aix-3.");
        break;
    case 1664:
        printf("netview-aix-4.");
        break;
    case 1665:
        printf("netview-aix-5.");
        break;
    case 1666:
        printf("netview-aix-6.");
        break;
    case 1667:
        printf("netview-aix-7.");
        break;
    case 1668:
        printf("netview-aix-8.");
        break;
    case 1669:
        printf("netview-aix-9.");
        break;
    case 1670:
        printf("netview-aix-10.");
        break;
    case 1671:
        printf("netview-aix-11.");
        break;
    case 1672:
        printf("netview-aix-12.");
        break;
    case 1673:
        printf("Intel Proshare Multicast.");
        break;
    case 1674:
        printf("Intel Proshare Multicast.");
        break;
    case 1675:
        printf("Pacific Data Products.");
        break;
    case 1676:
        printf("netcomm1.");
        break;
    case 1677:
        printf("groupwise.");
        break;
    case 1678:
        printf("prolink.");
        break;
    case 1679:
        printf("darcorp-lm.");
        break;
    case 1680:
        printf("microcom-sbp.");
        break;
    case 1681:
        printf("sd-elmd.");
        break;
    case 1682:
        printf("lanyon-lantern.");
        break;
    case 1683:
        printf("ncpm-hip.");
        break;
    case 1684:
        printf("SnareSecure.");
        break;
    case 1685:
        printf("n2nremote.");
        break;
    case 1686:
        printf("cvmon.");
        break;
    case 1687:
        printf("nsjtp-ctrl.");
        break;
    case 1688:
        printf("nsjtp-data.");
        break;
    case 1689:
        printf("firefox.");
        break;
    case 1690:
        printf("ng-umds.");
        break;
    case 1691:
        printf("empire-empuma.");
        break;
    case 1692:
        printf("sstsys-lm.");
        break;
    case 1693:
        printf("rrirtr.");
        break;
    case 1694:
        printf("rrimwm.");
        break;
    case 1695:
        printf("rrilwm.");
        break;
    case 1696:
        printf("rrifmm.");
        break;
    case 1697:
        printf("rrisat.");
        break;
    case 1698:
        printf("RSVP-ENCAPSULATION-1.");
        break;
    case 1699:
        printf("RSVP-ENCAPSULATION-2.");
        break;
    case 1700:
        printf("mps-raft.");
        break;
    case 1701:
        printf("l2f/l2tp.");
        break;
    case 1702:
        printf("deskshare.");
        break;
    case 1703:
        printf("hb-engine.");
        break;
    case 1704:
        printf("bcs-broker.");
        break;
    case 1705:
        printf("slingshot.");
        break;
    case 1706:
        printf("jetform.");
        break;
    case 1707:
        printf("vdmplay.");
        break;
    case 1708:
        printf("gat-lmd.");
        break;
    case 1709:
        printf("centra.");
        break;
    case 1710:
        printf("impera.");
        break;
    case 1711:
        printf("pptconference.");
        break;
    case 1712:
        printf("resource monitoring service.");
        break;
    case 1713:
        printf("ConferenceTalk.");
        break;
    case 1714:
        printf("sesi-lm.");
        break;
    case 1715:
        printf("houdini-lm.");
        break;
    case 1716:
        printf("xmsg.");
        break;
    case 1717:
        printf("fj-hdnet.");
        break;
    case 1718:
        printf("H.323 Multicast Gatekeeper Discover.");
        break;
    case 1719:
        printf("H.323 Unicast Gatekeeper Signaling.");
        break;
    case 1720:
        printf("H.323 Call Control Signalling.");
        break;
    case 1721:
        printf("caicci.");
        break;
    case 1722:
        printf("HKS License Manager.");
        break;
    case 1723:
        printf("pptp.");
        break;
    case 1724:
        printf("csbphonemaster.");
        break;
    case 1725:
        printf("iden-ralp.");
        break;
    case 1726:
        printf("IBERIAGAMES.");
        break;
    case 1727:
        printf("winddx.");
        break;
    case 1728:
        printf("TELINDUS.");
        break;
    case 1729:
        printf("CityNL License Management.");
        break;
    case 1730:
        printf("roketz.");
        break;
    case 1731:
        printf("MSICCP.");
        break;
    case 1732:
        printf("proxim.");
        break;
    case 1733:
        printf("SIMS - SIIPAT Protocol for Alarm Transmission.");
        break;
    case 1734:
        printf("Camber Corporation License Management.");
        break;
    case 1735:
        printf("PrivateChat.");
        break;
    case 1736:
        printf("street-stream.");
        break;
    case 1737:
        printf("ultimad.");
        break;
    case 1738:
        printf("GameGen1.");
        break;
    case 1739:
        printf("webaccess.");
        break;
    case 1740:
        printf("encore.");
        break;
    case 1741:
        printf("cisco-net-mgmt.");
        break;
    case 1742:
        printf("3Com-nsd.");
        break;
    case 1743:
        printf("Cinema Graphics License Manager.");
        break;
    case 1744:
        printf("ncpm-ft.");
        break;
    case 1745:
        printf("remote-winsock.");
        break;
    case 1746:
        printf("ftrapid-1.");
        break;
    case 1747:
        printf("ftrapid-2.");
        break;
    case 1748:
        printf("oracle-em1.");
        break;
    case 1749:
        printf("aspen-services.");
        break;
    case 1750:
        printf("Simple Socket Library's PortMaster.");
        break;
    case 1751:
        printf("SwiftNet.");
        break;
    case 1752:
        printf("Leap of Faith Research License Manager.");
        break;
    case 1753:
        printf("Predatar Comms Service.");
        break;
    case 1754:
        printf("oracle-em2.");
        break;
    case 1755:
        printf("ms-streaming.");
        break;
    case 1756:
        printf("capfast-lmd.");
        break;
    case 1757:
        printf("cnhrp.");
        break;
    case 1758:
        printf("tftp-mcast.");
        break;
    case 1759:
        printf("SPSS License Manager.");
        break;
    case 1760:
        printf("www-ldap-gw.");
        break;
    case 1761:
        printf("cft-0.");
        break;
    case 1762:
        printf("cft-1.");
        break;
    case 1763:
        printf("cft-2.");
        break;
    case 1764:
        printf("cft-3.");
        break;
    case 1765:
        printf("cft-4.");
        break;
    case 1766:
        printf("cft-5.");
        break;
    case 1767:
        printf("cft-6.");
        break;
    case 1768:
        printf("cft-7.");
        break;
    case 1769:
        printf("bmc-net-adm.");
        break;
    case 1770:
        printf("bmc-net-svc.");
        break;
    case 1771:
        printf("vaultbase.");
        break;
    case 1772:
        printf("EssWeb Gateway.");
        break;
    case 1773:
        printf("KMSControl.");
        break;
    case 1774:
        printf("global-dtserv.");
        break;
    case 1775:
        printf("data interchange between visual processing containers.");
        break;
    case 1776:
        printf("Federal Emergency Management Information System.");
        break;
    case 1777:
        printf("powerguardian.");
        break;
    case 1778:
        printf("prodigy-internet.");
        break;
    case 1779:
        printf("pharmasoft.");
        break;
    case 1780:
        printf("dpkeyserv.");
        break;
    case 1781:
        printf("answersoft-lm.");
        break;
    case 1782:
        printf("hp-hcip.");
        break;
    case 1784:
        printf("Finle License Manager.");
        break;
    case 1785:
        printf("Wind River Systems License Manager.");
        break;
    case 1786:
        printf("funk-logger.");
        break;
    case 1787:
        printf("funk-license.");
        break;
    case 1788:
        printf("psmond.");
        break;
    case 1789:
        printf("hello.");
        break;
    case 1790:
        printf("Narrative Media Streaming Protocol.");
        break;
    case 1791:
        printf("EA1.");
        break;
    case 1792:
        printf("ibm-dt-2.");
        break;
    case 1793:
        printf("rsc-robot.");
        break;
    case 1794:
        printf("cera-bcm.");
        break;
    case 1795:
        printf("dpi-proxy.");
        break;
    case 1796:
        printf("Vocaltec Server Administration.");
        break;
    case 1797:
        printf("UMA.");
        break;
    case 1798:
        printf("Event Transfer Protocol.");
        break;
    case 1799:
        printf("NETRISK.");
        break;
    case 1800:
        printf("ANSYS-License manager.");
        break;
    case 1801:
        printf("Microsoft Message Que.");
        break;
    case 1802:
        printf("ConComp1.");
        break;
    case 1803:
        printf("HP-HCIP-GWY.");
        break;
    case 1804:
        printf("ENL.");
        break;
    case 1805:
        printf("ENL-Name.");
        break;
    case 1806:
        printf("Musiconline.");
        break;
    case 1807:
        printf("Fujitsu Hot Standby Protocol.");
        break;
    case 1808:
        printf("Oracle-VP2.");
        break;
    case 1809:
        printf("Oracle-VP1.");
        break;
    case 1810:
        printf("Jerand License Manager.");
        break;
    case 1811:
        printf("Scientia-SDB.");
        break;
    case 1812:
        printf("RADIUS.");
        break;
    case 1813:
        printf("RADIUS Accounting.");
        break;
    case 1814:
        printf("TDP Suite.");
        break;
    case 1815:
        printf("MMPFT.");
        break;
    case 1816:
        printf("HARP.");
        break;
    case 1817:
        printf("RKB-OSCS.");
        break;
    case 1818:
        printf("Enhanced Trivial File Transfer Protocol.");
        break;
    case 1819:
        printf("Plato License Manager.");
        break;
    case 1820:
        printf("mcagent.");
        break;
    case 1821:
        printf("donnyworld.");
        break;
    case 1822:
        printf("es-elmd.");
        break;
    case 1823:
        printf("Unisys Natural Language License Manager.");
        break;
    case 1824:
        printf("metrics-pas.");
        break;
    case 1825:
        printf("DirecPC Video.");
        break;
    case 1826:
        printf("ARDT.");
        break;
    case 1827:
        printf("ASI.");
        break;
    case 1828:
        printf("itm-mcell-u.");
        break;
    case 1829:
        printf("Optika eMedia.");
        break;
    case 1830:
        printf("Oracle Net8 CMan Admin.");
        break;
    case 1831:
        printf("Myrtle.");
        break;
    case 1832:
        printf("ThoughtTreasure.");
        break;
    case 1833:
        printf("udpradio.");
        break;
    case 1834:
        printf("ARDUS Unicast.");
        break;
    case 1835:
        printf("ARDUS Multicast.");
        break;
    case 1836:
        printf("ste-smsc.");
        break;
    case 1837:
        printf("csoft1.");
        break;
    case 1838:
        printf("TALNET.");
        break;
    case 1839:
        printf("netopia-vo1.");
        break;
    case 1840:
        printf("netopia-vo2.");
        break;
    case 1841:
        printf("netopia-vo3.");
        break;
    case 1842:
        printf("netopia-vo4.");
        break;
    case 1843:
        printf("netopia-vo5.");
        break;
    case 1844:
        printf("DirecPC-DLL.");
        break;
    case 1845:
        printf("altalink.");
        break;
    case 1846:
        printf("Tunstall PNC.");
        break;
    case 1847:
        printf("SLP Notification.");
        break;
    case 1848:
        printf("fjdocdist.");
        break;
    case 1849:
        printf("ALPHA-SMS.");
        break;
    case 1850:
        printf("GSI.");
        break;
    case 1851:
        printf("ctcd.");
        break;
    case 1852:
        printf("Virtual Time.");
        break;
    case 1853:
        printf("VIDS-AVTP.");
        break;
    case 1854:
        printf("Buddy Draw.");
        break;
    case 1855:
        printf("Fiorano RtrSvc.");
        break;
    case 1856:
        printf("Fiorano MsgSvc.");
        break;
    case 1857:
        printf("DataCaptor.");
        break;
    case 1858:
        printf("PrivateArk.");
        break;
    case 1859:
        printf("Gamma Fetcher Server.");
        break;
    case 1860:
        printf("SunSCALAR Services.");
        break;
    case 1861:
        printf("LeCroy VICP.");
        break;
    case 1862:
        printf("MySQL Cluster Manager Agent.");
        break;
    case 1863:
        printf("MSNP.");
        break;
    case 1864:
        printf("Paradym 31 Port.");
        break;
    case 1865:
        printf("ENTP.");
        break;
    case 1866:
        printf("swrmi.");
        break;
    case 1867:
        printf("UDRIVE.");
        break;
    case 1868:
        printf("VizibleBrowser.");
        break;
    case 1869:
        printf("TransAct.");
        break;
    case 1870:
        printf("SunSCALAR DNS Service.");
        break;
    case 1871:
        printf("Cano Central 0.");
        break;
    case 1872:
        printf("Cano Central 1.");
        break;
    case 1873:
        printf("Fjmpjps.");
        break;
    case 1874:
        printf("Fjswapsnp.");
        break;
    case 1875:
        printf("westell stats.");
        break;
    case 1876:
        printf("ewcappsrv.");
        break;
    case 1877:
        printf("hp-webqosdb.");
        break;
    case 1878:
        printf("drmsmc.");
        break;
    case 1879:
        printf("NettGain NMS.");
        break;
    case 1880:
        printf("Gilat VSAT Control.");
        break;
    case 1881:
        printf("IBM WebSphere MQ Everyplace.");
        break;
    case 1882:
        printf("CA eTrust Common Services.");
        break;
    case 1883:
        printf("Message Queuing Telemetry Transport Protocol.");
        break;
    case 1884:
        printf("Internet Distance Map Svc.");
        break;
    case 1885:
        printf("Veritas Trap Server.");
        break;
    case 1886:
        printf("Leonardo over IP.");
        break;
    case 1887:
        printf("FileX Listening Port.");
        break;
    case 1888:
        printf("NC Config Port.");
        break;
    case 1889:
        printf("Unify Web Adapter Service.");
        break;
    case 1890:
        printf("wilkenListener.");
        break;
    case 1891:
        printf("ChildKey Notification.");
        break;
    case 1892:
        printf("ChildKey Control.");
        break;
    case 1893:
        printf("ELAD Protocol.");
        break;
    case 1894:
        printf("O2Server Port.");
        break;
    case 1896:
        printf("b-novative license server.");
        break;
    case 1897:
        printf("MetaAgent.");
        break;
    case 1898:
        printf("Cymtec secure management.");
        break;
    case 1899:
        printf("MC2Studios.");
        break;
    case 1900:
        printf("SSDP.");
        break;
    case 1901:
        printf("Fujitsu ICL Terminal Emulator Program A.");
        break;
    case 1902:
        printf("Fujitsu ICL Terminal Emulator Program B.");
        break;
    case 1903:
        printf("Local Link Name Resolution.");
        break;
    case 1904:
        printf("Fujitsu ICL Terminal Emulator Program C.");
        break;
    case 1905:
        printf("Secure UP.Link Gateway Protocol.");
        break;
    case 1906:
        printf("TPortMapperReq.");
        break;
    case 1907:
        printf("IntraSTAR.");
        break;
    case 1908:
        printf("Dawn.");
        break;
    case 1909:
        printf("Global World Link.");
        break;
    case 1910:
        printf("UltraBac Software communications port.");
        break;
    case 1911:
        printf("Starlight Networks Multimedia Transport Protocol.");
        break;
    case 1912:
        printf("rhp-iibp.");
        break;
    case 1913:
        printf("armadp.");
        break;
    case 1914:
        printf("Elm-Momentum.");
        break;
    case 1915:
        printf("FACELINK.");
        break;
    case 1916:
        printf("Persoft Persona.");
        break;
    case 1917:
        printf("nOAgent.");
        break;
    case 1918:
        printf("IBM Tivole Directory Service - NDS.");
        break;
    case 1919:
        printf("IBM Tivoli Directory Service - DCH.");
        break;
    case 1920:
        printf("IBM Tivoli Directory Service - FERRET.");
        break;
    case 1921:
        printf("NoAdmin.");
        break;
    case 1922:
        printf("Tapestry.");
        break;
    case 1923:
        printf("SPICE.");
        break;
    case 1924:
        printf("XIIP.");
        break;
    case 1925:
        printf("Surrogate Discovery Port.");
        break;
    case 1926:
        printf("Evolution Game Server.");
        break;
    case 1927:
        printf("Videte CIPC Port.");
        break;
    case 1928:
        printf("Expnd Maui Srvr Dscovr.");
        break;
    case 1929:
        printf("Bandwiz System - Server.");
        break;
    case 1930:
        printf("Drive AppServer.");
        break;
    case 1931:
        printf("AMD SCHED.");
        break;
    case 1932:
        printf("CTT Broker.");
        break;
    case 1933:
        printf("IBM LM MT Agent.");
        break;
    case 1934:
        printf("IBM LM Appl Agent.");
        break;
    case 1935:
        printf("Macromedia Flash Communications Server MX.");
        break;
    case 1936:
        printf("JetCmeServer Server Port.");
        break;
    case 1937:
        printf("JetVWay Server Port.");
        break;
    case 1938:
        printf("JetVWay Client Port.");
        break;
    case 1939:
        printf("JetVision Server Port.");
        break;
    case 1940:
        printf("JetVision Client Port.");
        break;
    case 1941:
        printf("DIC-Aida.");
        break;
    case 1942:
        printf("Real Enterprise Service.");
        break;
    case 1943:
        printf("Beeyond Media.");
        break;
    case 1944:
        printf("close-combat.");
        break;
    case 1945:
        printf("dialogic-elmd.");
        break;
    case 1946:
        printf("tekpls.");
        break;
    case 1947:
        printf("SentinelSRM.");
        break;
    case 1948:
        printf("eye2eye.");
        break;
    case 1949:
        printf("ISMA Easdaq Live.");
        break;
    case 1950:
        printf("ISMA Easdaq Test.");
        break;
    case 1951:
        printf("bcs-lmserver.");
        break;
    case 1952:
        printf("mpnjsc.");
        break;
    case 1953:
        printf("Rapid Base.");
        break;
    case 1954:
        printf("ABR-API (diskbridge).");
        break;
    case 1955:
        printf("ABR-Secure Data (diskbridge).");
        break;
    case 1956:
        printf("Vertel VMF DS.");
        break;
    case 1957:
        printf("unix-status.");
        break;
    case 1958:
        printf("CA Administration Daemon.");
        break;
    case 1959:
        printf("SIMP Channel.");
        break;
    case 1960:
        printf("Merit DAC NASmanager.");
        break;
    case 1961:
        printf("BTS APPSERVER.");
        break;
    case 1962:
        printf("BIAP-MP.");
        break;
    case 1963:
        printf("WebMachine.");
        break;
    case 1964:
        printf("SOLID E ENGINE.");
        break;
    case 1965:
        printf("Tivoli NPM.");
        break;
    case 1966:
        printf("Slush.");
        break;
    case 1967:
        printf("SNS Quote.");
        break;
    case 1968:
        printf("LIPSinc.");
        break;
    case 1969:
        printf("LIPSinc 1.");
        break;
    case 1970:
        printf("NetOp Remote Control.");
        break;
    case 1971:
        printf("NetOp School.");
        break;
    case 1972:
        printf("Cache.");
        break;
    case 1973:
        printf("Data Link Switching Remote Access Protocol.");
        break;
    case 1974:
        printf("DRP.");
        break;
    case 1975:
        printf("TCO Flash Agent.");
        break;
    case 1976:
        printf("TCO Reg Agent.");
        break;
    case 1977:
        printf("TCO Address Book.");
        break;
    case 1978:
        printf("UniSQL.");
        break;
    case 1979:
        printf("UniSQL Java.");
        break;
    case 1980:
        printf("PearlDoc XACT.");
        break;
    case 1981:
        printf("p2pQ.");
        break;
    case 1982:
        printf("Evidentiary Timestamp.");
        break;
    case 1983:
        printf("Loophole Test Protocol.");
        break;
    case 1984:
        printf("BB.");
        break;
    case 1985:
        printf("Hot Standby Router Protocol.");
        break;
    case 1986:
        printf("cisco license management.");
        break;
    case 1987:
        printf("cisco RSRB Priority 1 port.");
        break;
    case 1988:
        printf("cisco RSRB Priority 2 port.");
        break;
    case 1989:
        printf("cisco RSRB Priority 3 port/MHSnet system.");
        break;
    case 1990:
        printf("cisco STUN Priority 1 port.");
        break;
    case 1991:
        printf("cisco STUN Priority 2 port.");
        break;
    case 1992:
        printf("cisco STUN Priority 3 port.");
        break;
    case 1993:
        printf("cisco SNMP TCP port.");
        break;
    case 1994:
        printf("cisco serial tunnel port.");
        break;
    case 1995:
        printf("cisco perf port.");
        break;
    case 1996:
        printf("cisco Remote SRB port.");
        break;
    case 1997:
        printf("cisco Gateway Discovery Protocol.");
        break;
    case 1998:
        printf("cisco X.25 service (XOT).");
        break;
    case 1999:
        printf("cisco identification port.");
        break;
    case 2000:
        printf("Cisco SCCP.");
        break;
    case 2003:
        printf("Brutus Server.");
        break;
    case 2011:
        printf("raid.");
        break;
    case 2029:
        printf("Hot Standby Router Protocol IPv6.");
        break;
    case 2031:
        printf("mobrien-chat.");
        break;
    case 2036:
        printf("Ethernet WS DP network.");
        break;
    case 2037:
        printf("APplus Application Server.");
        break;
    case 2039:
        printf("Prizma Monitoring Service.");
        break;
    case 2042:
        printf("isis.");
        break;
    case 2043:
        printf("isis-bcast.");
        break;
    case 2049:
        printf("Network File System - Sun Microsystems.");
        break;
    case 2050:
        printf("Avaya EMB Config Port.");
        break;
    case 2051:
        printf("EPNSDP.");
        break;
    case 2052:
        printf("clearVisn Services Port.");
        break;
    case 2053:
        printf("Lot105 DSuper Updates.");
        break;
    case 2054:
        printf("Weblogin Port.");
        break;
    case 2055:
        printf("Iliad-Odyssey Protocol.");
        break;
    case 2056:
        printf("OmniSky Port.");
        break;
    case 2057:
        printf("Rich Content Protocol.");
        break;
    case 2058:
        printf("NewWaveSearchables RMI.");
        break;
    case 2059:
        printf("BMC Messaging Service.");
        break;
    case 2060:
        printf("Telenium Daemon IF.");
        break;
    case 2061:
        printf("NetMount.");
        break;
    case 2062:
        printf("ICG SWP Port.");
        break;
    case 2063:
        printf("ICG Bridge Port.");
        break;
    case 2064:
        printf("ICG IP Relay Port.");
        break;
    case 2065:
        printf("Data Link Switch Read Port Number.");
        break;
    case 2066:
        printf("AVM USB Remote Architecture.");
        break;
    case 2067:
        printf("Data Link Switch Write Port Number.");
        break;
    case 2068:
        printf("Avocent AuthSrv Protocol.");
        break;
    case 2069:
        printf("HTTP Event Port.");
        break;
    case 2070:
        printf("AH and ESP Encapsulated in UDP packet.");
        break;
    case 2071:
        printf("Axon Control Protocol.");
        break;
    case 2072:
        printf("GlobeCast mSync.");
        break;
    case 2073:
        printf("DataReel Database Socket.");
        break;
    case 2074:
        printf("Vertel VMF SA.");
        break;
    case 2075:
        printf("Newlix ServerWare Engine.");
        break;
    case 2076:
        printf("Newlix JSPConfig.");
        break;
    case 2077:
        printf("Old Tivoli Storage Manager.");
        break;
    case 2078:
        printf("IBM Total Productivity Center Server.");
        break;
    case 2079:
        printf("IDWARE Router Port.");
        break;
    case 2080:
        printf("Autodesk NLM (FLEXlm).");
        break;
    case 2081:
        printf("KME PRINTER TRAP PORT.");
        break;
    case 2082:
        printf("Infowave Mobility Server.");
        break;
    case 2083:
        printf("Secure Radius Service.");
        break;
    case 2084:
        printf("SunCluster Geographic.");
        break;
    case 2085:
        printf("ADA Control.");
        break;
    case 2086:
        printf("GNUnet.");
        break;
    case 2087:
        printf("ELI - Event Logging Integration.");
        break;
    case 2088:
        printf("IP Busy Lamp Field.");
        break;
    case 2089:
        printf("Security Encapsulation Protocol - SEP.");
        break;
    case 2090:
        printf("Load Report Protocol.");
        break;
    case 2091:
        printf("PRP.");
        break;
    case 2092:
        printf("Descent 3.");
        break;
    case 2093:
        printf("NBX CC.");
        break;
    case 2094:
        printf("NBX AU.");
        break;
    case 2095:
        printf("NBX SER.");
        break;
    case 2096:
        printf("NBX DIR.");
        break;
    case 2097:
        printf("Jet Form Preview.");
        break;
    case 2098:
        printf("Dialog Port.");
        break;
    case 2099:
        printf("H.225.0 Annex G Signalling.");
        break;
    case 2100:
        printf("Amiga Network Filesystem.");
        break;
    case 2101:
        printf("rtcm-sc104.");
        break;
    case 2102:
        printf("Zephyr server.");
        break;
    case 2103:
        printf("Zephyr serv-hm connection.");
        break;
    case 2104:
        printf("Zephyr hostmanager.");
        break;
    case 2105:
        printf("MiniPay.");
        break;
    case 2106:
        printf("MZAP.");
        break;
    case 2107:
        printf("BinTec Admin.");
        break;
    case 2108:
        printf("Comcam.");
        break;
    case 2109:
        printf("Ergolight.");
        break;
    case 2110:
        printf("UMSP.");
        break;
    case 2111:
        printf("OPNET Dynamic Sampling Agent Transaction Protocol.");
        break;
    case 2112:
        printf("Idonix MetaNet.");
        break;
    case 2113:
        printf("HSL StoRM.");
        break;
    case 2114:
        printf("Classical Music Meta-Data Access and Enhancement.");
        break;
    case 2115:
        printf("Key Distribution Manager.");
        break;
    case 2116:
        printf("CCOWCMR.");
        break;
    case 2117:
        printf("MENTACLIENT.");
        break;
    case 2118:
        printf("MENTASERVER.");
        break;
    case 2119:
        printf("GSIGATEKEEPER.");
        break;
    case 2120:
        printf("Quick Eagle Networks CP.");
        break;
    case 2121:
        printf("SCIENTIA-SSDB.");
        break;
    case 2122:
        printf("CauPC Remote Control.");
        break;
    case 2123:
        printf("GTP-Control Plane (3GPP).");
        break;
    case 2124:
        printf("ELATELINK.");
        break;
    case 2125:
        printf("LOCKSTEP.");
        break;
    case 2126:
        printf("PktCable-COPS.");
        break;
    case 2127:
        printf("INDEX-PC-WB.");
        break;
    case 2128:
        printf("Net Steward Control.");
        break;
    case 2129:
        printf("cs-live.com.");
        break;
    case 2130:
        printf("XDS.");
        break;
    case 2131:
        printf("Avantageb2b.");
        break;
    case 2132:
        printf("SoleraTec End Point Map.");
        break;
    case 2133:
        printf("ZYMED-ZPP.");
        break;
    case 2134:
        printf("AVENUE.");
        break;
    case 2135:
        printf("Grid Resource Information Server.");
        break;
    case 2136:
        printf("APPWORXSRV.");
        break;
    case 2137:
        printf("CONNECT.");
        break;
    case 2138:
        printf("UNBIND-CLUSTER.");
        break;
    case 2139:
        printf("IAS-AUTH.");
        break;
    case 2140:
        printf("IAS-REG.");
        break;
    case 2141:
        printf("IAS-ADMIND.");
        break;
    case 2142:
        printf("TDM OVER IP.");
        break;
    case 2143:
        printf("Live Vault Job Control.");
        break;
    case 2144:
        printf("Live Vault Fast Object Transfer.");
        break;
    case 2145:
        printf("Live Vault Remote Diagnostic Console Support.");
        break;
    case 2146:
        printf("Live Vault Admin Event Notification.");
        break;
    case 2147:
        printf("Live Vault Authentication.");
        break;
    case 2148:
        printf("VERITAS UNIVERSAL COMMUNICATION LAYER.");
        break;
    case 2149:
        printf("ACPTSYS.");
        break;
    case 2150:
        printf("DYNAMIC3D.");
        break;
    case 2151:
        printf("DOCENT.");
        break;
    case 2152:
        printf("GTP-User Plane (3GPP).");
        break;
    case 2153:
        printf("Control Protocol.");
        break;
    case 2154:
        printf("Standard Protocol.");
        break;
    case 2155:
        printf("Bridge Protocol.");
        break;
    case 2156:
        printf("Talari Reliable Protocol.");
        break;
    case 2157:
        printf("Xerox Network Document Scan Protocol.");
        break;
    case 2158:
        printf("TouchNetPlus Service.");
        break;
    case 2159:
        printf("GDB Remote Debug Port.");
        break;
    case 2160:
        printf("APC 2160.");
        break;
    case 2161:
        printf("APC 2161.");
        break;
    case 2162:
        printf("Navisphere.");
        break;
    case 2163:
        printf("Navisphere Secure.");
        break;
    case 2164:
        printf("Dynamic DNS Version 3.");
        break;
    case 2165:
        printf("X-Bone API.");
        break;
    case 2166:
        printf("iwserver.");
        break;
    case 2167:
        printf("Raw Async Serial Link.");
        break;
    case 2168:
        printf("easy-soft Multiplexer.");
        break;
    case 2169:
        printf("Backbone for Academic Information Notification (BRAIN).");
        break;
    case 2170:
        printf("EyeTV Server Port.");
        break;
    case 2171:
        printf("MS Firewall Storage.");
        break;
    case 2172:
        printf("MS Firewall SecureStorage.");
        break;
    case 2173:
        printf("MS Firewall Replication.");
        break;
    case 2174:
        printf("MS Firewall Intra Array.");
        break;
    case 2175:
        printf("Microsoft Desktop AirSync Protocol.");
        break;
    case 2176:
        printf("Microsoft ActiveSync Remote API.");
        break;
    case 2177:
        printf("qWAVE Bandwidth Estimate.");
        break;
    case 2178:
        printf("Peer Services for BITS.");
        break;
    case 2179:
        printf("Microsoft RDP for virtual machines.");
        break;
    case 2180:
        printf("Millicent Vendor Gateway Server.");
        break;
    case 2181:
        printf("eforward.");
        break;
    case 2182:
        printf("CGN status.");
        break;
    case 2183:
        printf("Code Green configuration.");
        break;
    case 2184:
        printf("NVD User.");
        break;
    case 2185:
        printf("OnBase Distributed Disk Services.");
        break;
    case 2186:
        printf("Guy-Tek Automated Update Applications.");
        break;
    case 2187:
        printf("Sepehr System Management Control.");
        break;
    case 2188:
        printf("Radware Resource Pool Manager.");
        break;
    case 2189:
        printf("Secure Radware Resource Pool Manager.");
        break;
    case 2190:
        printf("TiVoConnect Beacon.");
        break;
    case 2191:
        printf("TvBus Messaging.");
        break;
    case 2192:
        printf("ASDIS software management.");
        break;
    case 2193:
        printf("Dr.Web Enterprise Management Service.");
        break;
    case 2197:
        printf("MNP data exchange.");
        break;
    case 2198:
        printf("OneHome Remote Access.");
        break;
    case 2199:
        printf("OneHome Service Port.");
        break;
    case 2200:
        printf("ICI.");
        break;
    case 2201:
        printf("Advanced Training System Program.");
        break;
    case 2202:
        printf("Int. Multimedia Teleconferencing Cosortium.");
        break;
    case 2203:
        printf("b2 Runtime Protocol.");
        break;
    case 2204:
        printf("b2 License Server.");
        break;
    case 2205:
        printf("Java Presentation Server.");
        break;
    case 2206:
        printf("HP OpenCall bus.");
        break;
    case 2207:
        printf("HP Status and Services.");
        break;
    case 2208:
        printf("HP I/O Backend.");
        break;
    case 2209:
        printf("HP RIM for Files Portal Service.");
        break;
    case 2210:
        printf("NOAAPORT Broadcast Network.");
        break;
    case 2211:
        printf("EMWIN.");
        break;
    case 2212:
        printf("LeeCO POS Server Service.");
        break;
    case 2213:
        printf("Kali.");
        break;
    case 2214:
        printf("RDQ Protocol Interface.");
        break;
    case 2215:
        printf("IPCore.co.za GPRS.");
        break;
    case 2216:
        printf("VTU data service.");
        break;
    case 2217:
        printf("GoToDevice Device Management.");
        break;
    case 2218:
        printf("Bounzza IRC Proxy.");
        break;
    case 2219:
        printf("NetIQ NCAP Protocol.");
        break;
    case 2220:
        printf("NetIQ End2End.");
        break;
    case 2221:
        printf("EtherNet/IP over TLS.");
        break;
    case 2222:
        printf("EtherNet/IP I/O.");
        break;
    case 2223:
        printf("Rockwell CSP2.");
        break;
    case 2224:
        printf("Easy Flexible Internet/Multiplayer Games.");
        break;
    case 2225:
        printf("Resource Connection Initiation Protocol.");
        break;
    case 2226:
        printf("Digital Instinct DRM.");
        break;
    case 2227:
        printf("DI Messaging Service.");
        break;
    case 2228:
        printf("eHome Message Server.");
        break;
    case 2229:
        printf("DataLens Service.");
        break;
    case 2230:
        printf("MetaSoft Job Queue Administration Service.");
        break;
    case 2231:
        printf("WiMAX ASN Control Plane Protocol.");
        break;
    case 2232:
        printf("IVS Video default.");
        break;
    case 2233:
        printf("INFOCRYPT.");
        break;
    case 2234:
        printf("DirectPlay.");
        break;
    case 2235:
        printf("Sercomm-WLink.");
        break;
    case 2236:
        printf("Nani.");
        break;
    case 2237:
        printf("Optech Port1 License Manager.");
        break;
    case 2238:
        printf("AVIVA SNA SERVER.");
        break;
    case 2239:
        printf("Image Query.");
        break;
    case 2240:
        printf("RECIPe.");
        break;
    case 2241:
        printf("IVS Daemon.");
        break;
    case 2242:
        printf("Folio Remote Server.");
        break;
    case 2243:
        printf("Magicom Protocol.");
        break;
    case 2244:
        printf("NMS Server.");
        break;
    case 2245:
        printf("HaO.");
        break;
    case 2246:
        printf("PacketCable MTA Addr Map.");
        break;
    case 2247:
        printf("Antidote Deployment Manager Service.");
        break;
    case 2248:
        printf("User Management Service.");
        break;
    case 2249:
        printf("RISO File Manager Protocol.");
        break;
    case 2250:
        printf("remote-collab.");
        break;
    case 2251:
        printf("Distributed Framework Port.");
        break;
    case 2252:
        printf("NJENET using SSL.");
        break;
    case 2253:
        printf("DTV Channel Request.");
        break;
    case 2254:
        printf("Seismic P.O.C. Port.");
        break;
    case 2255:
        printf("VRTP - ViRtue Transfer Protocol.");
        break;
    case 2256:
        printf("PCC MFP.");
        break;
    case 2257:
        printf("simple text/file transfer.");
        break;
    case 2258:
        printf("Rotorcraft Communications Test System.");
        break;
    case 2260:
        printf("APC 2260.");
        break;
    case 2261:
        printf("CoMotion Master Server.");
        break;
    case 2262:
        printf("CoMotion Backup Server.");
        break;
    case 2263:
        printf("ECweb Configuration Service.");
        break;
    case 2264:
        printf("Audio Precision Apx500 API Port 1.");
        break;
    case 2265:
        printf("Audio Precision Apx500 API Port 2.");
        break;
    case 2266:
        printf("M-Files Server.");
        break;
    case 2267:
        printf("OntoBroker.");
        break;
    case 2268:
        printf("AMT.");
        break;
    case 2269:
        printf("MIKEY.");
        break;
    case 2270:
        printf("starSchool.");
        break;
    case 2271:
        printf("Secure Meeting Maker Scheduling.");
        break;
    case 2272:
        printf("Meeting Maker Scheduling.");
        break;
    case 2273:
        printf("MySQL Instance Manager.");
        break;
    case 2274:
        printf("PCTTunneller.");
        break;
    case 2275:
        printf("iBridge Conferencing.");
        break;
    case 2276:
        printf("iBridge Management.");
        break;
    case 2277:
        printf("Bt device control proxy.");
        break;
    case 2278:
        printf("Simple Stacked Sequences Database.");
        break;
    case 2279:
        printf("xmquery.");
        break;
    case 2280:
        printf("LNVPOLLER.");
        break;
    case 2281:
        printf("LNVCONSOLE.");
        break;
    case 2282:
        printf("LNVALARM.");
        break;
    case 2283:
        printf("LNVSTATUS.");
        break;
    case 2284:
        printf("LNVMAPS.");
        break;
    case 2285:
        printf("LNVMAILMON.");
        break;
    case 2286:
        printf("NAS-Metering.");
        break;
    case 2287:
        printf("DNA.");
        break;
    case 2288:
        printf("NETML.");
        break;
    case 2289:
        printf("Lookup dict server.");
        break;
    case 2290:
        printf("Sonus Logging Services.");
        break;
    case 2291:
        printf("EPSON Advanced Printer Share Protocol.");
        break;
    case 2292:
        printf("Sonus Element Management Services.");
        break;
    case 2293:
        printf("Network Platform Debug Manager.");
        break;
    case 2294:
        printf("Konshus License Manager (FLEX).");
        break;
    case 2295:
        printf("Advant License Manager.");
        break;
    case 2296:
        printf("Theta License Manager (Rainbow).");
        break;
    case 2297:
        printf("D2K DataMover 1.");
        break;
    case 2298:
        printf("D2K DataMover 2.");
        break;
    case 2299:
        printf("PC Telecommute.");
        break;
    case 2300:
        printf("CVMMON.");
        break;
    case 2301:
        printf("Compaq HTTP.");
        break;
    case 2302:
        printf("Bindery Support.");
        break;
    case 2303:
        printf("Proxy Gateway.");
        break;
    case 2304:
        printf("Attachmate UTS.");
        break;
    case 2305:
        printf("MT ScaleServer.");
        break;
    case 2306:
        printf("TAPPI BoxNet.");
        break;
    case 2307:
        printf("pehelp.");
        break;
    case 2308:
        printf("sdhelp.");
        break;
    case 2309:
        printf("SD Server.");
        break;
    case 2310:
        printf("SD Client.");
        break;
    case 2311:
        printf("Message Service.");
        break;
    case 2312:
        printf("WANScaler Communication Service.");
        break;
    case 2313:
        printf("IAPP (Inter Access Point Protocol).");
        break;
    case 2314:
        printf("CR WebSystems.");
        break;
    case 2315:
        printf("Precise Sft..");
        break;
    case 2316:
        printf("SENT License Manager.");
        break;
    case 2317:
        printf("Attachmate G32.");
        break;
    case 2318:
        printf("Cadence Control.");
        break;
    case 2319:
        printf("InfoLibria.");
        break;
    case 2320:
        printf("Siebel NS.");
        break;
    case 2321:
        printf("RDLAP.");
        break;
    case 2322:
        printf("ofsd.");
        break;
    case 2323:
        printf("3d-nfsd.");
        break;
    case 2324:
        printf("Cosmocall.");
        break;
    case 2325:
        printf("ANSYS Licensing Interconnect.");
        break;
    case 2326:
        printf("IDCP.");
        break;
    case 2327:
        printf("xingcsm.");
        break;
    case 2328:
        printf("Netrix SFTM.");
        break;
    case 2329:
        printf("NVD.");
        break;
    case 2330:
        printf("TSCCHAT.");
        break;
    case 2331:
        printf("AGENTVIEW.");
        break;
    case 2332:
        printf("RCC Host.");
        break;
    case 2333:
        printf("SNAPP.");
        break;
    case 2334:
        printf("ACE Client Auth.");
        break;
    case 2335:
        printf("ACE Proxy.");
        break;
    case 2336:
        printf("Apple UG Control.");
        break;
    case 2337:
        printf("ideesrv.");
        break;
    case 2338:
        printf("Norton Lambert.");
        break;
    case 2339:
        printf("3Com WebView.");
        break;
    case 2340:
        printf("WRS Registry .");
        break;
    case 2341:
        printf("XIO Status.");
        break;
    case 2342:
        printf("Seagate Manage Exec.");
        break;
    case 2343:
        printf("nati logos.");
        break;
    case 2344:
        printf("fcmsys.");
        break;
    case 2345:
        printf("dbm.");
        break;
    case 2346:
        printf("Game Connection Port.");
        break;
    case 2347:
        printf("Game Announcement and Location.");
        break;
    case 2348:
        printf("Information to query for game status.");
        break;
    case 2349:
        printf("Diagnostics Port.");
        break;
    case 2350:
        printf("Pharos Booking Server.");
        break;
    case 2351:
        printf("psrserver.");
        break;
    case 2352:
        printf("pslserver.");
        break;
    case 2353:
        printf("pspserver.");
        break;
    case 2354:
        printf("psprserver.");
        break;
    case 2355:
        printf("psdbserver.");
        break;
    case 2356:
        printf("GXT License Managemant.");
        break;
    case 2357:
        printf("UniHub Server.");
        break;
    case 2358:
        printf("Futrix.");
        break;
    case 2359:
        printf("FlukeServer.");
        break;
    case 2360:
        printf("NexstorIndLtd.");
        break;
    case 2361:
        printf("TL1.");
        break;
    case 2362:
        printf("digiman.");
        break;
    case 2363:
        printf("Media Central NFSD.");
        break;
    case 2364:
        printf("OI-2000.");
        break;
    case 2365:
        printf("dbref.");
        break;
    case 2366:
        printf("qip-login.");
        break;
    case 2367:
        printf("Service Control.");
        break;
    case 2368:
        printf("OpenTable.");
        break;
    case 2370:
        printf("L3-HBMon.");
        break;
    case 2371:
        printf("HP Remote Device Access.");
        break;
    case 2372:
        printf("LanMessenger.");
        break;
    case 2373:
        printf("Remograph License Manager.");
        break;
    case 2374:
        printf("Hydra RPC.");
        break;
    case 2375:
        printf("Docker REST API (plain text).");
        break;
    case 2376:
        printf("Docker REST API (ssl).");
        break;
    case 2377:
        printf("RPC interface for Docker Swarm.");
        break;
    case 2379:
        printf("etcd client communication.");
        break;
    case 2380:
        printf("etcd server to server communication.");
        break;
    case 2381:
        printf("Compaq HTTPS.");
        break;
    case 2382:
        printf("Microsoft OLAP.");
        break;
    case 2383:
        printf("Microsoft OLAP.");
        break;
    case 2384:
        printf("SD-REQUEST.");
        break;
    case 2385:
        printf("SD-DATA.");
        break;
    case 2386:
        printf("Virtual Tape.");
        break;
    case 2387:
        printf("VSAM Redirector.");
        break;
    case 2388:
        printf("MYNAH AutoStart.");
        break;
    case 2389:
        printf("OpenView Session Mgr.");
        break;
    case 2390:
        printf("RSMTP.");
        break;
    case 2391:
        printf("3COM Net Management.");
        break;
    case 2392:
        printf("Tactical Auth.");
        break;
    case 2393:
        printf("MS OLAP 1.");
        break;
    case 2394:
        printf("MS OLAP 2.");
        break;
    case 2395:
        printf("LAN900 Remote.");
        break;
    case 2396:
        printf("Wusage.");
        break;
    case 2397:
        printf("NCL.");
        break;
    case 2398:
        printf("Orbiter.");
        break;
    case 2399:
        printf("FileMaker, Inc. - Data Access Layer.");
        break;
    case 2400:
        printf("OpEquus Server.");
        break;
    case 2401:
        printf("cvspserver.");
        break;
    case 2402:
        printf("TaskMaster 2000 Server.");
        break;
    case 2403:
        printf("TaskMaster 2000 Web.");
        break;
    case 2404:
        printf("IEC 60870-5-104 process control over IP.");
        break;
    case 2405:
        printf("TRC Netpoll.");
        break;
    case 2406:
        printf("JediServer.");
        break;
    case 2407:
        printf("Orion.");
        break;
    case 2408:
        printf("CloudFlare Railgun Web Acceleration Protocol.");
        break;
    case 2409:
        printf("SNS Protocol.");
        break;
    case 2410:
        printf("VRTS Registry.");
        break;
    case 2411:
        printf("Netwave AP Management.");
        break;
    case 2412:
        printf("CDN.");
        break;
    case 2413:
        printf("orion-rmi-reg.");
        break;
    case 2414:
        printf("Beeyond.");
        break;
    case 2415:
        printf("Codima Remote Transaction Protocol.");
        break;
    case 2416:
        printf("RMT Server.");
        break;
    case 2417:
        printf("Composit Server.");
        break;
    case 2418:
        printf("cas.");
        break;
    case 2419:
        printf("Attachmate S2S.");
        break;
    case 2420:
        printf("DSL Remote Management.");
        break;
    case 2421:
        printf("G-Talk.");
        break;
    case 2422:
        printf("CRMSBITS.");
        break;
    case 2423:
        printf("RNRP.");
        break;
    case 2424:
        printf("KOFAX-SVR.");
        break;
    case 2425:
        printf("Fujitsu App Manager.");
        break;
    case 2426:
        printf("VeloCloud MultiPath Protocol.");
        break;
    case 2427:
        printf("Media Gateway Control Protocol Gateway.");
        break;
    case 2428:
        printf("One Way Trip Time.");
        break;
    case 2429:
        printf("FT-ROLE.");
        break;
    case 2430:
        printf("venus.");
        break;
    case 2431:
        printf("venus-se.");
        break;
    case 2432:
        printf("codasrv.");
        break;
    case 2433:
        printf("codasrv-se.");
        break;
    case 2434:
        printf("pxc-epmap.");
        break;
    case 2435:
        printf("OptiLogic.");
        break;
    case 2436:
        printf("TOP/X.");
        break;
    case 2437:
        printf("UniControl.");
        break;
    case 2438:
        printf("MSP.");
        break;
    case 2439:
        printf("SybaseDBSynch.");
        break;
    case 2440:
        printf("Spearway Lockers.");
        break;
    case 2441:
        printf("Pervasive I*net Data Server.");
        break;
    case 2442:
        printf("Netangel.");
        break;
    case 2443:
        printf("PowerClient Central Storage Facility.");
        break;
    case 2444:
        printf("BT PP2 Sectrans.");
        break;
    case 2445:
        printf("DTN1.");
        break;
    case 2446:
        printf("bues_service.");
        break;
    case 2447:
        printf("OpenView NNM daemon.");
        break;
    case 2448:
        printf("hpppsvr.");
        break;
    case 2449:
        printf("RATL.");
        break;
    case 2450:
        printf("netadmin.");
        break;
    case 2451:
        printf("netchat.");
        break;
    case 2452:
        printf("SnifferClient.");
        break;
    case 2453:
        printf("madge ltd.");
        break;
    case 2454:
        printf("IndX-DDS.");
        break;
    case 2455:
        printf("WAGO-IO-SYSTEM.");
        break;
    case 2456:
        printf("altav-remmgt.");
        break;
    case 2457:
        printf("Rapido_IP.");
        break;
    case 2458:
        printf("griffin.");
        break;
    case 2459:
        printf("Community.");
        break;
    case 2460:
        printf("ms-theater.");
        break;
    case 2461:
        printf("qadmifoper.");
        break;
    case 2462:
        printf("qadmifevent.");
        break;
    case 2463:
        printf("LSI RAID Management.");
        break;
    case 2464:
        printf("DirecPC SI.");
        break;
    case 2465:
        printf("Load Balance Management.");
        break;
    case 2466:
        printf("Load Balance Forwarding.");
        break;
    case 2467:
        printf("High Criteria.");
        break;
    case 2468:
        printf("qip_msgd.");
        break;
    case 2469:
        printf("MTI-TCS-COMM.");
        break;
    case 2470:
        printf("taskman port.");
        break;
    case 2471:
        printf("SeaODBC.");
        break;
    case 2472:
        printf("C3.");
        break;
    case 2473:
        printf("Aker-cdp.");
        break;
    case 2474:
        printf("Vital Analysis.");
        break;
    case 2475:
        printf("ACE Server.");
        break;
    case 2476:
        printf("ACE Server Propagation.");
        break;
    case 2477:
        printf("SecurSight Certificate Valifation Service.");
        break;
    case 2478:
        printf("SecurSight Authentication Server (SSL).");
        break;
    case 2479:
        printf("SecurSight Event Logging Server (SSL).");
        break;
    case 2480:
        printf("Informatica PowerExchange Listener.");
        break;
    case 2481:
        printf("Oracle GIOP.");
        break;
    case 2482:
        printf("Oracle GIOP SSL.");
        break;
    case 2483:
        printf("Oracle TTC.");
        break;
    case 2484:
        printf("Oracle TTC SSL.");
        break;
    case 2485:
        printf("Net Objects1.");
        break;
    case 2486:
        printf("Net Objects2.");
        break;
    case 2487:
        printf("Policy Notice Service.");
        break;
    case 2488:
        printf("Moy Corporation.");
        break;
    case 2489:
        printf("TSILB.");
        break;
    case 2490:
        printf("qip_qdhcp.");
        break;
    case 2491:
        printf("Conclave CPP.");
        break;
    case 2492:
        printf("GROOVE.");
        break;
    case 2493:
        printf("Talarian MQS.");
        break;
    case 2494:
        printf("BMC AR.");
        break;
    case 2495:
        printf("Fast Remote Services.");
        break;
    case 2496:
        printf("DIRGIS.");
        break;
    case 2497:
        printf("Quad DB.");
        break;
    case 2498:
        printf("ODN-CasTraq.");
        break;
    case 2499:
        printf("UniControl.");
        break;
    case 2500:
        printf("Resource Tracking system server.");
        break;
    case 2501:
        printf("Resource Tracking system client.");
        break;
    case 2502:
        printf("Kentrox Protocol.");
        break;
    case 2503:
        printf("NMS-DPNSS.");
        break;
    case 2504:
        printf("WLBS.");
        break;
    case 2505:
        printf("PowerPlay Control.");
        break;
    case 2506:
        printf("jbroker.");
        break;
    case 2507:
        printf("spock.");
        break;
    case 2508:
        printf("JDataStore.");
        break;
    case 2509:
        printf("fjmpss.");
        break;
    case 2510:
        printf("fjappmgrbulk.");
        break;
    case 2511:
        printf("Metastorm.");
        break;
    case 2512:
        printf("Citrix IMA.");
        break;
    case 2513:
        printf("Citrix ADMIN.");
        break;
    case 2514:
        printf("Facsys NTP.");
        break;
    case 2515:
        printf("Facsys Router.");
        break;
    case 2516:
        printf("Main Control.");
        break;
    case 2517:
        printf("H.323 Annex E Call Control Signalling Transport.");
        break;
    case 2518:
        printf("Willy.");
        break;
    case 2519:
        printf("globmsgsvc.");
        break;
    case 2520:
        printf("Pervasive Listener.");
        break;
    case 2521:
        printf("Adaptec Manager.");
        break;
    case 2522:
        printf("WinDb.");
        break;
    case 2523:
        printf("Qke LLC V.3.");
        break;
    case 2524:
        printf("Optiwave License Management.");
        break;
    case 2525:
        printf("MS V-Worlds.");
        break;
    case 2526:
        printf("EMA License Manager.");
        break;
    case 2527:
        printf("IQ Server.");
        break;
    case 2528:
        printf("NCR CCL.");
        break;
    case 2529:
        printf("UTS FTP.");
        break;
    case 2530:
        printf("VR Commerce.");
        break;
    case 2531:
        printf("ITO-E GUI.");
        break;
    case 2532:
        printf("OVTOPMD.");
        break;
    case 2533:
        printf("SnifferServer.");
        break;
    case 2534:
        printf("Combox Web Access.");
        break;
    case 2535:
        printf("MADCAP.");
        break;
    case 2536:
        printf("btpp2audctr1.");
        break;
    case 2537:
        printf("Upgrade Protocol.");
        break;
    case 2538:
        printf("vnwk-prapi.");
        break;
    case 2539:
        printf("VSI Admin.");
        break;
    case 2540:
        printf("LonWorks.");
        break;
    case 2541:
        printf("LonWorks2.");
        break;
    case 2542:
        printf("uDraw(Graph).");
        break;
    case 2543:
        printf("REFTEK.");
        break;
    case 2544:
        printf("Management Daemon Refresh.");
        break;
    case 2545:
        printf("sis-emt.");
        break;
    case 2546:
        printf("vytalvaultbrtp.");
        break;
    case 2547:
        printf("vytalvaultvsmp.");
        break;
    case 2548:
        printf("vytalvaultpipe.");
        break;
    case 2549:
        printf("IPASS.");
        break;
    case 2550:
        printf("ADS.");
        break;
    case 2551:
        printf("ISG UDA Server.");
        break;
    case 2552:
        printf("Call Logging.");
        break;
    case 2553:
        printf("efidiningport.");
        break;
    case 2554:
        printf("VCnet-Link v10.");
        break;
    case 2555:
        printf("Compaq WCP.");
        break;
    case 2556:
        printf("nicetec-nmsvc.");
        break;
    case 2557:
        printf("nicetec-mgmt.");
        break;
    case 2558:
        printf("PCLE Multi Media.");
        break;
    case 2559:
        printf("LSTP.");
        break;
    case 2560:
        printf("labrat.");
        break;
    case 2561:
        printf("MosaixCC.");
        break;
    case 2562:
        printf("Delibo.");
        break;
    case 2563:
        printf("CTI Redwood.");
        break;
    case 2564:
        printf("HP 3000 NS/VT block mode telnet.");
        break;
    case 2565:
        printf("Coordinator Server.");
        break;
    case 2566:
        printf("pcs-pcw.");
        break;
    case 2567:
        printf("Cisco Line Protocol.");
        break;
    case 2568:
        printf("SPAM TRAP.");
        break;
    case 2569:
        printf("Sonus Call Signal.");
        break;
    case 2570:
        printf("HS Port.");
        break;
    case 2571:
        printf("CECSVC.");
        break;
    case 2572:
        printf("IBP.");
        break;
    case 2573:
        printf("Trust Establish.");
        break;
    case 2574:
        printf("Blockade BPSP.");
        break;
    case 2575:
        printf("HL7.");
        break;
    case 2576:
        printf("TCL Pro Debugger.");
        break;
    case 2577:
        printf("Scriptics Lsrvr.");
        break;
    case 2578:
        printf("RVS ISDN DCP.");
        break;
    case 2579:
        printf("mpfoncl.");
        break;
    case 2580:
        printf("Tributary.");
        break;
    case 2581:
        printf("ARGIS TE.");
        break;
    case 2582:
        printf("ARGIS DS.");
        break;
    case 2583:
        printf("MON.");
        break;
    case 2584:
        printf("cyaserv.");
        break;
    case 2585:
        printf("NETX Server.");
        break;
    case 2586:
        printf("NETX Agent.");
        break;
    case 2587:
        printf("MASC.");
        break;
    case 2588:
        printf("Privilege.");
        break;
    case 2589:
        printf("quartus tcl.");
        break;
    case 2590:
        printf("idotdist.");
        break;
    case 2591:
        printf("Maytag Shuffle.");
        break;
    case 2592:
        printf("netrek.");
        break;
    case 2593:
        printf("MNS Mail Notice Service.");
        break;
    case 2594:
        printf("Data Base Server.");
        break;
    case 2595:
        printf("World Fusion 1.");
        break;
    case 2596:
        printf("World Fusion 2.");
        break;
    case 2597:
        printf("Homestead Glory.");
        break;
    case 2598:
        printf("Citrix MA Client.");
        break;
    case 2599:
        printf("Snap Discovery.");
        break;
    case 2600:
        printf("HPSTGMGR.");
        break;
    case 2601:
        printf("discp client.");
        break;
    case 2602:
        printf("discp server.");
        break;
    case 2603:
        printf("Service Meter.");
        break;
    case 2604:
        printf("NSC CCS.");
        break;
    case 2605:
        printf("NSC POSA.");
        break;
    case 2606:
        printf("Dell Netmon.");
        break;
    case 2607:
        printf("Dell Connection.");
        break;
    case 2608:
        printf("Wag Service.");
        break;
    case 2609:
        printf("System Monitor.");
        break;
    case 2610:
        printf("VersaTek.");
        break;
    case 2611:
        printf("LIONHEAD.");
        break;
    case 2612:
        printf("Qpasa Agent.");
        break;
    case 2613:
        printf("SMNTUBootstrap.");
        break;
    case 2614:
        printf("Never Offline.");
        break;
    case 2615:
        printf("firepower.");
        break;
    case 2616:
        printf("appswitch-emp.");
        break;
    case 2617:
        printf("Clinical Context Managers.");
        break;
    case 2618:
        printf("Priority E-Com.");
        break;
    case 2619:
        printf("bruce.");
        break;
    case 2620:
        printf("LPSRecommender.");
        break;
    case 2621:
        printf("Miles Apart Jukebox Server.");
        break;
    case 2622:
        printf("MetricaDBC.");
        break;
    case 2623:
        printf("LMDP.");
        break;
    case 2624:
        printf("Aria.");
        break;
    case 2625:
        printf("Blwnkl Port.");
        break;
    case 2626:
        printf("gbjd816.");
        break;
    case 2627:
        printf("Moshe Beeri.");
        break;
    case 2628:
        printf("DICT.");
        break;
    case 2629:
        printf("Sitara Server.");
        break;
    case 2630:
        printf("Sitara Management.");
        break;
    case 2631:
        printf("Sitara Dir.");
        break;
    case 2632:
        printf("IRdg Post.");
        break;
    case 2633:
        printf("InterIntelli.");
        break;
    case 2634:
        printf("PK Electronics.");
        break;
    case 2635:
        printf("Back Burner.");
        break;
    case 2636:
        printf("Solve.");
        break;
    case 2637:
        printf("Import Document Service.");
        break;
    case 2638:
        printf("Sybase Anywhere.");
        break;
    case 2639:
        printf("AMInet.");
        break;
    case 2640:
        printf("Alcorn McBride Inc protocol used for device control.");
        break;
    case 2641:
        printf("HDL Server.");
        break;
    case 2642:
        printf("Tragic.");
        break;
    case 2643:
        printf("GTE-SAMP.");
        break;
    case 2644:
        printf("Travsoft IPX Tunnel.");
        break;
    case 2645:
        printf("Novell IPX CMD.");
        break;
    case 2646:
        printf("AND License Manager.");
        break;
    case 2647:
        printf("SyncServer.");
        break;
    case 2648:
        printf("Upsnotifyprot.");
        break;
    case 2649:
        printf("VPSIPPORT.");
        break;
    case 2650:
        printf("eristwoguns.");
        break;
    case 2651:
        printf("EBInSite.");
        break;
    case 2652:
        printf("InterPathPanel.");
        break;
    case 2653:
        printf("Sonus.");
        break;
    case 2654:
        printf("Corel VNC Admin.");
        break;
    case 2655:
        printf("UNIX Nt Glue.");
        break;
    case 2656:
        printf("Kana.");
        break;
    case 2657:
        printf("SNS Dispatcher.");
        break;
    case 2658:
        printf("SNS Admin.");
        break;
    case 2659:
        printf("SNS Query.");
        break;
    case 2660:
        printf("GC Monitor.");
        break;
    case 2661:
        printf("OLHOST.");
        break;
    case 2662:
        printf("BinTec-CAPI.");
        break;
    case 2663:
        printf("BinTec-TAPI.");
        break;
    case 2664:
        printf("Patrol for MQ GM.");
        break;
    case 2665:
        printf("Patrol for MQ NM.");
        break;
    case 2666:
        printf("extensis.");
        break;
    case 2667:
        printf("Alarm Clock Server.");
        break;
    case 2668:
        printf("Alarm Clock Client.");
        break;
    case 2669:
        printf("TOAD.");
        break;
    case 2670:
        printf("TVE Announce.");
        break;
    case 2671:
        printf("newlixreg.");
        break;
    case 2672:
        printf("nhserver.");
        break;
    case 2673:
        printf("First Call 42.");
        break;
    case 2674:
        printf("ewnn.");
        break;
    case 2675:
        printf("TTC ETAP.");
        break;
    case 2676:
        printf("SIMSLink.");
        break;
    case 2677:
        printf("Gadget Gate 1 Way.");
        break;
    case 2678:
        printf("Gadget Gate 2 Way.");
        break;
    case 2679:
        printf("Sync Server SSL.");
        break;
    case 2680:
        printf("pxc-sapxom.");
        break;
    case 2681:
        printf("mpnjsomb.");
        break;
    case 2683:
        printf("NCDLoadBalance.");
        break;
    case 2684:
        printf("mpnjsosv.");
        break;
    case 2685:
        printf("mpnjsocl.");
        break;
    case 2686:
        printf("mpnjsomg.");
        break;
    case 2687:
        printf("pq-lic-mgmt.");
        break;
    case 2688:
        printf("md-cf-http.");
        break;
    case 2689:
        printf("FastLynx.");
        break;
    case 2690:
        printf("HP NNM Embedded Database.");
        break;
    case 2691:
        printf("ITInternet ISM Server.");
        break;
    case 2692:
        printf("Admins LMS.");
        break;
    case 2694:
        printf("pwrsevent.");
        break;
    case 2695:
        printf("VSPREAD.");
        break;
    case 2696:
        printf("Unify Admin.");
        break;
    case 2697:
        printf("Oce SNMP Trap Port.");
        break;
    case 2698:
        printf("MCK-IVPIP.");
        break;
    case 2699:
        printf("Csoft Plus Client.");
        break;
    case 2700:
        printf("tqdata.");
        break;
    case 2701:
        printf("SMS RCINFO.");
        break;
    case 2702:
        printf("SMS XFER.");
        break;
    case 2703:
        printf("SMS CHAT.");
        break;
    case 2704:
        printf("SMS REMCTRL.");
        break;
    case 2705:
        printf("SDS Admin.");
        break;
    case 2706:
        printf("NCD Mirroring.");
        break;
    case 2707:
        printf("EMCSYMAPIPORT.");
        break;
    case 2708:
        printf("Banyan-Net.");
        break;
    case 2709:
        printf("Supermon.");
        break;
    case 2710:
        printf("SSO Service.");
        break;
    case 2711:
        printf("SSO Control.");
        break;
    case 2712:
        printf("Axapta Object Communication Protocol.");
        break;
    case 2713:
        printf("Raven Trinity Broker Service.");
        break;
    case 2714:
        printf("Raven Trinity Data Mover.");
        break;
    case 2715:
        printf("HPSTGMGR2.");
        break;
    case 2716:
        printf("Inova IP Disco.");
        break;
    case 2717:
        printf("PN REQUESTER.");
        break;
    case 2718:
        printf("PN REQUESTER 2.");
        break;
    case 2719:
        printf("Scan & Change.");
        break;
    case 2720:
        printf("wkars.");
        break;
    case 2721:
        printf("Smart Diagnose.");
        break;
    case 2722:
        printf("Proactive Server.");
        break;
    case 2723:
        printf("WatchDog NT Protocol.");
        break;
    case 2724:
        printf("qotps.");
        break;
    case 2725:
        printf("MSOLAP PTP2.");
        break;
    case 2726:
        printf("TAMS.");
        break;
    case 2727:
        printf("Media Gateway Control Protocol Call Agent.");
        break;
    case 2728:
        printf("SQDR.");
        break;
    case 2729:
        printf("TCIM Control.");
        break;
    case 2730:
        printf("NEC RaidPlus.");
        break;
    case 2731:
        printf("Fyre Messanger.");
        break;
    case 2732:
        printf("G5M.");
        break;
    case 2733:
        printf("Signet CTF.");
        break;
    case 2734:
        printf("CCS Software.");
        break;
    case 2735:
        printf("NetIQ Monitor Console.");
        break;
    case 2736:
        printf("RADWIZ NMS SRV.");
        break;
    case 2737:
        printf("SRP Feedback.");
        break;
    case 2738:
        printf("NDL TCP-OSI Gateway.");
        break;
    case 2739:
        printf("TN Timing.");
        break;
    case 2740:
        printf("Alarm.");
        break;
    case 2741:
        printf("TSB.");
        break;
    case 2742:
        printf("TSB2.");
        break;
    case 2743:
        printf("murx.");
        break;
    case 2744:
        printf("honyaku.");
        break;
    case 2745:
        printf("URBISNET.");
        break;
    case 2746:
        printf("CPUDPENCAP.");
        break;
    case 2752:
        printf("RSISYS ACCESS.");
        break;
    case 2753:
        printf("de-spot.");
        break;
    case 2754:
        printf("APOLLO CC.");
        break;
    case 2755:
        printf("Express Pay.");
        break;
    case 2756:
        printf("simplement-tie.");
        break;
    case 2757:
        printf("CNRP.");
        break;
    case 2758:
        printf("APOLLO Status.");
        break;
    case 2759:
        printf("APOLLO GMS.");
        break;
    case 2760:
        printf("Saba MS.");
        break;
    case 2761:
        printf("DICOM ISCL.");
        break;
    case 2762:
        printf("DICOM TLS.");
        break;
    case 2763:
        printf("Desktop DNA.");
        break;
    case 2764:
        printf("Data Insurance.");
        break;
    case 2765:
        printf("qip-audup.");
        break;
    case 2766:
        printf("Compaq SCP.");
        break;
    case 2767:
        printf("UADTC.");
        break;
    case 2768:
        printf("UACS.");
        break;
    case 2769:
        printf("eXcE.");
        break;
    case 2770:
        printf("Veronica.");
        break;
    case 2771:
        printf("Vergence CM.");
        break;
    case 2772:
        printf("auris.");
        break;
    case 2773:
        printf("RBackup Remote Backup.");
        break;
    case 2774:
        printf("RBackup Remote Backup.");
        break;
    case 2775:
        printf("SMPP.");
        break;
    case 2776:
        printf("Ridgeway Systems & Software.");
        break;
    case 2777:
        printf("Ridgeway Systems & Software.");
        break;
    case 2778:
        printf("Gwen-Sonya.");
        break;
    case 2779:
        printf("LBC Sync.");
        break;
    case 2780:
        printf("LBC Control.");
        break;
    case 2781:
        printf("whosells.");
        break;
    case 2782:
        printf("everydayrc.");
        break;
    case 2783:
        printf("AISES.");
        break;
    case 2784:
        printf("world wide web - development.");
        break;
    case 2785:
        printf("aic-np.");
        break;
    case 2786:
        printf("aic-oncrpc - Destiny MCD database.");
        break;
    case 2787:
        printf("piccolo - Cornerstone Software.");
        break;
    case 2788:
        printf("NetWare Loadable Module - Seagate Software.");
        break;
    case 2789:
        printf("Media Agent.");
        break;
    case 2790:
        printf("PLG Proxy.");
        break;
    case 2791:
        printf("MT Port Registrator.");
        break;
    case 2792:
        printf("f5-globalsite.");
        break;
    case 2793:
        printf("initlsmsad.");
        break;
    case 2795:
        printf("LiveStats.");
        break;
    case 2796:
        printf("ac-tech.");
        break;
    case 2797:
        printf("esp-encap.");
        break;
    case 2798:
        printf("TMESIS-UPShot.");
        break;
    case 2799:
        printf("ICON Discover.");
        break;
    case 2800:
        printf("ACC RAID.");
        break;
    case 2801:
        printf("IGCP.");
        break;
    case 2802:
        printf("Veritas TCP1.");
        break;
    case 2803:
        printf("btprjctrl.");
        break;
    case 2804:
        printf("March Networks Digital Video Recorders and Enterprise Service Manager products.");
        break;
    case 2805:
        printf("WTA WSP-S.");
        break;
    case 2806:
        printf("cspuni.");
        break;
    case 2807:
        printf("cspmulti.");
        break;
    case 2808:
        printf("J-LAN-P.");
        break;
    case 2809:
        printf("CORBA LOC.");
        break;
    case 2810:
        printf("Active Net Steward.");
        break;
    case 2811:
        printf("GSI FTP.");
        break;
    case 2812:
        printf("atmtcp.");
        break;
    case 2813:
        printf("llm-pass.");
        break;
    case 2814:
        printf("llm-csv.");
        break;
    case 2815:
        printf("LBC Measurement.");
        break;
    case 2816:
        printf("LBC Watchdog.");
        break;
    case 2817:
        printf("NMSig Port.");
        break;
    case 2818:
        printf("rmlnk.");
        break;
    case 2819:
        printf("FC Fault Notification.");
        break;
    case 2820:
        printf("UniVision.");
        break;
    case 2821:
        printf("VERITAS Authentication Service.");
        break;
    case 2822:
        printf("ka0wuc.");
        break;
    case 2823:
        printf("CQG Net/LAN.");
        break;
    case 2824:
        printf("CQG Net/LAN 1.");
        break;
    case 2826:
        printf("slc systemlog.");
        break;
    case 2827:
        printf("slc ctrlrloops.");
        break;
    case 2828:
        printf("ITM License Manager.");
        break;
    case 2829:
        printf("silkp1.");
        break;
    case 2830:
        printf("silkp2.");
        break;
    case 2831:
        printf("silkp3.");
        break;
    case 2832:
        printf("silkp4.");
        break;
    case 2833:
        printf("glishd.");
        break;
    case 2834:
        printf("EVTP.");
        break;
    case 2835:
        printf("EVTP-DATA.");
        break;
    case 2836:
        printf("catalyst.");
        break;
    case 2837:
        printf("Repliweb.");
        break;
    case 2838:
        printf("Starbot.");
        break;
    case 2839:
        printf("NMSigPort.");
        break;
    case 2840:
        printf("l3-exprt.");
        break;
    case 2841:
        printf("l3-ranger.");
        break;
    case 2842:
        printf("l3-hawk.");
        break;
    case 2843:
        printf("PDnet.");
        break;
    case 2844:
        printf("BPCP POLL.");
        break;
    case 2845:
        printf("BPCP TRAP.");
        break;
    case 2846:
        printf("AIMPP Hello.");
        break;
    case 2847:
        printf("AIMPP Port Req.");
        break;
    case 2848:
        printf("AMT-BLC-PORT.");
        break;
    case 2849:
        printf("FXP.");
        break;
    case 2850:
        printf("MetaConsole.");
        break;
    case 2851:
        printf("webemshttp.");
        break;
    case 2852:
        printf("bears-01.");
        break;
    case 2853:
        printf("ISPipes.");
        break;
    case 2854:
        printf("InfoMover.");
        break;
    case 2855:
        printf("MSRP over TCP.");
        break;
    case 2856:
        printf("cesdinv.");
        break;
    case 2857:
        printf("SimCtIP.");
        break;
    case 2858:
        printf("ECNP.");
        break;
    case 2859:
        printf("Active Memory.");
        break;
    case 2860:
        printf("Dialpad Voice 1.");
        break;
    case 2861:
        printf("Dialpad Voice 2.");
        break;
    case 2862:
        printf("TTG Protocol.");
        break;
    case 2863:
        printf("Sonar Data.");
        break;
    case 2864:
        printf("main 5001 cmd.");
        break;
    case 2865:
        printf("pit-vpn.");
        break;
    case 2866:
        printf("iwlistener.");
        break;
    case 2867:
        printf("esps-portal.");
        break;
    case 2868:
        printf("Norman Proprietaqry Events Protocol.");
        break;
    case 2869:
        printf("ICSLAP.");
        break;
    case 2870:
        printf("daishi.");
        break;
    case 2871:
        printf("MSI Select Play.");
        break;
    case 2872:
        printf("RADIX.");
        break;
    case 2874:
        printf("DX Message Base Transport Protocol.");
        break;
    case 2875:
        printf("DX Message Base Transport Protocol.");
        break;
    case 2876:
        printf("SPS Tunnel.");
        break;
    case 2877:
        printf("BLUELANCE.");
        break;
    case 2878:
        printf("AAP.");
        break;
    case 2879:
        printf("ucentric-ds.");
        break;
    case 2880:
        printf("Synapse Transport.");
        break;
    case 2881:
        printf("NDSP.");
        break;
    case 2882:
        printf("NDTP.");
        break;
    case 2883:
        printf("NDNP.");
        break;
    case 2884:
        printf("Flash Msg.");
        break;
    case 2885:
        printf("TopFlow.");
        break;
    case 2886:
        printf("RESPONSELOGIC.");
        break;
    case 2887:
        printf("aironet.");
        break;
    case 2888:
        printf("SPCSDLOBBY.");
        break;
    case 2889:
        printf("RSOM.");
        break;
    case 2890:
        printf("CSPCLMULTI.");
        break;
    case 2891:
        printf("CINEGRFX-ELMD License Manager.");
        break;
    case 2892:
        printf("SNIFFERDATA.");
        break;
    case 2893:
        printf("VSECONNECTOR.");
        break;
    case 2894:
        printf("ABACUS-REMOTE.");
        break;
    case 2895:
        printf("NATUS LINK.");
        break;
    case 2896:
        printf("ECOVISIONG6-1.");
        break;
    case 2897:
        printf("Citrix RTMP.");
        break;
    case 2898:
        printf("APPLIANCE-CFG.");
        break;
    case 2899:
        printf("POWERGEMPLUS.");
        break;
    case 2900:
        printf("QUICKSUITE.");
        break;
    case 2901:
        printf("ALLSTORCNS.");
        break;
    case 2902:
        printf("NET ASPI.");
        break;
    case 2903:
        printf("SUITCASE.");
        break;
    case 2904:
        printf("M2UA.");
        break;
    case 2905:
        printf("M3UA.");
        break;
    case 2906:
        printf("CALLER9.");
        break;
    case 2907:
        printf("WEBMETHODS B2B.");
        break;
    case 2908:
        printf("mao.");
        break;
    case 2909:
        printf("Funk Dialout.");
        break;
    case 2910:
        printf("TDAccess.");
        break;
    case 2911:
        printf("Blockade.");
        break;
    case 2912:
        printf("Epicon.");
        break;
    case 2913:
        printf("Booster Ware.");
        break;
    case 2914:
        printf("Game Lobby.");
        break;
    case 2915:
        printf("TK Socket.");
        break;
    case 2916:
        printf("Elvin Server.");
        break;
    case 2917:
        printf("Elvin Client.");
        break;
    case 2918:
        printf("Kasten Chase Pad.");
        break;
    case 2919:
        printf("roboER.");
        break;
    case 2920:
        printf("roboEDA.");
        break;
    case 2921:
        printf("CESD Contents Delivery Management.");
        break;
    case 2922:
        printf("CESD Contents Delivery Data Transfer.");
        break;
    case 2923:
        printf("WTA-WSP-WTP-S.");
        break;
    case 2924:
        printf("PRECISE-VIP.");
        break;
    case 2926:
        printf("MOBILE-FILE-DL.");
        break;
    case 2927:
        printf("UNIMOBILECTRL.");
        break;
    case 2928:
        printf("REDSTONE-CPSS.");
        break;
    case 2929:
        printf("AMX-WEBADMIN.");
        break;
    case 2930:
        printf("AMX-WEBLINX.");
        break;
    case 2931:
        printf("Circle-X.");
        break;
    case 2932:
        printf("INCP.");
        break;
    case 2933:
        printf("4-TIER OPM GW.");
        break;
    case 2934:
        printf("4-TIER OPM CLI.");
        break;
    case 2935:
        printf("QTP.");
        break;
    case 2936:
        printf("OTPatch.");
        break;
    case 2937:
        printf("PNACONSULT-LM.");
        break;
    case 2938:
        printf("SM-PAS-1.");
        break;
    case 2939:
        printf("SM-PAS-2.");
        break;
    case 2940:
        printf("SM-PAS-3.");
        break;
    case 2941:
        printf("SM-PAS-4.");
        break;
    case 2942:
        printf("SM-PAS-5.");
        break;
    case 2943:
        printf("TTNRepository.");
        break;
    case 2944:
        printf("Megaco H-248.");
        break;
    case 2945:
        printf("H248 Binary.");
        break;
    case 2946:
        printf("FJSVmpor.");
        break;
    case 2947:
        printf("GPS Daemon request/response protocol.");
        break;
    case 2948:
        printf("WAP PUSH.");
        break;
    case 2949:
        printf("WAP PUSH SECURE.");
        break;
    case 2950:
        printf("ESIP.");
        break;
    case 2951:
        printf("OTTP.");
        break;
    case 2952:
        printf("MPFWSAS.");
        break;
    case 2953:
        printf("OVALARMSRV.");
        break;
    case 2954:
        printf("OVALARMSRV-CMD.");
        break;
    case 2955:
        printf("CSNOTIFY.");
        break;
    case 2956:
        printf("OVRIMOSDBMAN.");
        break;
    case 2957:
        printf("JAMCT5.");
        break;
    case 2958:
        printf("JAMCT6.");
        break;
    case 2959:
        printf("RMOPAGT.");
        break;
    case 2960:
        printf("DFOXSERVER.");
        break;
    case 2961:
        printf("BOLDSOFT-LM.");
        break;
    case 2962:
        printf("IPH-POLICY-CLI.");
        break;
    case 2963:
        printf("IPH-POLICY-ADM.");
        break;
    case 2964:
        printf("BULLANT SRAP.");
        break;
    case 2965:
        printf("BULLANT RAP.");
        break;
    case 2966:
        printf("IDP-INFOTRIEVE.");
        break;
    case 2967:
        printf("SSC-AGENT.");
        break;
    case 2968:
        printf("ENPP.");
        break;
    case 2969:
        printf("ESSP.");
        break;
    case 2970:
        printf("INDEX-NET.");
        break;
    case 2971:
        printf("NetClip clipboard daemon.");
        break;
    case 2972:
        printf("PMSM Webrctl.");
        break;
    case 2973:
        printf("SV Networks.");
        break;
    case 2974:
        printf("Signal.");
        break;
    case 2975:
        printf("Fujitsu Configuration Management Service.");
        break;
    case 2976:
        printf("CNS Server Port.");
        break;
    case 2977:
        printf("TTCs Enterprise Test Access Protocol - NS.");
        break;
    case 2978:
        printf("TTCs Enterprise Test Access Protocol - DS.");
        break;
    case 2979:
        printf("H.263 Video Streaming.");
        break;
    case 2980:
        printf("Instant Messaging Service.");
        break;
    case 2981:
        printf("MYLXAMPORT.");
        break;
    case 2982:
        printf("IWB-WHITEBOARD.");
        break;
    case 2983:
        printf("NETPLAN.");
        break;
    case 2984:
        printf("HPIDSADMIN.");
        break;
    case 2985:
        printf("HPIDSAGENT.");
        break;
    case 2986:
        printf("STONEFALLS.");
        break;
    case 2987:
        printf("identify.");
        break;
    case 2988:
        printf("HIPPA Reporting Protocol.");
        break;
    case 2989:
        printf("ZARKOV Intelligent Agent Communication.");
        break;
    case 2990:
        printf("BOSCAP.");
        break;
    case 2991:
        printf("WKSTN-MON.");
        break;
    case 2992:
        printf("Avenyo Server.");
        break;
    case 2993:
        printf("VERITAS VIS1.");
        break;
    case 2994:
        printf("VERITAS VIS2.");
        break;
    case 2995:
        printf("IDRS.");
        break;
    case 2996:
        printf("vsixml.");
        break;
    case 2997:
        printf("REBOL.");
        break;
    case 2998:
        printf("Real Secure.");
        break;
    case 2999:
        printf("RemoteWare Unassigned.");
        break;
    case 3000:
        printf("HBCI.");
        break;
    case 3001:
        printf("OrigoDB Server Native Interface.");
        break;
    case 3002:
        printf("EXLM Agent.");
        break;
    case 3003:
        printf("CGMS.");
        break;
    case 3004:
        printf("Csoft Agent.");
        break;
    case 3005:
        printf("Genius License Manager.");
        break;
    case 3006:
        printf("Instant Internet Admin.");
        break;
    case 3007:
        printf("Lotus Mail Tracking Agent Protocol.");
        break;
    case 3008:
        printf("Midnight Technologies.");
        break;
    case 3009:
        printf("PXC-NTFY.");
        break;
    case 3010:
        printf("Telerate Workstation.");
        break;
    case 3011:
        printf("Trusted Web.");
        break;
    case 3012:
        printf("Trusted Web Client.");
        break;
    case 3013:
        printf("Gilat Sky Surfer.");
        break;
    case 3014:
        printf("Broker Service.");
        break;
    case 3015:
        printf("NATI DSTP.");
        break;
    case 3016:
        printf("Notify Server.");
        break;
    case 3017:
        printf("Event Listener.");
        break;
    case 3018:
        printf("Service Registry.");
        break;
    case 3019:
        printf("Resource Manager.");
        break;
    case 3020:
        printf("CIFS.");
        break;
    case 3021:
        printf("AGRI Server.");
        break;
    case 3022:
        printf("CSREGAGENT.");
        break;
    case 3023:
        printf("magicnotes.");
        break;
    case 3024:
        printf("NDS_SSO.");
        break;
    case 3025:
        printf("Arepa Raft.");
        break;
    case 3026:
        printf("AGRI Gateway.");
        break;
    case 3027:
        printf("LiebDevMgmt_C.");
        break;
    case 3028:
        printf("LiebDevMgmt_DM.");
        break;
    case 3029:
        printf("LiebDevMgmt_A.");
        break;
    case 3030:
        printf("Arepa Cas.");
        break;
    case 3031:
        printf("Remote AppleEvents/PPC Toolbox.");
        break;
    case 3032:
        printf("Redwood Chat.");
        break;
    case 3033:
        printf("PDB.");
        break;
    case 3034:
        printf("Osmosis / Helix (R) AEEA Port.");
        break;
    case 3035:
        printf("FJSV gssagt.");
        break;
    case 3036:
        printf("Hagel DUMP.");
        break;
    case 3037:
        printf("HP SAN Mgmt.");
        break;
    case 3038:
        printf("Santak UPS.");
        break;
    case 3039:
        printf("Cogitate, Inc..");
        break;
    case 3040:
        printf("Tomato Springs.");
        break;
    case 3041:
        printf("di-traceware.");
        break;
    case 3042:
        printf("journee.");
        break;
    case 3043:
        printf("Broadcast Routing Protocol.");
        break;
    case 3044:
        printf("EndPoint Protocol.");
        break;
    case 3045:
        printf("ResponseNet.");
        break;
    case 3046:
        printf("di-ase.");
        break;
    case 3047:
        printf("Fast Security HL Server.");
        break;
    case 3048:
        printf("Sierra Net PC Trader.");
        break;
    case 3049:
        printf("NSWS.");
        break;
    case 3050:
        printf("gds_db.");
        break;
    case 3051:
        printf("Galaxy Server.");
        break;
    case 3052:
        printf("APC 3052.");
        break;
    case 3053:
        printf("dsom-server.");
        break;
    case 3054:
        printf("AMT CNF PROT.");
        break;
    case 3055:
        printf("Policy Server.");
        break;
    case 3056:
        printf("CDL Server.");
        break;
    case 3057:
        printf("GoAhead FldUp.");
        break;
    case 3058:
        printf("videobeans.");
        break;
    case 3059:
        printf("qsoft.");
        break;
    case 3060:
        printf("interserver.");
        break;
    case 3061:
        printf("cautcpd.");
        break;
    case 3062:
        printf("ncacn-ip-tcp.");
        break;
    case 3063:
        printf("ncadg-ip-udp.");
        break;
    case 3064:
        printf("Remote Port Redirector.");
        break;
    case 3065:
        printf("slinterbase.");
        break;
    case 3066:
        printf("NETATTACHSDMP.");
        break;
    case 3067:
        printf("FJHPJP.");
        break;
    case 3068:
        printf("ls3 Broadcast.");
        break;
    case 3069:
        printf("ls3.");
        break;
    case 3070:
        printf("MGXSWITCH.");
        break;
    case 3071:
        printf("Crossplatform replication protocol.");
        break;
    case 3072:
        printf("ContinuStor Monitor Port.");
        break;
    case 3073:
        printf("Very simple chatroom prot.");
        break;
    case 3074:
        printf("Xbox game port.");
        break;
    case 3075:
        printf("Orbix 2000 Locator.");
        break;
    case 3076:
        printf("Orbix 2000 Config.");
        break;
    case 3077:
        printf("Orbix 2000 Locator SSL.");
        break;
    case 3078:
        printf("Orbix 2000 Locator SSL.");
        break;
    case 3079:
        printf("LV Front Panel.");
        break;
    case 3080:
        printf("stm_pproc.");
        break;
    case 3081:
        printf("TL1-LV.");
        break;
    case 3082:
        printf("TL1-RAW.");
        break;
    case 3083:
        printf("TL1-TELNET.");
        break;
    case 3084:
        printf("ITM-MCCS.");
        break;
    case 3085:
        printf("PCIHReq.");
        break;
    case 3086:
        printf("JDL-DBKitchen.");
        break;
    case 3087:
        printf("Asoki SMA.");
        break;
    case 3088:
        printf("eXtensible Data Transfer Protocol.");
        break;
    case 3089:
        printf("ParaTek Agent Linking.");
        break;
    case 3090:
        printf("Senforce Session Services.");
        break;
    case 3091:
        printf("1Ci Server Management.");
        break;
    case 3093:
        printf("Jiiva RapidMQ Center.");
        break;
    case 3094:
        printf("Jiiva RapidMQ Registry.");
        break;
    case 3095:
        printf("Panasas rendezvous port.");
        break;
    case 3096:
        printf("Active Print Server Port.");
        break;
    case 3098:
        printf("Universal Message Manager.");
        break;
    case 3099:
        printf("CHIPSY Machine Daemon.");
        break;
    case 3100:
        printf("OpCon/xps.");
        break;
    case 3101:
        printf("HP PolicyXpert PIB Server.");
        break;
    case 3102:
        printf("SoftlinK Slave Mon Port.");
        break;
    case 3103:
        printf("Autocue SMI Protocol.");
        break;
    case 3104:
        printf("Autocue Logger Protocol.");
        break;
    case 3105:
        printf("Cardbox.");
        break;
    case 3106:
        printf("Cardbox HTTP.");
        break;
    case 3107:
        printf("Business protocol.");
        break;
    case 3108:
        printf("Geolocate protocol.");
        break;
    case 3109:
        printf("Personnel protocol.");
        break;
    case 3110:
        printf("simulator control port.");
        break;
    case 3111:
        printf("Web Synchronous Services.");
        break;
    case 3112:
        printf("KDE System Guard.");
        break;
    case 3113:
        printf("CS-Authenticate Svr Port.");
        break;
    case 3114:
        printf("CCM AutoDiscover.");
        break;
    case 3115:
        printf("MCTET Master.");
        break;
    case 3116:
        printf("MCTET Gateway.");
        break;
    case 3117:
        printf("MCTET Jserv.");
        break;
    case 3118:
        printf("PKAgent.");
        break;
    case 3119:
        printf("D2000 Kernel Port.");
        break;
    case 3120:
        printf("D2000 Webserver Port.");
        break;
    case 3121:
        printf("The pacemaker remote (pcmk-remote) service extends high availability functionality outside of the Linux cluster into remote nodes..");
        break;
    case 3122:
        printf("MTI VTR Emulator port.");
        break;
    case 3123:
        printf("EDI Translation Protocol.");
        break;
    case 3124:
        printf("Beacon Port.");
        break;
    case 3125:
        printf("A13-AN Interface.");
        break;
    case 3127:
        printf("CTX Bridge Port.");
        break;
    case 3128:
        printf("Active API Server Port.");
        break;
    case 3129:
        printf("NetPort Discovery Port.");
        break;
    case 3130:
        printf("ICPv2.");
        break;
    case 3131:
        printf("Net Book Mark.");
        break;
    case 3132:
        printf("Microsoft Business Rule Engine Update Service.");
        break;
    case 3133:
        printf("Prism Deploy User Port.");
        break;
    case 3134:
        printf("Extensible Code Protocol.");
        break;
    case 3135:
        printf("PeerBook Port.");
        break;
    case 3136:
        printf("Grub Server Port.");
        break;
    case 3137:
        printf("rtnt-1 data packets.");
        break;
    case 3138:
        printf("rtnt-2 data packets.");
        break;
    case 3139:
        printf("Incognito Rendez-Vous.");
        break;
    case 3140:
        printf("Arilia Multiplexor.");
        break;
    case 3141:
        printf("VMODEM.");
        break;
    case 3142:
        printf("RDC WH EOS.");
        break;
    case 3143:
        printf("Sea View.");
        break;
    case 3144:
        printf("Tarantella.");
        break;
    case 3145:
        printf("CSI-LFAP.");
        break;
    case 3146:
        printf("bears-02.");
        break;
    case 3147:
        printf("RFIO.");
        break;
    case 3148:
        printf("NetMike Game Administrator.");
        break;
    case 3149:
        printf("NetMike Game Server.");
        break;
    case 3150:
        printf("NetMike Assessor Administrator.");
        break;
    case 3151:
        printf("NetMike Assessor.");
        break;
    case 3152:
        printf("FeiTian Port.");
        break;
    case 3153:
        printf("S8Cargo Client Port.");
        break;
    case 3154:
        printf("ON RMI Registry.");
        break;
    case 3155:
        printf("JpegMpeg Port.");
        break;
    case 3156:
        printf("Indura Collector.");
        break;
    case 3157:
        printf("CCC Listener Port.");
        break;
    case 3158:
        printf("SmashTV Protocol.");
        break;
    case 3159:
        printf("NavegaWeb Tarification.");
        break;
    case 3160:
        printf("TIP Application Server.");
        break;
    case 3161:
        printf("DOC1 License Manager.");
        break;
    case 3162:
        printf("SFLM.");
        break;
    case 3163:
        printf("RES-SAP.");
        break;
    case 3164:
        printf("IMPRS.");
        break;
    case 3165:
        printf("Newgenpay Engine Service.");
        break;
    case 3166:
        printf("Quest Spotlight Out-Of-Process Collector.");
        break;
    case 3167:
        printf("Now Contact Public Server.");
        break;
    case 3168:
        printf("Now Up-to-Date Public Server.");
        break;
    case 3169:
        printf("SERVERVIEW-AS.");
        break;
    case 3170:
        printf("SERVERVIEW-ASN.");
        break;
    case 3171:
        printf("SERVERVIEW-GF.");
        break;
    case 3172:
        printf("SERVERVIEW-RM.");
        break;
    case 3173:
        printf("SERVERVIEW-ICC.");
        break;
    case 3174:
        printf("ARMI Server.");
        break;
    case 3175:
        printf("T1_E1_Over_IP.");
        break;
    case 3176:
        printf("ARS Master.");
        break;
    case 3177:
        printf("Phonex Protocol.");
        break;
    case 3178:
        printf("Radiance UltraEdge Port.");
        break;
    case 3179:
        printf("H2GF W.2m Handover prot..");
        break;
    case 3180:
        printf("Millicent Broker Server.");
        break;
    case 3181:
        printf("BMC Patrol Agent.");
        break;
    case 3182:
        printf("BMC Patrol Rendezvous.");
        break;
    case 3183:
        printf("COPS/TLS.");
        break;
    case 3184:
        printf("ApogeeX Port.");
        break;
    case 3185:
        printf("SuSE Meta PPPD.");
        break;
    case 3186:
        printf("IIW Monitor User Port.");
        break;
    case 3187:
        printf("Open Design Listen Port.");
        break;
    case 3188:
        printf("Broadcom Port.");
        break;
    case 3189:
        printf("Pinnacle Sys InfEx Port.");
        break;
    case 3190:
        printf("ConServR Proxy.");
        break;
    case 3191:
        printf("ConServR SSL Proxy.");
        break;
    case 3192:
        printf("FireMon Revision Control.");
        break;
    case 3193:
        printf("SpanDataPort.");
        break;
    case 3194:
        printf("Rockstorm MAG protocol.");
        break;
    case 3195:
        printf("Network Control Unit.");
        break;
    case 3196:
        printf("Network Control Unit.");
        break;
    case 3197:
        printf("Embrace Device Protocol Server.");
        break;
    case 3198:
        printf("Embrace Device Protocol Client.");
        break;
    case 3199:
        printf("DMOD WorkSpace.");
        break;
    case 3200:
        printf("Press-sense Tick Port.");
        break;
    case 3201:
        printf("CPQ-TaskSmart.");
        break;
    case 3202:
        printf("IntraIntra.");
        break;
    case 3203:
        printf("Network Watcher Monitor.");
        break;
    case 3204:
        printf("Network Watcher DB Access.");
        break;
    case 3205:
        printf("iSNS Server Port.");
        break;
    case 3206:
        printf("IronMail POP Proxy.");
        break;
    case 3207:
        printf("Veritas Authentication Port.");
        break;
    case 3208:
        printf("PFU PR Callback.");
        break;
    case 3209:
        printf("HP OpenView Network Path Engine Server.");
        break;
    case 3210:
        printf("Flamenco Networks Proxy.");
        break;
    case 3211:
        printf("Avocent Secure Management.");
        break;
    case 3212:
        printf("Survey Instrument.");
        break;
    case 3213:
        printf("NEON 24X7 Mission Control.");
        break;
    case 3214:
        printf("JMQ Daemon Port 1.");
        break;
    case 3215:
        printf("JMQ Daemon Port 2.");
        break;
    case 3216:
        printf("Ferrari electronic FOAM.");
        break;
    case 3217:
        printf("Unified IP & Telecom Environment.");
        break;
    case 3218:
        printf("EMC SmartPackets.");
        break;
    case 3219:
        printf("WMS Messenger.");
        break;
    case 3220:
        printf("XML NM over SSL.");
        break;
    case 3221:
        printf("XML NM over TCP.");
        break;
    case 3222:
        printf("Gateway Load Balancing Pr.");
        break;
    case 3223:
        printf("DIGIVOTE (R) Vote-Server.");
        break;
    case 3224:
        printf("AES Discovery Port.");
        break;
    case 3225:
        printf("FCIP.");
        break;
    case 3226:
        printf("ISI Industry Software IRP.");
        break;
    case 3227:
        printf("DiamondWave NMS Server.");
        break;
    case 3228:
        printf("DiamondWave MSG Server.");
        break;
    case 3229:
        printf("Global CD Port.");
        break;
    case 3230:
        printf("Software Distributor Port.");
        break;
    case 3231:
        printf("VidiGo communication (previous was: Delta Solutions Direct).");
        break;
    case 3232:
        printf("MDT port.");
        break;
    case 3233:
        printf("WhiskerControl main port.");
        break;
    case 3234:
        printf("Alchemy Server.");
        break;
    case 3235:
        printf("MDAP port.");
        break;
    case 3236:
        printf("appareNet Test Server.");
        break;
    case 3237:
        printf("appareNet Test Packet Sequencer.");
        break;
    case 3238:
        printf("appareNet Analysis Server.");
        break;
    case 3239:
        printf("appareNet User Interface.");
        break;
    case 3240:
        printf("Trio Motion Control Port.");
        break;
    case 3241:
        printf("SysOrb Monitoring Server.");
        break;
    case 3242:
        printf("Session Description ID.");
        break;
    case 3243:
        printf("Timelot Port.");
        break;
    case 3244:
        printf("OneSAF.");
        break;
    case 3245:
        printf("VIEO Fabric Executive.");
        break;
    case 3246:
        printf("DVT SYSTEM PORT.");
        break;
    case 3247:
        printf("DVT DATA LINK.");
        break;
    case 3248:
        printf("PROCOS LM.");
        break;
    case 3249:
        printf("State Sync Protocol.");
        break;
    case 3250:
        printf("HMS hicp port.");
        break;
    case 3251:
        printf("Sys Scanner.");
        break;
    case 3252:
        printf("DHE port.");
        break;
    case 3253:
        printf("PDA Data.");
        break;
    case 3254:
        printf("PDA System.");
        break;
    case 3255:
        printf("Semaphore Connection Port.");
        break;
    case 3256:
        printf("Compaq RPM Agent Port.");
        break;
    case 3257:
        printf("Compaq RPM Server Port.");
        break;
    case 3258:
        printf("Ivecon Server Port.");
        break;
    case 3259:
        printf("Epson Network Common Devi.");
        break;
    case 3260:
        printf("iSCSI port.");
        break;
    case 3261:
        printf("winShadow.");
        break;
    case 3262:
        printf("NECP.");
        break;
    case 3263:
        printf("E-Color Enterprise Imager.");
        break;
    case 3264:
        printf("cc:mail/lotus.");
        break;
    case 3265:
        printf("Altav Tunnel.");
        break;
    case 3266:
        printf("NS CFG Server.");
        break;
    case 3267:
        printf("IBM Dial Out.");
        break;
    case 3268:
        printf("Microsoft Global Catalog.");
        break;
    case 3269:
        printf("Microsoft Global Catalog with LDAP/SSL.");
        break;
    case 3270:
        printf("Verismart.");
        break;
    case 3271:
        printf("CSoft Prev Port.");
        break;
    case 3272:
        printf("Fujitsu User Manager.");
        break;
    case 3273:
        printf("Simple Extensible Multiplexed Protocol.");
        break;
    case 3274:
        printf("Ordinox Server.");
        break;
    case 3275:
        printf("SAMD.");
        break;
    case 3276:
        printf("Maxim ASICs.");
        break;
    case 3277:
        printf("AWG Proxy.");
        break;
    case 3278:
        printf("LKCM Server.");
        break;
    case 3279:
        printf("admind.");
        break;
    case 3280:
        printf("VS Server.");
        break;
    case 3281:
        printf("SYSOPT.");
        break;
    case 3282:
        printf("Datusorb.");
        break;
    case 3283:
        printf("Net Assistant.");
        break;
    case 3284:
        printf("4Talk.");
        break;
    case 3285:
        printf("Plato.");
        break;
    case 3286:
        printf("E-Net.");
        break;
    case 3287:
        printf("DIRECTVDATA.");
        break;
    case 3288:
        printf("COPS.");
        break;
    case 3289:
        printf("ENPC.");
        break;
    case 3290:
        printf("CAPS LOGISTICS TOOLKIT - LM.");
        break;
    case 3291:
        printf("S A Holditch & Associates - LM.");
        break;
    case 3292:
        printf("Cart O Rama.");
        break;
    case 3293:
        printf("fg-fps.");
        break;
    case 3294:
        printf("fg-gip.");
        break;
    case 3295:
        printf("Dynamic IP Lookup.");
        break;
    case 3296:
        printf("Rib License Manager.");
        break;
    case 3297:
        printf("Cytel License Manager.");
        break;
    case 3298:
        printf("DeskView.");
        break;
    case 3299:
        printf("pdrncs.");
        break;
    case 3300:
        printf("Ceph monitor.");
        break;
    case 3302:
        printf("MCS Fastmail.");
        break;
    case 3303:
        printf("OP Session Client.");
        break;
    case 3304:
        printf("OP Session Server.");
        break;
    case 3305:
        printf("ODETTE-FTP.");
        break;
    case 3306:
        printf("MySQL.");
        break;
    case 3307:
        printf("OP Session Proxy.");
        break;
    case 3308:
        printf("TNS Server.");
        break;
    case 3309:
        printf("TNS ADV.");
        break;
    case 3310:
        printf("Dyna Access.");
        break;
    case 3311:
        printf("MCNS Tel Ret.");
        break;
    case 3312:
        printf("Application Management Server.");
        break;
    case 3313:
        printf("Unify Object Broker.");
        break;
    case 3314:
        printf("Unify Object Host.");
        break;
    case 3315:
        printf("CDID.");
        break;
    case 3316:
        printf("AICC/CMI.");
        break;
    case 3317:
        printf("VSAI PORT.");
        break;
    case 3318:
        printf("Swith to Swith Routing Information Protocol.");
        break;
    case 3319:
        printf("SDT License Manager.");
        break;
    case 3320:
        printf("Office Link 2000.");
        break;
    case 3321:
        printf("VNSSTR.");
        break;
    case 3326:
        printf("SFTU.");
        break;
    case 3327:
        printf("BBARS.");
        break;
    case 3328:
        printf("Eaglepoint License Manager.");
        break;
    case 3329:
        printf("HP Device Disc.");
        break;
    case 3330:
        printf("MCS Calypso ICF.");
        break;
    case 3331:
        printf("MCS Messaging.");
        break;
    case 3332:
        printf("MCS Mail Server.");
        break;
    case 3333:
        printf("DEC Notes.");
        break;
    case 3334:
        printf("Direct TV Webcasting.");
        break;
    case 3335:
        printf("Direct TV Software Updates.");
        break;
    case 3336:
        printf("Direct TV Tickers.");
        break;
    case 3337:
        printf("Direct TV Data Catalog.");
        break;
    case 3338:
        printf("OMF data b.");
        break;
    case 3339:
        printf("OMF data l.");
        break;
    case 3340:
        printf("OMF data m.");
        break;
    case 3341:
        printf("OMF data h.");
        break;
    case 3342:
        printf("WebTIE.");
        break;
    case 3343:
        printf("MS Cluster Net.");
        break;
    case 3344:
        printf("BNT Manager.");
        break;
    case 3345:
        printf("Influence.");
        break;
    case 3346:
        printf("Trnsprnt Proxy.");
        break;
    case 3347:
        printf("Phoenix RPC.");
        break;
    case 3348:
        printf("Pangolin Laser.");
        break;
    case 3349:
        printf("Chevin Services.");
        break;
    case 3350:
        printf("FINDVIATV.");
        break;
    case 3351:
        printf("Btrieve port.");
        break;
    case 3352:
        printf("Scalable SQL.");
        break;
    case 3353:
        printf("FATPIPE.");
        break;
    case 3354:
        printf("SUITJD.");
        break;
    case 3355:
        printf("Ordinox Dbase.");
        break;
    case 3356:
        printf("UPNOTIFYPS.");
        break;
    case 3357:
        printf("Adtech Test IP.");
        break;
    case 3358:
        printf("Mp Sys Rmsvr.");
        break;
    case 3359:
        printf("WG NetForce.");
        break;
    case 3360:
        printf("KV Server.");
        break;
    case 3361:
        printf("KV Agent.");
        break;
    case 3362:
        printf("DJ ILM.");
        break;
    case 3363:
        printf("NATI Vi Server.");
        break;
    case 3364:
        printf("Creative Server.");
        break;
    case 3365:
        printf("Content Server.");
        break;
    case 3366:
        printf("Creative Partner.");
        break;
    case 3372:
        printf("TIP 2.");
        break;
    case 3373:
        printf("Lavenir License Manager.");
        break;
    case 3374:
        printf("Cluster Disc.");
        break;
    case 3375:
        printf("VSNM Agent.");
        break;
    case 3376:
        printf("CD Broker.");
        break;
    case 3377:
        printf("Cogsys Network License Manager.");
        break;
    case 3378:
        printf("WSICOPY.");
        break;
    case 3379:
        printf("SOCORFS.");
        break;
    case 3380:
        printf("SNS Channels.");
        break;
    case 3381:
        printf("Geneous.");
        break;
    case 3382:
        printf("Fujitsu Network Enhanced Antitheft function.");
        break;
    case 3383:
        printf("Enterprise Software Products License Manager.");
        break;
    case 3384:
        printf("Cluster Management Services.");
        break;
    case 3385:
        printf("qnxnetman.");
        break;
    case 3386:
        printf("GPRS Data.");
        break;
    case 3387:
        printf("Back Room Net.");
        break;
    case 3388:
        printf("CB Server.");
        break;
    case 3389:
        printf("MS WBT Server.");
        break;
    case 3390:
        printf("Distributed Service Coordinator.");
        break;
    case 3391:
        printf("SAVANT.");
        break;
    case 3392:
        printf("EFI License Management.");
        break;
    case 3393:
        printf("D2K Tapestry Client to Server.");
        break;
    case 3394:
        printf("D2K Tapestry Server to Server.");
        break;
    case 3395:
        printf("Dyna License Manager (Elam).");
        break;
    case 3396:
        printf("Printer Agent.");
        break;
    case 3397:
        printf("Cloanto License Manager.");
        break;
    case 3398:
        printf("Mercantile.");
        break;
    case 3399:
        printf("CSMS.");
        break;
    case 3400:
        printf("CSMS2.");
        break;
    case 3401:
        printf("filecast.");
        break;
    case 3402:
        printf("FXa Engine Network Port.");
        break;
    case 3405:
        printf("Nokia Announcement ch 1.");
        break;
    case 3406:
        printf("Nokia Announcement ch 2.");
        break;
    case 3407:
        printf("LDAP admin server port.");
        break;
    case 3408:
        printf("BES Api Port.");
        break;
    case 3409:
        printf("NetworkLens Event Port.");
        break;
    case 3410:
        printf("NetworkLens SSL Event.");
        break;
    case 3411:
        printf("BioLink Authenteon server.");
        break;
    case 3412:
        printf("xmlBlaster.");
        break;
    case 3413:
        printf("SpecView Networking.");
        break;
    case 3414:
        printf("BroadCloud WIP Port.");
        break;
    case 3415:
        printf("BCI Name Service.");
        break;
    case 3416:
        printf("AirMobile IS Command Port.");
        break;
    case 3417:
        printf("ConServR file translation.");
        break;
    case 3418:
        printf("Remote nmap.");
        break;
    case 3419:
        printf("Isogon SoftAudit.");
        break;
    case 3420:
        printf("iFCP User Port.");
        break;
    case 3421:
        printf("Bull Apprise portmapper.");
        break;
    case 3422:
        printf("Remote USB System Port.");
        break;
    case 3423:
        printf("xTrade Reliable Messaging.");
        break;
    case 3424:
        printf("xTrade over TLS/SSL.");
        break;
    case 3425:
        printf("AGPS Access Port.");
        break;
    case 3426:
        printf("Arkivio Storage Protocol.");
        break;
    case 3427:
        printf("WebSphere SNMP.");
        break;
    case 3428:
        printf("2Wire CSS.");
        break;
    case 3429:
        printf("GCSP user port.");
        break;
    case 3430:
        printf("Scott Studios Dispatch.");
        break;
    case 3431:
        printf("Active License Server Port.");
        break;
    case 3432:
        printf("Secure Device Protocol.");
        break;
    case 3433:
        printf("OPNET Service Management Platform.");
        break;
    case 3434:
        printf("OpenCM Server.");
        break;
    case 3435:
        printf("Pacom Security User Port.");
        break;
    case 3436:
        printf("GuardControl Exchange Protocol.");
        break;
    case 3437:
        printf("Autocue Directory Service.");
        break;
    case 3438:
        printf("Spiralcraft Admin.");
        break;
    case 3439:
        printf("HRI Interface Port.");
        break;
    case 3440:
        printf("Net Steward Mgmt Console.");
        break;
    case 3441:
        printf("OC Connect Client.");
        break;
    case 3442:
        printf("OC Connect Server.");
        break;
    case 3443:
        printf("OpenView Network Node Manager WEB Server.");
        break;
    case 3444:
        printf("Denali Server.");
        break;
    case 3445:
        printf("Media Object Network.");
        break;
    case 3446:
        printf("3Com FAX RPC port.");
        break;
    case 3447:
        printf("DirectNet IM System.");
        break;
    case 3448:
        printf("Discovery and Net Config.");
        break;
    case 3449:
        printf("HotU Chat.");
        break;
    case 3450:
        printf("CAStorProxy.");
        break;
    case 3451:
        printf("ASAM Services.");
        break;
    case 3452:
        printf("SABP-Signalling Protocol.");
        break;
    case 3453:
        printf("PSC Update.");
        break;
    case 3454:
        printf("Apple Remote Access Protocol.");
        break;
    case 3455:
        printf("RSVP Port.");
        break;
    case 3456:
        printf("VAT default data.");
        break;
    case 3457:
        printf("VAT default control.");
        break;
    case 3458:
        printf("D3WinOSFI.");
        break;
    case 3459:
        printf("TIP Integral.");
        break;
    case 3460:
        printf("EDM Manger.");
        break;
    case 3461:
        printf("EDM Stager.");
        break;
    case 3462:
        printf("EDM STD Notify.");
        break;
    case 3463:
        printf("EDM ADM Notify.");
        break;
    case 3464:
        printf("EDM MGR Sync.");
        break;
    case 3465:
        printf("EDM MGR Cntrl.");
        break;
    case 3466:
        printf("WORKFLOW.");
        break;
    case 3467:
        printf("RCST.");
        break;
    case 3468:
        printf("TTCM Remote Controll.");
        break;
    case 3469:
        printf("Pluribus.");
        break;
    case 3470:
        printf("jt400.");
        break;
    case 3471:
        printf("jt400-ssl.");
        break;
    case 3472:
        printf("JAUGS N-G Remotec 1.");
        break;
    case 3473:
        printf("JAUGS N-G Remotec 2.");
        break;
    case 3474:
        printf("TSP Automation.");
        break;
    case 3475:
        printf("Genisar Comm Port.");
        break;
    case 3476:
        printf("NVIDIA Mgmt Protocol.");
        break;
    case 3477:
        printf("eComm link port.");
        break;
    case 3478:
        printf("Session Traversal Utilities for NAT (STUN) port.");
        break;
    case 3479:
        printf("2Wire RPC.");
        break;
    case 3480:
        printf("Secure Virtual Workspace.");
        break;
    case 3481:
        printf("CleanerLive remote ctrl.");
        break;
    case 3482:
        printf("Vulture Monitoring System.");
        break;
    case 3483:
        printf("Slim Devices Protocol.");
        break;
    case 3484:
        printf("GBS SnapTalk Protocol.");
        break;
    case 3485:
        printf("CelaTalk.");
        break;
    case 3486:
        printf("IFSF Heartbeat Port.");
        break;
    case 3487:
        printf("LISA TCP Transfer Channel.");
        break;
    case 3488:
        printf("FS Remote Host Server.");
        break;
    case 3489:
        printf("DTP/DIA.");
        break;
    case 3490:
        printf("Colubris Management Port.");
        break;
    case 3491:
        printf("SWR Port.");
        break;
    case 3492:
        printf("TVDUM Tray Port.");
        break;
    case 3493:
        printf("Network UPS Tools.");
        break;
    case 3494:
        printf("IBM 3494.");
        break;
    case 3495:
        printf("securitylayer over tcp.");
        break;
    case 3496:
        printf("securitylayer over tls.");
        break;
    case 3497:
        printf("ipEther232Port.");
        break;
    case 3498:
        printf("DASHPAS user port.");
        break;
    case 3499:
        printf("SccIP Media.");
        break;
    case 3500:
        printf("RTMP Port.");
        break;
    case 3501:
        printf("iSoft-P2P.");
        break;
    case 3502:
        printf("Avocent Install Discovery.");
        break;
    case 3503:
        printf("MPLS LSP-echo Port.");
        break;
    case 3504:
        printf("IronStorm game server.");
        break;
    case 3505:
        printf("CCM communications port.");
        break;
    case 3506:
        printf("APC 3506.");
        break;
    case 3507:
        printf("Nesh Broker Port.");
        break;
    case 3508:
        printf("Interaction Web.");
        break;
    case 3509:
        printf("Virtual Token SSL Port.");
        break;
    case 3510:
        printf("XSS Port.");
        break;
    case 3511:
        printf("WebMail/2.");
        break;
    case 3512:
        printf("Aztec Distribution Port.");
        break;
    case 3513:
        printf("Adaptec Remote Protocol.");
        break;
    case 3514:
        printf("MUST Peer to Peer.");
        break;
    case 3515:
        printf("MUST Backplane.");
        break;
    case 3516:
        printf("Smartcard Port.");
        break;
    case 3517:
        printf("IEEE 802.11 WLANs WG IAPP.");
        break;
    case 3518:
        printf("Artifact Message Server.");
        break;
    case 3519:
        printf("Netvion Messenger Port.");
        break;
    case 3520:
        printf("Netvion Galileo Log Port.");
        break;
    case 3521:
        printf("Telequip Labs MC3SS.");
        break;
    case 3522:
        printf("DO over NSSocketPort.");
        break;
    case 3523:
        printf("Odeum Serverlink.");
        break;
    case 3524:
        printf("ECM Server port.");
        break;
    case 3525:
        printf("EIS Server port.");
        break;
    case 3526:
        printf("starQuiz Port.");
        break;
    case 3527:
        printf("VERITAS Backup Exec Server.");
        break;
    case 3528:
        printf("JBoss IIOP.");
        break;
    case 3529:
        printf("JBoss IIOP/SSL.");
        break;
    case 3530:
        printf("Grid Fristd::endly.");
        break;
    case 3531:
        printf("Joltid.");
        break;
    case 3532:
        printf("Raven Remote Management Control.");
        break;
    case 3533:
        printf("Raven Remote Management Data.");
        break;
    case 3534:
        printf("URL Daemon Port.");
        break;
    case 3535:
        printf("MS-LA.");
        break;
    case 3536:
        printf("SNAC.");
        break;
    case 3537:
        printf("Remote NI-VISA port.");
        break;
    case 3538:
        printf("IBM Directory Server.");
        break;
    case 3539:
        printf("IBM Directory Server SSL.");
        break;
    case 3540:
        printf("PNRP User Port.");
        break;
    case 3541:
        printf("VoiSpeed Port.");
        break;
    case 3542:
        printf("HA cluster monitor.");
        break;
    case 3543:
        printf("qftest Lookup Port.");
        break;
    case 3544:
        printf("Teredo Port.");
        break;
    case 3545:
        printf("CAMAC equipment.");
        break;
    case 3547:
        printf("Symantec SIM.");
        break;
    case 3548:
        printf("Interworld.");
        break;
    case 3549:
        printf("Tellumat MDR NMS.");
        break;
    case 3550:
        printf("Secure SMPP.");
        break;
    case 3551:
        printf("Apcupsd Information Port.");
        break;
    case 3552:
        printf("TeamAgenda Server Port.");
        break;
    case 3553:
        printf("Red Box Recorder ADP.");
        break;
    case 3554:
        printf("Quest Notification Server.");
        break;
    case 3555:
        printf("Vipul's Razor.");
        break;
    case 3556:
        printf("Sky Transport Protocol.");
        break;
    case 3557:
        printf("PersonalOS Comm Port.");
        break;
    case 3558:
        printf("MCP user port.");
        break;
    case 3559:
        printf("CCTV control port.");
        break;
    case 3560:
        printf("INIServe port.");
        break;
    case 3561:
        printf("BMC-OneKey.");
        break;
    case 3562:
        printf("SDBProxy.");
        break;
    case 3563:
        printf("Watcom Debug.");
        break;
    case 3564:
        printf("Electromed SIM port.");
        break;
    case 3565:
        printf("M2PA.");
        break;
    case 3566:
        printf("Quest Data Hub.");
        break;
    case 3567:
        printf("DOF Protocol Stack.");
        break;
    case 3568:
        printf("DOF Secure Tunnel.");
        break;
    case 3569:
        printf("Meinberg Control Service.");
        break;
    case 3570:
        printf("MCC Web Server Port.");
        break;
    case 3571:
        printf("MegaRAID Server Port.");
        break;
    case 3572:
        printf("Registration Server Port.");
        break;
    case 3573:
        printf("Advantage Group UPS Suite.");
        break;
    case 3574:
        printf("DMAF Server.");
        break;
    case 3575:
        printf("Coalsere CCM Port.");
        break;
    case 3576:
        printf("Coalsere CMC Port.");
        break;
    case 3577:
        printf("Configuration Port.");
        break;
    case 3578:
        printf("Data Port.");
        break;
    case 3579:
        printf("Tarantella Load Balancing.");
        break;
    case 3580:
        printf("NATI-ServiceLocator.");
        break;
    case 3581:
        printf("Ascent Capture Licensing.");
        break;
    case 3582:
        printf("PEG PRESS Server.");
        break;
    case 3583:
        printf("CANEX Watch System.");
        break;
    case 3584:
        printf("U-DBase Access Protocol.");
        break;
    case 3585:
        printf("Emprise License Server.");
        break;
    case 3586:
        printf("License Server Console.");
        break;
    case 3587:
        printf("Peer to Peer Grouping.");
        break;
    case 3588:
        printf("Sentinel Server.");
        break;
    case 3589:
        printf("isomair.");
        break;
    case 3590:
        printf("WV CSP SMS Binding.");
        break;
    case 3591:
        printf("LOCANIS G-TRACK Server.");
        break;
    case 3592:
        printf("LOCANIS G-TRACK NE Port.");
        break;
    case 3593:
        printf("BP Model Debugger.");
        break;
    case 3594:
        printf("MediaSpace.");
        break;
    case 3595:
        printf("ShareApp.");
        break;
    case 3596:
        printf("Illusion Wireless MMOG.");
        break;
    case 3597:
        printf("A14 (AN-to-SC/MM).");
        break;
    case 3598:
        printf("A15 (AN-to-AN).");
        break;
    case 3599:
        printf("Quasar Accounting Server.");
        break;
    case 3600:
        printf("text relay-answer.");
        break;
    case 3601:
        printf("Visinet Gui.");
        break;
    case 3602:
        printf("InfiniSwitch Mgr Client.");
        break;
    case 3603:
        printf("Integrated Rcvr Control.");
        break;
    case 3604:
        printf("BMC JMX Port.");
        break;
    case 3605:
        printf("ComCam IO Port.");
        break;
    case 3606:
        printf("Splitlock Server.");
        break;
    case 3607:
        printf("Precise I3.");
        break;
    case 3608:
        printf("Trendchip control protocol.");
        break;
    case 3609:
        printf("CPDI PIDAS Connection Mon.");
        break;
    case 3610:
        printf("ECHONET.");
        break;
    case 3611:
        printf("Six Degrees Port.");
        break;
    case 3612:
        printf("HP Data Protector.");
        break;
    case 3613:
        printf("Alaris Device Discovery.");
        break;
    case 3614:
        printf("Satchwell Sigma.");
        break;
    case 3615:
        printf("Start Messaging Network.");
        break;
    case 3616:
        printf("cd3o Control Protocol.");
        break;
    case 3617:
        printf("ATI SHARP Logic Engine.");
        break;
    case 3618:
        printf("AAIR-Network 1.");
        break;
    case 3619:
        printf("AAIR-Network 2.");
        break;
    case 3620:
        printf("EPSON Projector Control Port.");
        break;
    case 3621:
        printf("EPSON Network Screen Port.");
        break;
    case 3622:
        printf("FF LAN Redundancy Port.");
        break;
    case 3623:
        printf("HAIPIS Dynamic Discovery.");
        break;
    case 3624:
        printf("Distributed Upgrade Port.");
        break;
    case 3625:
        printf("Volley.");
        break;
    case 3626:
        printf("bvControl Daemon.");
        break;
    case 3627:
        printf("Jam Server Port.");
        break;
    case 3628:
        printf("EPT Machine Interface.");
        break;
    case 3629:
        printf("ESC/VP.net.");
        break;
    case 3630:
        printf("C&S Remote Database Port.");
        break;
    case 3631:
        printf("C&S Web Services Port.");
        break;
    case 3632:
        printf("distributed compiler.");
        break;
    case 3633:
        printf("Wyrnix AIS port.");
        break;
    case 3634:
        printf("hNTSP Library Manager.");
        break;
    case 3635:
        printf("Simple Distributed Objects.");
        break;
    case 3636:
        printf("SerVistaITSM.");
        break;
    case 3637:
        printf("Customer Service Port.");
        break;
    case 3638:
        printf("EHP Backup Protocol.");
        break;
    case 3639:
        printf("Extensible Automation.");
        break;
    case 3640:
        printf("Netplay Port 1.");
        break;
    case 3641:
        printf("Netplay Port 2.");
        break;
    case 3642:
        printf("Juxml Replication port.");
        break;
    case 3643:
        printf("AudioJuggler.");
        break;
    case 3644:
        printf("ssowatch.");
        break;
    case 3645:
        printf("Cyc.");
        break;
    case 3646:
        printf("XSS Server Port.");
        break;
    case 3647:
        printf("Splitlock Gateway.");
        break;
    case 3648:
        printf("Fujitsu Cooperation Port.");
        break;
    case 3649:
        printf("Nishioka Miyuki Msg Protocol.");
        break;
    case 3650:
        printf("PRISMIQ VOD plug-in.");
        break;
    case 3651:
        printf("XRPC Registry.");
        break;
    case 3652:
        printf("VxCR NBU Default Port.");
        break;
    case 3653:
        printf("Tunnel Setup Protocol.");
        break;
    case 3654:
        printf("VAP RealTime Messenger.");
        break;
    case 3655:
        printf("ActiveBatch Exec Agent.");
        break;
    case 3656:
        printf("ActiveBatch Job Scheduler.");
        break;
    case 3657:
        printf("ImmediaNet Beacon.");
        break;
    case 3658:
        printf("PlayStation AMS (Secure).");
        break;
    case 3659:
        printf("Apple SASL.");
        break;
    case 3660:
        printf("IBM Tivoli Directory Service using SSL.");
        break;
    case 3661:
        printf("IBM Tivoli Directory Service using SSL.");
        break;
    case 3662:
        printf("pserver.");
        break;
    case 3663:
        printf("DIRECWAY Tunnel Protocol.");
        break;
    case 3664:
        printf("UPS Engine Port.");
        break;
    case 3665:
        printf("Enterprise Engine Port.");
        break;
    case 3666:
        printf("IBM eServer PAP.");
        break;
    case 3667:
        printf("IBM Information Exchange.");
        break;
    case 3668:
        printf("Dell Remote Management.");
        break;
    case 3669:
        printf("CA SAN Switch Management.");
        break;
    case 3670:
        printf("SMILE TCP/UDP Interface.");
        break;
    case 3671:
        printf("e Field Control (EIBnet).");
        break;
    case 3672:
        printf("LispWorks ORB.");
        break;
    case 3673:
        printf("Openview Media Vault GUI.");
        break;
    case 3674:
        printf("WinINSTALL IPC Port.");
        break;
    case 3675:
        printf("CallTrax Data Port.");
        break;
    case 3676:
        printf("VisualAge Pacbase server.");
        break;
    case 3677:
        printf("RoverLog IPC.");
        break;
    case 3678:
        printf("DataGuardianLT.");
        break;
    case 3679:
        printf("Newton Dock.");
        break;
    case 3680:
        printf("NPDS Tracker.");
        break;
    case 3681:
        printf("BTS X73 Port.");
        break;
    case 3682:
        printf("EMC SmartPackets-MAPI.");
        break;
    case 3683:
        printf("BMC EDV/EA.");
        break;
    case 3684:
        printf("FAXstfX.");
        break;
    case 3685:
        printf("DS Expert Agent.");
        break;
    case 3686:
        printf("Trivial Network Management.");
        break;
    case 3687:
        printf("simple-push.");
        break;
    case 3688:
        printf("simple-push Secure.");
        break;
    case 3689:
        printf("Digital Audio Access Protocol (iTunes).");
        break;
    case 3690:
        printf("Subversion.");
        break;
    case 3691:
        printf("Magaya Network Port.");
        break;
    case 3692:
        printf("Brimstone IntelSync.");
        break;
    case 3693:
        printf("Emergency Automatic Structure Lockdown System.");
        break;
    case 3695:
        printf("BMC Data Collection.");
        break;
    case 3696:
        printf("Telnet Com Port Control.");
        break;
    case 3697:
        printf("NavisWorks License System.");
        break;
    case 3698:
        printf("SAGECTLPANEL.");
        break;
    case 3699:
        printf("Internet Call Waiting.");
        break;
    case 3700:
        printf("LRS NetPage.");
        break;
    case 3701:
        printf("NetCelera.");
        break;
    case 3702:
        printf("Web Service Discovery.");
        break;
    case 3703:
        printf("Adobe Server 3.");
        break;
    case 3704:
        printf("Adobe Server 4.");
        break;
    case 3705:
        printf("Adobe Server 5.");
        break;
    case 3706:
        printf("Real-Time Event Port.");
        break;
    case 3707:
        printf("Real-Time Event Secure Port.");
        break;
    case 3708:
        printf("Sun App Svr - Naming.");
        break;
    case 3709:
        printf("CA-IDMS Server.");
        break;
    case 3710:
        printf("PortGate Authentication.");
        break;
    case 3711:
        printf("EBD Server 2.");
        break;
    case 3712:
        printf("Sentinel Enterprise.");
        break;
    case 3713:
        printf("TFTP over TLS.");
        break;
    case 3714:
        printf("DELOS Direct Messaging.");
        break;
    case 3715:
        printf("Anoto Rendezvous Port.");
        break;
    case 3716:
        printf("WV CSP SMS CIR Channel.");
        break;
    case 3717:
        printf("WV CSP UDP/IP CIR Channel.");
        break;
    case 3718:
        printf("OPUS Server Port.");
        break;
    case 3719:
        printf("iTel Server Port.");
        break;
    case 3720:
        printf("UF Astro. Instr. Services.");
        break;
    case 3721:
        printf("Xsync.");
        break;
    case 3722:
        printf("Xserve RAID.");
        break;
    case 3723:
        printf("Sychron Service Daemon.");
        break;
    case 3724:
        printf("World of Warcraft.");
        break;
    case 3725:
        printf("Netia NA-ER Port.");
        break;
    case 3726:
        printf("Xyratex Array Manager.");
        break;
    case 3727:
        printf("Ericsson Mobile Data Unit.");
        break;
    case 3728:
        printf("Ericsson Web on Air.");
        break;
    case 3729:
        printf("Fireking Audit Port.");
        break;
    case 3730:
        printf("Client Control.");
        break;
    case 3731:
        printf("Service Manager.");
        break;
    case 3732:
        printf("Mobile Wnn.");
        break;
    case 3733:
        printf("Multipuesto Msg Port.");
        break;
    case 3734:
        printf("Synel Data Collection Port.");
        break;
    case 3735:
        printf("Password Distribution.");
        break;
    case 3736:
        printf("RealSpace RMI.");
        break;
    case 3737:
        printf("XPanel Daemon.");
        break;
    case 3738:
        printf("versaTalk Server Port.");
        break;
    case 3739:
        printf("Launchbird LicenseManager.");
        break;
    case 3740:
        printf("Heartbeat Protocol.");
        break;
    case 3741:
        printf("WysDM Agent.");
        break;
    case 3742:
        printf("CST - Configuration & Service Tracker.");
        break;
    case 3743:
        printf("IP Control Systems Ltd..");
        break;
    case 3744:
        printf("SASG.");
        break;
    case 3745:
        printf("GWRTC Call Port.");
        break;
    case 3746:
        printf("LXPRO.COM LinkTest.");
        break;
    case 3747:
        printf("LXPRO.COM LinkTest SSL.");
        break;
    case 3748:
        printf("webData.");
        break;
    case 3749:
        printf("CimTrak.");
        break;
    case 3750:
        printf("CBOS/IP ncapsalation port.");
        break;
    case 3751:
        printf("CommLinx GPRS Cube.");
        break;
    case 3752:
        printf("Vigil-IP RemoteAgent.");
        break;
    case 3753:
        printf("NattyServer Port.");
        break;
    case 3754:
        printf("TimesTen Broker Port.");
        break;
    case 3755:
        printf("SAS Remote Help Server.");
        break;
    case 3756:
        printf("Canon CAPT Port.");
        break;
    case 3757:
        printf("GRF Server Port.");
        break;
    case 3758:
        printf("apw RMI registry.");
        break;
    case 3759:
        printf("Exapt License Manager.");
        break;
    case 3760:
        printf("adTempus Client.");
        break;
    case 3761:
        printf("gsakmp port.");
        break;
    case 3762:
        printf("GBS SnapMail Protocol.");
        break;
    case 3763:
        printf("XO Wave Control Port.");
        break;
    case 3764:
        printf("MNI Protected Routing.");
        break;
    case 3765:
        printf("Remote Traceroute.");
        break;
    case 3766:
        printf("SSL e-watch sitewatch server.");
        break;
    case 3767:
        printf("ListMGR Port.");
        break;
    case 3768:
        printf("rblcheckd server daemon.");
        break;
    case 3769:
        printf("HAIPE Network Keying.");
        break;
    case 3770:
        printf("Cinderella Collaboration.");
        break;
    case 3771:
        printf("RTP Paging Port.");
        break;
    case 3772:
        printf("Chantry Tunnel Protocol.");
        break;
    case 3773:
        printf("ctdhercules.");
        break;
    case 3774:
        printf("ZICOM.");
        break;
    case 3775:
        printf("ISPM Manager Port.");
        break;
    case 3776:
        printf("Device Provisioning Port.");
        break;
    case 3777:
        printf("Jibe EdgeBurst.");
        break;
    case 3778:
        printf("Cutler-Hammer IT Port.");
        break;
    case 3779:
        printf("Cognima Replication.");
        break;
    case 3780:
        printf("Nuzzler Network Protocol.");
        break;
    case 3781:
        printf("ABCvoice server port.");
        break;
    case 3782:
        printf("Secure ISO TP0 port.");
        break;
    case 3783:
        printf("Impact Mgr./PEM Gateway.");
        break;
    case 3784:
        printf("BFD Control Protocol.");
        break;
    case 3785:
        printf("BFD Echo Protocol.");
        break;
    case 3786:
        printf("VSW Upstrigger port.");
        break;
    case 3787:
        printf("Fintrx.");
        break;
    case 3788:
        printf("SPACEWAY Routing port.");
        break;
    case 3789:
        printf("RemoteDeploy Administration Port [July 2003].");
        break;
    case 3790:
        printf("QuickBooks RDS.");
        break;
    case 3791:
        printf("TV NetworkVideo Data port.");
        break;
    case 3792:
        printf("e-Watch Corporation SiteWatch.");
        break;
    case 3793:
        printf("DataCore Software.");
        break;
    case 3794:
        printf("JAUS Robots.");
        break;
    case 3795:
        printf("myBLAST Mekentosj port.");
        break;
    case 3796:
        printf("Spaceway Dialer.");
        break;
    case 3797:
        printf("idps.");
        break;
    case 3798:
        printf("Minilock.");
        break;
    case 3799:
        printf("RADIUS Dynamic Authorization.");
        break;
    case 3800:
        printf("Print Services Interface.");
        break;
    case 3801:
        printf("ibm manager service.");
        break;
    case 3802:
        printf("VHD.");
        break;
    case 3803:
        printf("SoniqSync.");
        break;
    case 3804:
        printf("Harman IQNet Port.");
        break;
    case 3805:
        printf("ThorGuard Server Port.");
        break;
    case 3806:
        printf("Remote System Manager.");
        break;
    case 3807:
        printf("SpuGNA Communication Port.");
        break;
    case 3808:
        printf("Sun App Svr-IIOPClntAuth.");
        break;
    case 3809:
        printf("Java Desktop System Configuration Agent.");
        break;
    case 3810:
        printf("WLAN AS server.");
        break;
    case 3811:
        printf("AMP.");
        break;
    case 3812:
        printf("netO WOL Server.");
        break;
    case 3813:
        printf("Rhapsody Interface Protocol.");
        break;
    case 3814:
        printf("netO DCS.");
        break;
    case 3815:
        printf("LANsurveyor XML.");
        break;
    case 3816:
        printf("Sun Local Patch Server.");
        break;
    case 3817:
        printf("Yosemite Tech Tapeware.");
        break;
    case 3818:
        printf("Crinis Heartbeat.");
        break;
    case 3819:
        printf("EPL Sequ Layer Protocol.");
        break;
    case 3820:
        printf("Siemens AuD SCP.");
        break;
    case 3821:
        printf("ATSC PMCP Standard.");
        break;
    case 3822:
        printf("Compute Pool Discovery.");
        break;
    case 3823:
        printf("Compute Pool Conduit.");
        break;
    case 3824:
        printf("Compute Pool Policy.");
        break;
    case 3825:
        printf("Antera FlowFusion Process Simulation.");
        break;
    case 3826:
        printf("WarMUX game server.");
        break;
    case 3827:
        printf("Netadmin Systems MPI service.");
        break;
    case 3828:
        printf("Netadmin Systems Event Handler.");
        break;
    case 3829:
        printf("Netadmin Systems Event Handler External.");
        break;
    case 3830:
        printf("Cerner System Management Agent.");
        break;
    case 3831:
        printf("Docsvault Application Service.");
        break;
    case 3832:
        printf("xxNETserver.");
        break;
    case 3833:
        printf("AIPN LS Authentication.");
        break;
    case 3834:
        printf("Spectar Data Stream Service.");
        break;
    case 3835:
        printf("Spectar Database Rights Service.");
        break;
    case 3836:
        printf("MARKEM NEXTGEN DCP.");
        break;
    case 3837:
        printf("MARKEM Auto-Discovery.");
        break;
    case 3838:
        printf("Scito Object Server.");
        break;
    case 3839:
        printf("AMX Resource Management Suite.");
        break;
    case 3840:
        printf("www.FlirtMitMir.de.");
        break;
    case 3841:
        printf("ShipRush Database Server.");
        break;
    case 3842:
        printf("NHCI status port.");
        break;
    case 3843:
        printf("Quest Common Agent.");
        break;
    case 3844:
        printf("RNM.");
        break;
    case 3845:
        printf("V-ONE Single Port Proxy.");
        break;
    case 3846:
        printf("Astare Network PCP.");
        break;
    case 3847:
        printf("MS Firewall Control.");
        break;
    case 3848:
        printf("IT Environmental Monitor.");
        break;
    case 3849:
        printf("SPACEWAY DNS Preload.");
        break;
    case 3850:
        printf("QTMS Bootstrap Protocol.");
        break;
    case 3851:
        printf("SpectraTalk Port.");
        break;
    case 3852:
        printf("SSE App Configuration.");
        break;
    case 3853:
        printf("SONY scanning protocol.");
        break;
    case 3854:
        printf("Stryker Comm Port.");
        break;
    case 3855:
        printf("OpenTRAC.");
        break;
    case 3856:
        printf("INFORMER.");
        break;
    case 3857:
        printf("Trap Port.");
        break;
    case 3858:
        printf("Trap Port MOM.");
        break;
    case 3859:
        printf("Navini Port.");
        break;
    case 3860:
        printf("Server/Application State Protocol (SASP).");
        break;
    case 3861:
        printf("winShadow Host Discovery.");
        break;
    case 3862:
        printf("GIGA-POCKET.");
        break;
    case 3863:
        printf("asap tcp port.");
        break;
    case 3864:
        printf("asap/tls tcp port.");
        break;
    case 3865:
        printf("xpl automation protocol.");
        break;
    case 3866:
        printf("Sun SDViz DZDAEMON Port.");
        break;
    case 3867:
        printf("Sun SDViz DZOGLSERVER Port.");
        break;
    case 3868:
        printf("DIAMETER.");
        break;
    case 3869:
        printf("hp OVSAM MgmtServer Disco.");
        break;
    case 3870:
        printf("hp OVSAM HostAgent Disco.");
        break;
    case 3871:
        printf("Avocent DS Authorization.");
        break;
    case 3872:
        printf("OEM Agent.");
        break;
    case 3873:
        printf("fagordnc.");
        break;
    case 3874:
        printf("SixXS Configuration.");
        break;
    case 3875:
        printf("PNBSCADA.");
        break;
    case 3876:
        printf("DirectoryLockdown Agent.");
        break;
    case 3877:
        printf("XMPCR Interface Port.");
        break;
    case 3878:
        printf("FotoG CAD interface.");
        break;
    case 3879:
        printf("appss license manager.");
        break;
    case 3880:
        printf("IGRS.");
        break;
    case 3881:
        printf("Data Acquisition and Control.");
        break;
    case 3882:
        printf("DTS Service Port.");
        break;
    case 3883:
        printf("VR Peripheral Network.");
        break;
    case 3884:
        printf("SofTrack Metering.");
        break;
    case 3885:
        printf("TopFlow SSL.");
        break;
    case 3886:
        printf("NEI management port.");
        break;
    case 3887:
        printf("Ciphire Data Transport.");
        break;
    case 3888:
        printf("Ciphire Services.");
        break;
    case 3889:
        printf("D and V Tester Control Port.");
        break;
    case 3890:
        printf("Niche Data Server Connect.");
        break;
    case 3891:
        printf("Oracle RTC-PM port.");
        break;
    case 3892:
        printf("PCC-image-port.");
        break;
    case 3893:
        printf("CGI StarAPI Server.");
        break;
    case 3894:
        printf("SyAM Agent Port.");
        break;
    case 3895:
        printf("SyAm SMC Service Port.");
        break;
    case 3896:
        printf("Simple Distributed Objects over TLS.");
        break;
    case 3897:
        printf("Simple Distributed Objects over SSH.");
        break;
    case 3898:
        printf("IAS, Inc. SmartEye NET Internet Protocol.");
        break;
    case 3899:
        printf("ITV Port.");
        break;
    case 3900:
        printf("Unidata UDT OS.");
        break;
    case 3901:
        printf("NIM Service Handler.");
        break;
    case 3902:
        printf("NIMsh Auxiliary Port.");
        break;
    case 3903:
        printf("CharsetMGR.");
        break;
    case 3904:
        printf("Arnet Omnilink Port.");
        break;
    case 3905:
        printf("Mailbox Update (MUPDATE) protocol.");
        break;
    case 3906:
        printf("TopoVista elevation data.");
        break;
    case 3907:
        printf("Imoguia Port.");
        break;
    case 3908:
        printf("HP Procurve NetManagement.");
        break;
    case 3909:
        printf("SurfControl CPA.");
        break;
    case 3910:
        printf("Printer Request Port.");
        break;
    case 3911:
        printf("Printer Status Port.");
        break;
    case 3912:
        printf("Global Maintech Stars.");
        break;
    case 3913:
        printf("ListCREATOR Port.");
        break;
    case 3914:
        printf("ListCREATOR Port 2.");
        break;
    case 3915:
        printf("Auto-Graphics Cataloging.");
        break;
    case 3916:
        printf("WysDM Controller.");
        break;
    case 3917:
        printf("AFT multiplex port.");
        break;
    case 3918:
        printf("PacketCableMultimediaCOPS.");
        break;
    case 3919:
        printf("HyperIP.");
        break;
    case 3920:
        printf("Exasoft IP Port.");
        break;
    case 3921:
        printf("Herodotus Net.");
        break;
    case 3922:
        printf("Soronti Update Port.");
        break;
    case 3923:
        printf("Symbian Service Broker.");
        break;
    case 3924:
        printf("MPL_GPRS_PORT.");
        break;
    case 3925:
        printf("Zoran Media Port.");
        break;
    case 3926:
        printf("WINPort.");
        break;
    case 3927:
        printf("ScsTsr.");
        break;
    case 3928:
        printf("PXE NetBoot Manager.");
        break;
    case 3929:
        printf("AMS Port.");
        break;
    case 3930:
        printf("Syam Web Server Port.");
        break;
    case 3931:
        printf("MSR Plugin Port.");
        break;
    case 3932:
        printf("Dynamic Site System.");
        break;
    case 3933:
        printf("PL/B App Server User Port.");
        break;
    case 3934:
        printf("PL/B File Manager Port.");
        break;
    case 3935:
        printf("SDP Port Mapper Protocol.");
        break;
    case 3936:
        printf("Mailprox.");
        break;
    case 3937:
        printf("DVB Service Discovery.");
        break;
    case 3938:
        printf("Oracle dbControl Agent po.");
        break;
    case 3939:
        printf("Anti-virus Application Management Port.");
        break;
    case 3940:
        printf("XeCP Node Service.");
        break;
    case 3941:
        printf("Home Portal Web Server.");
        break;
    case 3942:
        printf("satellite distribution.");
        break;
    case 3943:
        printf("TetraNode Ip Gateway.");
        break;
    case 3944:
        printf("S-Ops Management.");
        break;
    case 3945:
        printf("EMCADS Server Port.");
        break;
    case 3946:
        printf("BackupEDGE Server.");
        break;
    case 3947:
        printf("Connect and Control Protocol for Consumer, Commercial, and Industrial Electronic Devices.");
        break;
    case 3948:
        printf("Anton Paar Device Administration Protocol.");
        break;
    case 3949:
        printf("Dynamic Routing Information Protocol.");
        break;
    case 3950:
        printf("Name Munging.");
        break;
    case 3951:
        printf("PWG IPP Facsimile.");
        break;
    case 3952:
        printf("I3 Session Manager.");
        break;
    case 3953:
        printf("Eydeas XMLink Connect.");
        break;
    case 3954:
        printf("AD Replication RPC.");
        break;
    case 3955:
        printf("p2pCommunity.");
        break;
    case 3956:
        printf("GigE Vision Control.");
        break;
    case 3957:
        printf("MQEnterprise Broker.");
        break;
    case 3958:
        printf("MQEnterprise Agent.");
        break;
    case 3959:
        printf("Tree Hopper Networking.");
        break;
    case 3960:
        printf("Bess Peer Assessment.");
        break;
    case 3961:
        printf("ProAxess Server.");
        break;
    case 3962:
        printf("SBI Agent Protocol.");
        break;
    case 3963:
        printf("Teran Hybrid Routing Protocol.");
        break;
    case 3964:
        printf("SASG GPRS.");
        break;
    case 3965:
        printf("Avanti IP to NCPE API.");
        break;
    case 3966:
        printf("BuildForge Lock Manager.");
        break;
    case 3967:
        printf("PPS Message Service.");
        break;
    case 3968:
        printf("iAnywhere DBNS.");
        break;
    case 3969:
        printf("Landmark Messages.");
        break;
    case 3970:
        printf("LANrev Agent.");
        break;
    case 3971:
        printf("LANrev Server.");
        break;
    case 3972:
        printf("ict-control Protocol.");
        break;
    case 3973:
        printf("ConnectShip Progistics.");
        break;
    case 3974:
        printf("Remote Applicant Tracking Service.");
        break;
    case 3975:
        printf("Air Shot.");
        break;
    case 3976:
        printf("Server Automation Agent.");
        break;
    case 3977:
        printf("Opsware Manager.");
        break;
    case 3978:
        printf("Secured Configuration Server.");
        break;
    case 3979:
        printf("Smith Micro Wide Area Network Service.");
        break;
    case 3980:
        printf("Aircraft Cabin Management System.");
        break;
    case 3981:
        printf("Starfish System Admin.");
        break;
    case 3982:
        printf("ESRI Image Server.");
        break;
    case 3983:
        printf("ESRI Image Service.");
        break;
    case 3984:
        printf("MAPPER network node manager.");
        break;
    case 3985:
        printf("MAPPER TCP/IP server.");
        break;
    case 3986:
        printf("MAPPER workstation server.");
        break;
    case 3987:
        printf("Centerline.");
        break;
    case 3988:
        printf("DCS Configuration Port.");
        break;
    case 3989:
        printf("BindView-Query Engine.");
        break;
    case 3990:
        printf("BindView-IS.");
        break;
    case 3991:
        printf("BindView-SMCServer.");
        break;
    case 3992:
        printf("BindView-DirectoryServer.");
        break;
    case 3993:
        printf("BindView-Agent.");
        break;
    case 3995:
        printf("ISS Management Svcs SSL.");
        break;
    case 3996:
        printf("abcsoftware-01.");
        break;
    case 3997:
        printf("aes_db.");
        break;
    case 3998:
        printf("Distributed Nagios Executor Service.");
        break;
    case 3999:
        printf("Norman distributes scanning service.");
        break;
    case 4000:
        printf("Terabase.");
        break;
    case 4001:
        printf("NewOak.");
        break;
    case 4002:
        printf("pxc-spvr-ft.");
        break;
    case 4003:
        printf("pxc-splr-ft.");
        break;
    case 4004:
        printf("pxc-roid.");
        break;
    case 4005:
        printf("pxc-pin.");
        break;
    case 4006:
        printf("pxc-spvr.");
        break;
    case 4007:
        printf("pxc-splr.");
        break;
    case 4008:
        printf("NetCheque accounting.");
        break;
    case 4009:
        printf("Chimera HWM.");
        break;
    case 4010:
        printf("Samsung Unidex.");
        break;
    case 4011:
        printf("Alternate Service Boot.");
        break;
    case 4012:
        printf("PDA Gate.");
        break;
    case 4013:
        printf("ACL Manager.");
        break;
    case 4014:
        printf("TAICLOCK.");
        break;
    case 4015:
        printf("Talarian Mcast.");
        break;
    case 4016:
        printf("Talarian Mcast.");
        break;
    case 4017:
        printf("Talarian Mcast.");
        break;
    case 4018:
        printf("Talarian Mcast.");
        break;
    case 4019:
        printf("Talarian Mcast.");
        break;
    case 4020:
        printf("TRAP Port.");
        break;
    case 4021:
        printf("Nexus Portal.");
        break;
    case 4022:
        printf("DNOX.");
        break;
    case 4023:
        printf("ESNM Zoning Port.");
        break;
    case 4024:
        printf("TNP1 User Port.");
        break;
    case 4025:
        printf("Partition Image Port.");
        break;
    case 4026:
        printf("Graphical Debug Server.");
        break;
    case 4027:
        printf("bitxpress.");
        break;
    case 4028:
        printf("DTServer Port.");
        break;
    case 4029:
        printf("IP Q signaling protocol.");
        break;
    case 4030:
        printf("Accell/JSP Daemon Port.");
        break;
    case 4031:
        printf("UUCP over SSL.");
        break;
    case 4032:
        printf("VERITAS Authorization Service.");
        break;
    case 4033:
        printf("SANavigator Peer Port.");
        break;
    case 4034:
        printf("Ubiquinox Daemon.");
        break;
    case 4035:
        printf("WAP Push OTA-HTTP port.");
        break;
    case 4036:
        printf("WAP Push OTA-HTTP secure.");
        break;
    case 4037:
        printf("RaveHD network control.");
        break;
    case 4038:
        printf("Fazzt Point-To-Point.");
        break;
    case 4039:
        printf("Fazzt Administration.");
        break;
    case 4040:
        printf("Yo.net main service.");
        break;
    case 4041:
        printf("Rocketeer-Houston.");
        break;
    case 4042:
        printf("LDXP.");
        break;
    case 4043:
        printf("Neighbour Identity Resolution.");
        break;
    case 4044:
        printf("Location Tracking Protocol.");
        break;
    case 4045:
        printf("Network Paging Protocol.");
        break;
    case 4046:
        printf("Accounting Protocol.");
        break;
    case 4047:
        printf("Context Transfer Protocol.");
        break;
    case 4049:
        printf("Wide Area File Services.");
        break;
    case 4050:
        printf("Wide Area File Services.");
        break;
    case 4051:
        printf("Cisco Peer to Peer Distribution Protocol.");
        break;
    case 4052:
        printf("VoiceConnect Interact.");
        break;
    case 4053:
        printf("CosmoCall Universe Communications Port 1.");
        break;
    case 4054:
        printf("CosmoCall Universe Communications Port 2.");
        break;
    case 4055:
        printf("CosmoCall Universe Communications Port 3.");
        break;
    case 4056:
        printf("Location Message Service.");
        break;
    case 4057:
        printf("Servigistics WFM server.");
        break;
    case 4058:
        printf("Kingfisher protocol.");
        break;
    case 4059:
        printf("DLMS/COSEM.");
        break;
    case 4060:
        printf("DSMETER Inter-Agent Transfer Channel.");
        break;
    case 4061:
        printf("Ice Location Service (TCP).");
        break;
    case 4062:
        printf("Ice Location Service (SSL).");
        break;
    case 4063:
        printf("Ice Firewall Traversal Service (TCP).");
        break;
    case 4064:
        printf("Ice Firewall Traversal Service (SSL).");
        break;
    case 4065:
        printf("Avanti Common Data.");
        break;
    case 4066:
        printf("Performance Measurement and Analysis.");
        break;
    case 4067:
        printf("Information Distribution Protocol.");
        break;
    case 4068:
        printf("IP Fleet Broadcast.");
        break;
    case 4069:
        printf("Minger Email Address Validation Service.");
        break;
    case 4070:
        printf("Trivial IP Encryption (TrIPE).");
        break;
    case 4071:
        printf("Automatically Incremental Backup.");
        break;
    case 4072:
        printf("Zieto Socket Communications.");
        break;
    case 4073:
        printf("Interactive Remote Application Pairing Protocol.");
        break;
    case 4074:
        printf("Cequint City ID UI trigger.");
        break;
    case 4075:
        printf("ISC Alarm Message Service.");
        break;
    case 4076:
        printf("Seraph DCS.");
        break;
    case 4078:
        printf("Coordinated Security Service Protocol.");
        break;
    case 4079:
        printf("SANtools Diagnostic Server.");
        break;
    case 4080:
        printf("Lorica inside facing.");
        break;
    case 4081:
        printf("Lorica inside facing (SSL).");
        break;
    case 4082:
        printf("Lorica outside facing.");
        break;
    case 4083:
        printf("Lorica outside facing (SSL).");
        break;
    case 4085:
        printf("EZNews Newsroom Message Service.");
        break;
    case 4087:
        printf("APplus Service.");
        break;
    case 4088:
        printf("Noah Printing Service Protocol.");
        break;
    case 4089:
        printf("OpenCORE Remote Control Service.");
        break;
    case 4090:
        printf("OMA BCAST Service Guide.");
        break;
    case 4091:
        printf("EminentWare Installer.");
        break;
    case 4092:
        printf("EminentWare DGS.");
        break;
    case 4093:
        printf("Pvx Plus CS Host.");
        break;
    case 4094:
        printf("sysrq daemon.");
        break;
    case 4095:
        printf("xtgui information service.");
        break;
    case 4096:
        printf("BRE (Bridge Relay Element).");
        break;
    case 4097:
        printf("Patrol View.");
        break;
    case 4098:
        printf("drmsfsd.");
        break;
    case 4099:
        printf("DPCP.");
        break;
    case 4100:
        printf("IGo Incognito Data Port.");
        break;
    case 4101:
        printf("Braille protocol.");
        break;
    case 4102:
        printf("Braille protocol.");
        break;
    case 4103:
        printf("Braille protocol.");
        break;
    case 4104:
        printf("Braille protocol.");
        break;
    case 4105:
        printf("Shofar.");
        break;
    case 4106:
        printf("Synchronite.");
        break;
    case 4107:
        printf("JDL Accounting LAN Service.");
        break;
    case 4108:
        printf("ACCEL.");
        break;
    case 4109:
        printf("Instantiated Zero-control Messaging.");
        break;
    case 4110:
        printf("G2 RFID Tag Telemetry Data.");
        break;
    case 4111:
        printf("Xgrid.");
        break;
    case 4112:
        printf("Apple VPN Server Reporting Protocol.");
        break;
    case 4113:
        printf("AIPN LS Registration.");
        break;
    case 4114:
        printf("JomaMQMonitor.");
        break;
    case 4115:
        printf("CDS Transfer Agent.");
        break;
    case 4116:
        printf("smartcard-TLS.");
        break;
    case 4117:
        printf("Hillr Connection Manager.");
        break;
    case 4118:
        printf("Netadmin Systems NETscript service.");
        break;
    case 4119:
        printf("Assuria Log Manager.");
        break;
    case 4120:
        printf("MiniRem Remote Telemetry and Control.");
        break;
    case 4121:
        printf("e-Builder Application Communication.");
        break;
    case 4122:
        printf("Fiber Patrol Alarm Service.");
        break;
    case 4123:
        printf("Z-Wave Protocol.");
        break;
    case 4124:
        printf("Rohill TetraNode Ip Gateway v2.");
        break;
    case 4125:
        printf("Opsview Envoy.");
        break;
    case 4126:
        printf("Data Domain Replication Service.");
        break;
    case 4127:
        printf("NetUniKeyServer.");
        break;
    case 4128:
        printf("NuFW decision delegation protocol.");
        break;
    case 4129:
        printf("NuFW authentication protocol.");
        break;
    case 4130:
        printf("FRONET message protocol.");
        break;
    case 4131:
        printf("Global Maintech Stars.");
        break;
    case 4132:
        printf("NUTS Daemon.");
        break;
    case 4133:
        printf("NUTS Bootp Server.");
        break;
    case 4134:
        printf("NIFTY-Serve HMI protocol.");
        break;
    case 4135:
        printf("Classic Line Database Server Attach.");
        break;
    case 4136:
        printf("Classic Line Database Server Request.");
        break;
    case 4137:
        printf("Classic Line Database Server Remote.");
        break;
    case 4138:
        printf("nettest.");
        break;
    case 4139:
        printf("Imperfect Networks Server.");
        break;
    case 4140:
        printf("Cedros Fraud Detection System.");
        break;
    case 4141:
        printf("Workflow Server.");
        break;
    case 4142:
        printf("Document Server.");
        break;
    case 4143:
        printf("Document Replication.");
        break;
    case 4145:
        printf("VVR Control.");
        break;
    case 4146:
        printf("TGCConnect Beacon.");
        break;
    case 4147:
        printf("Multum Service Manager.");
        break;
    case 4148:
        printf("HHB Handheld Client.");
        break;
    case 4149:
        printf("A10 GSLB Service.");
        break;
    case 4150:
        printf("PowerAlert Network Shutdown Agent.");
        break;
    case 4151:
        printf("Men & Mice Remote Control.");
        break;
    case 4152:
        printf("iDigTech Multiplex.");
        break;
    case 4153:
        printf("MBL Remote Battery Monitoring.");
        break;
    case 4154:
        printf("atlinks device discovery.");
        break;
    case 4155:
        printf("Bazaar version control system.");
        break;
    case 4156:
        printf("STAT Results.");
        break;
    case 4157:
        printf("STAT Scanner Control.");
        break;
    case 4158:
        printf("STAT Command Center.");
        break;
    case 4159:
        printf("Network Security Service.");
        break;
    case 4160:
        printf("Jini Discovery.");
        break;
    case 4161:
        printf("OMS Contact.");
        break;
    case 4162:
        printf("OMS Topology.");
        break;
    case 4163:
        printf("Silver Peak Peer Protocol.");
        break;
    case 4164:
        printf("Silver Peak Communication Protocol.");
        break;
    case 4165:
        printf("ArcLink over Ethernet.");
        break;
    case 4166:
        printf("Joost Peer to Peer Protocol.");
        break;
    case 4167:
        printf("DeskDirect Global Network.");
        break;
    case 4168:
        printf("PrintSoft License Server.");
        break;
    case 4169:
        printf("Automation Drive Interface Transport.");
        break;
    case 4170:
        printf("SMPTE Content Synchonization Protocol.");
        break;
    case 4171:
        printf("Maxlogic Supervisor Communication.");
        break;
    case 4172:
        printf("PC over IP.");
        break;
    case 4174:
        printf("StorMagic Cluster Services.");
        break;
    case 4175:
        printf("Brocade Cluster Communication Protocol.");
        break;
    case 4176:
        printf("Translattice Cluster IPC Proxy.");
        break;
    case 4177:
        printf("Wello P2P pubsub service.");
        break;
    case 4178:
        printf("StorMan.");
        break;
    case 4179:
        printf("Maxum Services.");
        break;
    case 4180:
        printf("HTTPX.");
        break;
    case 4181:
        printf("MacBak.");
        break;
    case 4182:
        printf("Production Company Pro TCP Service.");
        break;
    case 4183:
        printf("CyborgNet communications protocol.");
        break;
    case 4184:
        printf("UNIVERSE SUITE MESSAGE SERVICE.");
        break;
    case 4185:
        printf("Woven Control Plane Protocol.");
        break;
    case 4186:
        printf("Box Backup Store Service.");
        break;
    case 4187:
        printf("Cascade Proxy.");
        break;
    case 4188:
        printf("Vatata Peer to Peer Protocol.");
        break;
    case 4189:
        printf("Path Computation Element Communication Protocol.");
        break;
    case 4190:
        printf("ManageSieve Protocol.");
        break;
    case 4192:
        printf("Azeti Agent Service.");
        break;
    case 4193:
        printf("PxPlus remote file srvr.");
        break;
    case 4197:
        printf("Harman HControl Protocol.");
        break;
    case 4199:
        printf("EIMS ADMIN.");
        break;
    case 4300:
        printf("Corel CCam.");
        break;
    case 4301:
        printf("Diagnostic Data.");
        break;
    case 4302:
        printf("Diagnostic Data Control.");
        break;
    case 4303:
        printf("Simple Railroad Command Protocol.");
        break;
    case 4304:
        printf("One-Wire Filesystem Server.");
        break;
    case 4305:
        printf("better approach to mobile ad-hoc networking.");
        break;
    case 4306:
        printf("Hellgate London.");
        break;
    case 4307:
        printf("TrueConf Videoconference Service.");
        break;
    case 4308:
        printf("CompX-LockView.");
        break;
    case 4309:
        printf("Exsequi Appliance Discovery.");
        break;
    case 4310:
        printf("Mir-RT exchange service.");
        break;
    case 4311:
        printf("P6R Secure Server Management Console.");
        break;
    case 4312:
        printf("Parascale Membership Manager.");
        break;
    case 4313:
        printf("PERRLA User Services.");
        break;
    case 4314:
        printf("ChoiceView Agent.");
        break;
    case 4316:
        printf("ChoiceView Client.");
        break;
    case 4320:
        printf("FDT Remote Categorization Protocol.");
        break;
    case 4321:
        printf("Remote Who Is.");
        break;
    case 4322:
        printf("TRIM Event Service.");
        break;
    case 4323:
        printf("TRIM ICE Service.");
        break;
    case 4325:
        printf("Cadcorp GeognoSIS Manager Service.");
        break;
    case 4326:
        printf("Cadcorp GeognoSIS Service.");
        break;
    case 4327:
        printf("Jaxer Web Protocol.");
        break;
    case 4328:
        printf("Jaxer Manager Command Protocol.");
        break;
    case 4329:
        printf("PubliQare Distributed Environment Synchronisation Engine.");
        break;
    case 4330:
        printf("DEY Storage Administration REST API.");
        break;
    case 4331:
        printf("ktickets REST API for event management and ticketing systems (embedded POS devices).");
        break;
    case 4333:
        printf("ArrowHead Service Protocol (AHSP).");
        break;
    case 4334:
        printf("NETCONF Call Home (SSH).");
        break;
    case 4335:
        printf("NETCONF Call Home (TLS).");
        break;
    case 4336:
        printf("RESTCONF Call Home (TLS).");
        break;
    case 4340:
        printf("Gaia Connector Protocol.");
        break;
    case 4341:
        printf("LISP Data Packets.");
        break;
    case 4342:
        printf("LISP-CONS Control.");
        break;
    case 4343:
        printf("UNICALL.");
        break;
    case 4344:
        printf("VinaInstall.");
        break;
    case 4345:
        printf("Macro 4 Network AS.");
        break;
    case 4346:
        printf("ELAN LM.");
        break;
    case 4347:
        printf("LAN Surveyor.");
        break;
    case 4348:
        printf("ITOSE.");
        break;
    case 4349:
        printf("File System Port Map.");
        break;
    case 4350:
        printf("Net Device.");
        break;
    case 4351:
        printf("PLCY Net Services.");
        break;
    case 4352:
        printf("Projector Link.");
        break;
    case 4353:
        printf("F5 iQuery.");
        break;
    case 4354:
        printf("QSNet Transmitter.");
        break;
    case 4355:
        printf("QSNet Workstation.");
        break;
    case 4356:
        printf("QSNet Assistant.");
        break;
    case 4357:
        printf("QSNet Conductor.");
        break;
    case 4358:
        printf("QSNet Nucleus.");
        break;
    case 4359:
        printf("OMA BCAST Long-Term Key Messages.");
        break;
    case 4360:
        printf("Matrix VNet Communication Protocol.");
        break;
    case 4368:
        printf("WeatherBrief Direct.");
        break;
    case 4369:
        printf("Erlang Port Mapper Daemon.");
        break;
    case 4370:
        printf("ELPRO V2 Protocol Tunnel.");
        break;
    case 4371:
        printf("LAN2CAN Control.");
        break;
    case 4372:
        printf("LAN2CAN Data.");
        break;
    case 4373:
        printf("Remote Authenticated Command Service.");
        break;
    case 4374:
        printf("PSI Push-to-Talk Protocol.");
        break;
    case 4375:
        printf("Toltec EasyShare.");
        break;
    case 4376:
        printf("BioAPI Interworking.");
        break;
    case 4377:
        printf("Cambridge Pixel SPx Server.");
        break;
    case 4378:
        printf("Cambridge Pixel SPx Display.");
        break;
    case 4379:
        printf("CTDB.");
        break;
    case 4389:
        printf("Xandros Community Management Service.");
        break;
    case 4390:
        printf("Physical Access Control.");
        break;
    case 4391:
        printf("American Printware IMServer Protocol.");
        break;
    case 4392:
        printf("American Printware RXServer Protocol.");
        break;
    case 4393:
        printf("American Printware RXSpooler Protocol.");
        break;
    case 4395:
        printf("OmniVision communication for Virtual environments.");
        break;
    case 4396:
        printf("Fly Object Space.");
        break;
    case 4400:
        printf("ASIGRA Services.");
        break;
    case 4401:
        printf("ASIGRA Televaulting DS-System Service.");
        break;
    case 4402:
        printf("ASIGRA Televaulting DS-Client Service.");
        break;
    case 4403:
        printf("ASIGRA Televaulting DS-Client Monitoring/Management.");
        break;
    case 4404:
        printf("ASIGRA Televaulting DS-System Monitoring/Management.");
        break;
    case 4405:
        printf("ASIGRA Televaulting Message Level Restore service.");
        break;
    case 4406:
        printf("ASIGRA Televaulting DS-Sleeper Service.");
        break;
    case 4407:
        printf("Network Access Control Agent.");
        break;
    case 4408:
        printf("SLS Technology Control Centre.");
        break;
    case 4409:
        printf("Net-Cabinet comunication.");
        break;
    case 4410:
        printf("RIB iTWO Application Server.");
        break;
    case 4411:
        printf("Found Messaging Protocol.");
        break;
    case 4413:
        printf("AVI Systems NMS.");
        break;
    case 4414:
        printf("Updog Monitoring and Status Framework.");
        break;
    case 4415:
        printf("Brocade Virtual Router Request.");
        break;
    case 4416:
        printf("PJJ Media Player.");
        break;
    case 4417:
        printf("Workflow Director Communication.");
        break;
    case 4419:
        printf("Colnod Binary Protocol.");
        break;
    case 4420:
        printf("NVM Express over Fabrics storage access.");
        break;
    case 4421:
        printf("Multi-Platform Remote Management for Cloud Infrastructure.");
        break;
    case 4422:
        printf("TSEP Installation Service Protocol.");
        break;
    case 4423:
        printf("thingkit secure mesh.");
        break;
    case 4425:
        printf("NetROCKEY6 SMART Plus Service.");
        break;
    case 4426:
        printf("SMARTS Beacon Port.");
        break;
    case 4427:
        printf("Drizzle database server.");
        break;
    case 4428:
        printf("OMV-Investigation Server-Client.");
        break;
    case 4429:
        printf("OMV Investigation Agent-Server.");
        break;
    case 4430:
        printf("REAL SQL Server.");
        break;
    case 4431:
        printf("adWISE Pipe.");
        break;
    case 4432:
        printf("L-ACOUSTICS management.");
        break;
    case 4433:
        printf("Versile Object Protocol.");
        break;
    case 4442:
        printf("Saris.");
        break;
    case 4443:
        printf("Pharos.");
        break;
    case 4444:
        printf("KRB524/NV Video default.");
        break;
    case 4445:
        printf("UPNOTIFYP.");
        break;
    case 4446:
        printf("N1-FWP.");
        break;
    case 4447:
        printf("N1-RMGMT.");
        break;
    case 4448:
        printf("ASC Licence Manager.");
        break;
    case 4449:
        printf("PrivateWire.");
        break;
    case 4450:
        printf("Common ASCII Messaging Protocol.");
        break;
    case 4451:
        printf("CTI System Msg.");
        break;
    case 4452:
        printf("CTI Program Load.");
        break;
    case 4453:
        printf("NSS Alert Manager.");
        break;
    case 4454:
        printf("NSS Agent Manager.");
        break;
    case 4455:
        printf("PR Chat User.");
        break;
    case 4456:
        printf("PR Chat Server.");
        break;
    case 4457:
        printf("PR Register.");
        break;
    case 4458:
        printf("Matrix Configuration Protocol.");
        break;
    case 4484:
        printf("hpssmgmt service.");
        break;
    case 4485:
        printf("Assyst Data Repository Service.");
        break;
    case 4486:
        printf("Integrated Client Message Service.");
        break;
    case 4487:
        printf("Protocol for Remote Execution over TCP.");
        break;
    case 4488:
        printf("Apple Wide Area Connectivity Service ICE Bootstrap.");
        break;
    case 4500:
        printf("IPsec NAT-Traversal.");
        break;
    case 4535:
        printf("Event Heap Server.");
        break;
    case 4536:
        printf("Event Heap Server SSL.");
        break;
    case 4537:
        printf("WSS Security Service.");
        break;
    case 4538:
        printf("Software Data Exchange Gateway.");
        break;
    case 4545:
        printf("WorldScores.");
        break;
    case 4546:
        printf("SF License Manager (Sentinel).");
        break;
    case 4547:
        printf("Lanner License Manager.");
        break;
    case 4548:
        printf("Synchromesh.");
        break;
    case 4549:
        printf("Aegate PMR Service.");
        break;
    case 4550:
        printf("Perman I Interbase Server.");
        break;
    case 4551:
        printf("MIH Services.");
        break;
    case 4552:
        printf("Men and Mice Monitoring.");
        break;
    case 4553:
        printf("ICS host services.");
        break;
    case 4554:
        printf("MS FRS Replication.");
        break;
    case 4555:
        printf("RSIP Port.");
        break;
    case 4556:
        printf("DTN Bundle TCP CL Protocol.");
        break;
    case 4559:
        printf("HylaFAX.");
        break;
    case 4563:
        printf("Amahi Anywhere.");
        break;
    case 4566:
        printf("Kids Watch Time Control Service.");
        break;
    case 4567:
        printf("TRAM.");
        break;
    case 4568:
        printf("BMC Reporting.");
        break;
    case 4569:
        printf("Inter-Asterisk eXchange.");
        break;
    case 4570:
        printf("Service to distribute and update within a site deployment information for Oracle Communications Suite.");
        break;
    case 4573:
        printf("A port for communication between a server and client for a custom backup system.");
        break;
    case 4590:
        printf("RID over HTTP/TLS.");
        break;
    case 4591:
        printf("HRPD L3T (AT-AN).");
        break;
    case 4593:
        printf("IPT (ANRI-ANRI).");
        break;
    case 4594:
        printf("IAS-Session (ANRI-ANRI).");
        break;
    case 4595:
        printf("IAS-Paging (ANRI-ANRI).");
        break;
    case 4596:
        printf("IAS-Neighbor (ANRI-ANRI).");
        break;
    case 4597:
        printf("A21 (AN-1xBS).");
        break;
    case 4598:
        printf("A16 (AN-AN).");
        break;
    case 4599:
        printf("A17 (AN-AN).");
        break;
    case 4600:
        printf("Piranha1.");
        break;
    case 4601:
        printf("Piranha2.");
        break;
    case 4602:
        printf("EAX MTS Server.");
        break;
    case 4603:
        printf("Men & Mice Upgrade Agent.");
        break;
    case 4604:
        printf("Identity Registration Protocol.");
        break;
    case 4605:
        printf("Direct End to End Secure Chat Protocol.");
        break;
    case 4658:
        printf("PlayStation2 App Port.");
        break;
    case 4659:
        printf("PlayStation2 Lobby Port.");
        break;
    case 4660:
        printf("smaclmgr.");
        break;
    case 4661:
        printf("Kar2ouche Peer location service.");
        break;
    case 4662:
        printf("OrbitNet Message Service.");
        break;
    case 4663:
        printf("Note It! Message Service.");
        break;
    case 4664:
        printf("Rimage Messaging Server.");
        break;
    case 4665:
        printf("Container Client Message Service.");
        break;
    case 4666:
        printf("E-Port Message Service.");
        break;
    case 4667:
        printf("MMA Comm Services.");
        break;
    case 4668:
        printf("MMA EDS Service.");
        break;
    case 4669:
        printf("E-Port Data Service.");
        break;
    case 4670:
        printf("Light packets transfer protocol.");
        break;
    case 4671:
        printf("Bull RSF action server.");
        break;
    case 4672:
        printf("remote file access server.");
        break;
    case 4673:
        printf("CXWS Operations.");
        break;
    case 4674:
        printf("AppIQ Agent Management.");
        break;
    case 4675:
        printf("BIAP Device Status.");
        break;
    case 4676:
        printf("BIAP Generic Alert.");
        break;
    case 4677:
        printf("Business Continuity Servi.");
        break;
    case 4678:
        printf("boundary traversal.");
        break;
    case 4679:
        printf("MGE UPS Supervision.");
        break;
    case 4680:
        printf("MGE UPS Management.");
        break;
    case 4681:
        printf("Parliant Telephony System.");
        break;
    case 4682:
        printf("finisar.");
        break;
    case 4683:
        printf("Spike Clipboard Service.");
        break;
    case 4684:
        printf("RFID Reader Protocol 1.0.");
        break;
    case 4685:
        printf("Autopac Protocol.");
        break;
    case 4686:
        printf("Manina Service Protocol.");
        break;
    case 4687:
        printf("Network Scanner Tool FTP.");
        break;
    case 4688:
        printf("Mobile P2P Service.");
        break;
    case 4689:
        printf("Altova DatabaseCentral.");
        break;
    case 4690:
        printf("Prelude IDS message proto.");
        break;
    case 4691:
        printf("monotone Netsync Protocol.");
        break;
    case 4692:
        printf("Conspiracy messaging.");
        break;
    case 4700:
        printf("NetXMS Agent.");
        break;
    case 4701:
        printf("NetXMS Management.");
        break;
    case 4702:
        printf("NetXMS Server Synchronization.");
        break;
    case 4703:
        printf("Network Performance Quality Evaluation System Test Service.");
        break;
    case 4704:
        printf("Assuria Insider.");
        break;
    case 4711:
        printf("Trinity Trust Network Node Communication.");
        break;
    case 4725:
        printf("TruckStar Service.");
        break;
    case 4727:
        printf("F-Link Client Information Service.");
        break;
    case 4728:
        printf("CA Port Multiplexer.");
        break;
    case 4730:
        printf("Gearman Job Queue System.");
        break;
    case 4731:
        printf("Remote Capture Protocol.");
        break;
    case 4733:
        printf("RES Orchestration Catalog Services.");
        break;
    case 4737:
        printf("IPDR/SP.");
        break;
    case 4738:
        printf("SoleraTec Locator.");
        break;
    case 4739:
        printf("IP Flow Info Export.");
        break;
    case 4740:
        printf("ipfix protocol over TLS.");
        break;
    case 4741:
        printf("Luminizer Manager.");
        break;
    case 4742:
        printf("SICCT.");
        break;
    case 4743:
        printf("openhpi HPI service.");
        break;
    case 4744:
        printf("Internet File Synchronization Protocol.");
        break;
    case 4745:
        printf("Funambol Mobile Push.");
        break;
    case 4749:
        printf("Profile for Mac.");
        break;
    case 4750:
        printf("Simple Service Auto Discovery.");
        break;
    case 4751:
        printf("Simple Policy Control Protocol.");
        break;
    case 4752:
        printf("Simple Network Audio Protocol.");
        break;
    case 4753:
        printf("Simple Invocation of Methods Over Network (SIMON).");
        break;
    case 4756:
        printf("Reticle Decision Center.");
        break;
    case 4774:
        printf("Converge RPC.");
        break;
    case 4784:
        printf("BFD Multihop Control.");
        break;
    case 4786:
        printf("Smart Install Service.");
        break;
    case 4787:
        printf("Service Insertion Architecture (SIA) Control-Plane.");
        break;
    case 4788:
        printf("eXtensible Messaging Client Protocol.");
        break;
    case 4800:
        printf("Icona Instant Messenging System.");
        break;
    case 4801:
        printf("Icona Web Embedded Chat.");
        break;
    case 4802:
        printf("Icona License System Server.");
        break;
    case 4803:
        printf("Notateit Messaging.");
        break;
    case 4827:
        printf("HTCP.");
        break;
    case 4837:
        printf("Varadero-0.");
        break;
    case 4838:
        printf("Varadero-1.");
        break;
    case 4839:
        printf("Varadero-2.");
        break;
    case 4840:
        printf("OPC UA Connection Protocol.");
        break;
    case 4841:
        printf("QUOSA Virtual Library Service.");
        break;
    case 4842:
        printf("nCode ICE-flow Library AppServer.");
        break;
    case 4843:
        printf("OPC UA TCP Protocol over TLS/SSL.");
        break;
    case 4844:
        printf("nCode ICE-flow Library LogServer.");
        break;
    case 4845:
        printf("WordCruncher Remote Library Service.");
        break;
    case 4846:
        printf("Contamac ICM Service.");
        break;
    case 4847:
        printf("Web Fresh Communication.");
        break;
    case 4848:
        printf("App Server - Admin HTTP.");
        break;
    case 4849:
        printf("App Server - Admin HTTPS.");
        break;
    case 4850:
        printf("Sun App Server - NA.");
        break;
    case 4851:
        printf("Apache Derby Replication.");
        break;
    case 4867:
        printf("Unify Debugger.");
        break;
    case 4868:
        printf("Photon Relay.");
        break;
    case 4869:
        printf("Photon Relay Debug.");
        break;
    case 4870:
        printf("Citcom Tracking Service.");
        break;
    case 4871:
        printf("Wired.");
        break;
    case 4876:
        printf("Tritium CAN Bus Bridge Service.");
        break;
    case 4877:
        printf("Lighting Management Control System.");
        break;
    case 4879:
        printf("WSDL Event Receiver.");
        break;
    case 4880:
        printf("IVI High-Speed LAN Instrument Protocol.");
        break;
    case 4883:
        printf("Meier-Phelps License Server.");
        break;
    case 4884:
        printf("HiveStor Distributed File System.");
        break;
    case 4885:
        printf("ABBS.");
        break;
    case 4894:
        printf("LysKOM Protocol A.");
        break;
    case 4899:
        printf("RAdmin Port.");
        break;
    case 4900:
        printf("HFSQL Client/Server Database Engine.");
        break;
    case 4901:
        printf("FileLocator Remote Search Agent.");
        break;
    case 4902:
        printf("magicCONROL RF and Data Interface.");
        break;
    case 4912:
        printf("Technicolor LUT Access Protocol.");
        break;
    case 4913:
        printf("LUTher Control Protocol.");
        break;
    case 4914:
        printf("Bones Remote Control.");
        break;
    case 4915:
        printf("Fibics Remote Control Service.");
        break;
    case 4940:
        printf("Equitrac Office.");
        break;
    case 4941:
        printf("Equitrac Office.");
        break;
    case 4942:
        printf("Equitrac Office.");
        break;
    case 4949:
        printf("Munin Graphing Framework.");
        break;
    case 4950:
        printf("Sybase Server Monitor.");
        break;
    case 4951:
        printf("PWG WIMS.");
        break;
    case 4952:
        printf("SAG Directory Server.");
        break;
    case 4953:
        printf("Synchronization Arbiter.");
        break;
    case 4969:
        printf("CCSS QMessageMonitor.");
        break;
    case 4970:
        printf("CCSS QSystemMonitor.");
        break;
    case 4971:
        printf("BackUp and Restore Program.");
        break;
    case 4984:
        printf("WebYast.");
        break;
    case 4985:
        printf("GER HC Standard.");
        break;
    case 4986:
        printf("Model Railway Interface Program.");
        break;
    case 4987:
        printf("SMAR Ethernet Port 1.");
        break;
    case 4988:
        printf("SMAR Ethernet Port 2.");
        break;
    case 4989:
        printf("Parallel for GAUSS (tm).");
        break;
    case 4990:
        printf("BusySync Calendar Synch. Protocol.");
        break;
    case 4991:
        printf("VITA Radio Transport.");
        break;
    case 4999:
        printf("HFSQL Client/Server Database Engine Manager.");
        break;
    case 5002:
        printf("radio free ethernet.");
        break;
    case 5003:
        printf("FileMaker, Inc. - Proprietary transport.");
        break;
    case 5004:
        printf("RTP media data.");
        break;
    case 5005:
        printf("RTP control protocol.");
        break;
    case 5006:
        printf("wsm server.");
        break;
    case 5007:
        printf("wsm server ssl.");
        break;
    case 5008:
        printf("Synapsis EDGE.");
        break;
    case 5009:
        printf("Microsoft Windows Filesystem.");
        break;
    case 5010:
        printf("TelepathStart.");
        break;
    case 5011:
        printf("TelepathAttack.");
        break;
    case 5012:
        printf("NetOnTap Service.");
        break;
    case 5013:
        printf("FileMaker, Inc. - Proprietary transport.");
        break;
    case 5015:
        printf("FileMaker, Inc. - Web publishing.");
        break;
    case 5020:
        printf("zenginkyo-1.");
        break;
    case 5021:
        printf("zenginkyo-2.");
        break;
    case 5022:
        printf("mice server.");
        break;
    case 5023:
        printf("Htuil Server for PLD2.");
        break;
    case 5024:
        printf("SCPI-TELNET.");
        break;
    case 5025:
        printf("SCPI-RAW.");
        break;
    case 5026:
        printf("Storix I/O daemon (data).");
        break;
    case 5027:
        printf("Storix I/O daemon (stat).");
        break;
    case 5028:
        printf("Quiqum Virtual Relais.");
        break;
    case 5029:
        printf("Infobright Database Server.");
        break;
    case 5030:
        printf("SurfPass.");
        break;
    case 5032:
        printf("SignaCert Enterprise Trust Server Agent.");
        break;
    case 5033:
        printf("Janstor Secure Data.");
        break;
    case 5034:
        printf("Janstor Status.");
        break;
    case 5042:
        printf("asnaacceler8db.");
        break;
    case 5043:
        printf("ShopWorX Administration.");
        break;
    case 5044:
        printf("LXI Event Service.");
        break;
    case 5045:
        printf("Open Settlement Protocol.");
        break;
    case 5048:
        printf("Texai Message Service.");
        break;
    case 5049:
        printf("iVocalize Web Conference.");
        break;
    case 5050:
        printf("multimedia conference control tool.");
        break;
    case 5051:
        printf("ITA Agent.");
        break;
    case 5052:
        printf("ITA Manager.");
        break;
    case 5053:
        printf("RLM License Server.");
        break;
    case 5054:
        printf("RLM administrative interface.");
        break;
    case 5055:
        printf("UNOT.");
        break;
    case 5056:
        printf("Intecom Pointspan 1.");
        break;
    case 5057:
        printf("Intecom Pointspan 2.");
        break;
    case 5059:
        printf("SIP Directory Services.");
        break;
    case 5060:
        printf("SIP.");
        break;
    case 5061:
        printf("SIP-TLS.");
        break;
    case 5062:
        printf("Localisation access.");
        break;
    case 5063:
        printf("centrify secure RPC.");
        break;
    case 5064:
        printf("Channel Access 1.");
        break;
    case 5065:
        printf("Channel Access 2.");
        break;
    case 5066:
        printf("STANAG-5066-SUBNET-INTF.");
        break;
    case 5067:
        printf("Authentx Service.");
        break;
    case 5068:
        printf("Bitforest Data Service.");
        break;
    case 5069:
        printf("I/Net 2000-NPR.");
        break;
    case 5070:
        printf("VersaTrans Server Agent Service.");
        break;
    case 5071:
        printf("PowerSchool.");
        break;
    case 5072:
        printf("Anything In Anything.");
        break;
    case 5073:
        printf("Advantage Group Port Mgr.");
        break;
    case 5074:
        printf("ALES Query.");
        break;
    case 5075:
        printf("Experimental Physics and Industrial Control System.");
        break;
    case 5080:
        printf("OnScreen Data Collection Service.");
        break;
    case 5081:
        printf("SDL - Ent Trans Server.");
        break;
    case 5082:
        printf("Qpur Communication Protocol.");
        break;
    case 5083:
        printf("Qpur File Protocol.");
        break;
    case 5084:
        printf("EPCglobal Low-Level Reader Protocol.");
        break;
    case 5085:
        printf("EPCglobal Encrypted LLRP.");
        break;
    case 5086:
        printf("Aprigo Collection Service.");
        break;
    case 5087:
        printf("BIOTIC - Binary Internet of Things Interoperable Communication.");
        break;
    case 5093:
        printf("Sentinel LM.");
        break;
    case 5094:
        printf("HART-IP.");
        break;
    case 5099:
        printf("SentLM Srv2Srv.");
        break;
    case 5100:
        printf("Socalia service mux.");
        break;
    case 5101:
        printf("Talarian_TCP.");
        break;
    case 5102:
        printf("Oracle OMS non-secure.");
        break;
    case 5103:
        printf("Actifio C2C.");
        break;
    case 5106:
        printf("Actifio UDS Agent.");
        break;
    case 5107:
        printf("Disk to Disk replication between Actifio Clusters.");
        break;
    case 5111:
        printf("TAEP AS service.");
        break;
    case 5112:
        printf("PeerMe Msg Cmd Service.");
        break;
    case 5114:
        printf("Enterprise Vault Services.");
        break;
    case 5115:
        printf("Symantec Autobuild Service.");
        break;
    case 5117:
        printf("GradeCam Image Processing.");
        break;
    case 5120:
        printf("Barracuda Backup Protocol.");
        break;
    case 5133:
        printf("Policy Commander.");
        break;
    case 5134:
        printf("PP ActivationServer.");
        break;
    case 5135:
        printf("ERP-Scale.");
        break;
    case 5137:
        printf("MyCTS server port.");
        break;
    case 5145:
        printf("RMONITOR SECURE.");
        break;
    case 5146:
        printf("Social Alarm Service.");
        break;
    case 5150:
        printf("Ascend Tunnel Management Protocol.");
        break;
    case 5151:
        printf("ESRI SDE Instance.");
        break;
    case 5152:
        printf("ESRI SDE Instance Discovery.");
        break;
    case 5154:
        printf("BZFlag game server.");
        break;
    case 5155:
        printf("Oracle asControl Agent.");
        break;
    case 5156:
        printf("Russian Online Game.");
        break;
    case 5157:
        printf("Mediat Remote Object Exchange.");
        break;
    case 5161:
        printf("SNMP over SSH Transport Model.");
        break;
    case 5162:
        printf("SNMP Notification over SSH Transport Model.");
        break;
    case 5163:
        printf("Shadow Backup.");
        break;
    case 5164:
        printf("Virtual Protocol Adapter.");
        break;
    case 5165:
        printf("ife_1corp.");
        break;
    case 5166:
        printf("WinPCS Service Connection.");
        break;
    case 5167:
        printf("SCTE104 Connection.");
        break;
    case 5168:
        printf("SCTE30 Connection.");
        break;
    case 5172:
        printf("PC over IP Endpoint Management.");
        break;
    case 5190:
        printf("America-Online.");
        break;
    case 5191:
        printf("AmericaOnline1.");
        break;
    case 5192:
        printf("AmericaOnline2.");
        break;
    case 5193:
        printf("AmericaOnline3.");
        break;
    case 5194:
        printf("CipherPoint Config Service.");
        break;
    case 5195:
        printf("The protocol is used by a license server and client programs to control use of program licenses that float to networked machines.");
        break;
    case 5197:
        printf("Tunstall Lone worker device interface.");
        break;
    case 5200:
        printf("TARGUS GetData.");
        break;
    case 5201:
        printf("TARGUS GetData 1.");
        break;
    case 5202:
        printf("TARGUS GetData 2.");
        break;
    case 5203:
        printf("TARGUS GetData 3.");
        break;
    case 5209:
        printf("Nomad Device Video Transfer.");
        break;
    case 5215:
        printf("NOTEZA Data Safety Service.");
        break;
    case 5221:
        printf("3eTI Extensible Management Protocol for OAMP.");
        break;
    case 5222:
        printf("XMPP Client Connection.");
        break;
    case 5223:
        printf("HP Virtual Machine Group Management.");
        break;
    case 5224:
        printf("HP Virtual Machine Console Operations.");
        break;
    case 5225:
        printf("HP Server.");
        break;
    case 5226:
        printf("HP Status.");
        break;
    case 5227:
        printf("HP System Performance Metric Service.");
        break;
    case 5228:
        printf("HP Virtual Room Service.");
        break;
    case 5229:
        printf("Netflow/IPFIX/sFlow Collector and Forwarder Management.");
        break;
    case 5230:
        printf("JaxMP RealFlow application and protocol data.");
        break;
    case 5231:
        printf("Remote Control of Scan Software for Cruse Scanners.");
        break;
    case 5232:
        printf("Cruse Scanning System Service.");
        break;
    case 5233:
        printf("Etinnae Network File Service.");
        break;
    case 5234:
        printf("EEnet communications.");
        break;
    case 5235:
        printf("Galaxy Network Service.");
        break;
    case 5237:
        printf("m-net discovery.");
        break;
    case 5245:
        printf("DownTools Control Protocol.");
        break;
    case 5248:
        printf("CA Access Control Web Service.");
        break;
    case 5249:
        printf("CA AC Lang Service.");
        break;
    case 5250:
        printf("soaGateway.");
        break;
    case 5251:
        printf("CA eTrust VM Service.");
        break;
    case 5252:
        printf("Movaz SSC.");
        break;
    case 5253:
        printf("Kohler Power Device Protocol.");
        break;
    case 5254:
        printf("LogCabin storage service.");
        break;
    case 5264:
        printf("3Com Network Jack Port 1.");
        break;
    case 5265:
        printf("3Com Network Jack Port 2.");
        break;
    case 5269:
        printf("XMPP Server Connection.");
        break;
    case 5270:
        printf("Cartographer XMP.");
        break;
    case 5271:
        printf("StageSoft CueLink messaging.");
        break;
    case 5272:
        printf("PK.");
        break;
    case 5280:
        printf("Bidirectional-streams Over Synchronous HTTP (BOSH).");
        break;
    case 5281:
        printf("Undo License Manager.");
        break;
    case 5282:
        printf("Marimba Transmitter Port.");
        break;
    case 5298:
        printf("XMPP Link-Local Messaging.");
        break;
    case 5299:
        printf("NLG Data Service.");
        break;
    case 5300:
        printf("HA cluster heartbeat.");
        break;
    case 5301:
        printf("HA cluster general services.");
        break;
    case 5302:
        printf("HA cluster configuration.");
        break;
    case 5303:
        printf("HA cluster probing.");
        break;
    case 5304:
        printf("HA Cluster Commands.");
        break;
    case 5305:
        printf("HA Cluster Test.");
        break;
    case 5306:
        printf("Sun MC Group.");
        break;
    case 5307:
        printf("SCO AIP.");
        break;
    case 5308:
        printf("CFengine.");
        break;
    case 5309:
        printf("J Printer.");
        break;
    case 5310:
        printf("Outlaws.");
        break;
    case 5312:
        printf("Permabit Client-Server.");
        break;
    case 5313:
        printf("Real-time & Reliable Data.");
        break;
    case 5314:
        printf("opalis-rbt-ipc.");
        break;
    case 5315:
        printf("HA Cluster UDP Polling.");
        break;
    case 5316:
        printf("HPBladeSystem Monitor Service.");
        break;
    case 5317:
        printf("HP Device Monitor Service.");
        break;
    case 5318:
        printf("PKIX Certificate Management using CMS (CMC).");
        break;
    case 5320:
        printf("Webservices-based Zn interface of BSF.");
        break;
    case 5321:
        printf("Webservices-based Zn interface of BSF over SSL.");
        break;
    case 5343:
        printf("Sculptor Database Server.");
        break;
    case 5344:
        printf("xkoto DRCP.");
        break;
    case 5349:
        printf("STUN over TLS/TURN over TLS/STUN Behavior Discovery over TLS.");
        break;
    case 5352:
        printf("DNS Long-Lived Queries.");
        break;
    case 5353:
        printf("Multicast DNS.");
        break;
    case 5354:
        printf("Multicast DNS Responder IPC.");
        break;
    case 5355:
        printf("LLMNR.");
        break;
    case 5356:
        printf("Microsoft Small Business.");
        break;
    case 5357:
        printf("Web Services for Devices.");
        break;
    case 5358:
        printf("WS for Devices Secured.");
        break;
    case 5359:
        printf("Microsoft Alerter.");
        break;
    case 5360:
        printf("Protocol for Windows SideShow.");
        break;
    case 5361:
        printf("Secure Protocol for Windows SideShow.");
        break;
    case 5362:
        printf("Microsoft Windows Server WSD2 Service.");
        break;
    case 5363:
        printf("Windows Network Projection.");
        break;
    case 5397:
        printf("StressTester(tm) Injector.");
        break;
    case 5398:
        printf("Elektron Administration.");
        break;
    case 5399:
        printf("SecurityChase.");
        break;
    case 5400:
        printf("Excerpt Search.");
        break;
    case 5401:
        printf("Excerpt Search Secure.");
        break;
    case 5402:
        printf("OmniCast MFTP.");
        break;
    case 5403:
        printf("HPOMS-CI-LSTN.");
        break;
    case 5404:
        printf("HPOMS-DPS-LSTN.");
        break;
    case 5405:
        printf("NetSupport.");
        break;
    case 5406:
        printf("Systemics Sox.");
        break;
    case 5407:
        printf("Foresyte-Clear.");
        break;
    case 5408:
        printf("Foresyte-Sec.");
        break;
    case 5409:
        printf("Salient Data Server.");
        break;
    case 5410:
        printf("Salient User Manager.");
        break;
    case 5411:
        printf("ActNet.");
        break;
    case 5412:
        printf("Continuus.");
        break;
    case 5413:
        printf("WWIOTALK.");
        break;
    case 5414:
        printf("StatusD.");
        break;
    case 5415:
        printf("NS Server.");
        break;
    case 5416:
        printf("SNS Gateway.");
        break;
    case 5417:
        printf("SNS Agent.");
        break;
    case 5418:
        printf("MCNTP.");
        break;
    case 5419:
        printf("DJ-ICE.");
        break;
    case 5420:
        printf("Cylink-C.");
        break;
    case 5421:
        printf("Net Support 2.");
        break;
    case 5422:
        printf("Salient MUX.");
        break;
    case 5423:
        printf("VIRTUALUSER.");
        break;
    case 5424:
        printf("Beyond Remote.");
        break;
    case 5425:
        printf("Beyond Remote Command Channel.");
        break;
    case 5426:
        printf("DEVBASIC.");
        break;
    case 5427:
        printf("SCO-PEER-TTA.");
        break;
    case 5428:
        printf("TELACONSOLE.");
        break;
    case 5429:
        printf("Billing and Accounting System Exchange.");
        break;
    case 5430:
        printf("RADEC CORP.");
        break;
    case 5431:
        printf("PARK AGENT.");
        break;
    case 5432:
        printf("PostgreSQL Database.");
        break;
    case 5433:
        printf("Pyrrho DBMS.");
        break;
    case 5434:
        printf("SGI Array Services Daemon.");
        break;
    case 5435:
        printf("SCEANICS situation and action notification.");
        break;
    case 5443:
        printf("Pearson HTTPS.");
        break;
    case 5445:
        printf("Server Message Block over Remote Direct Memory Access.");
        break;
    case 5450:
        printf("TiePie engineering data acquisition.");
        break;
    case 5453:
        printf("SureBox.");
        break;
    case 5454:
        printf("APC 5454.");
        break;
    case 5455:
        printf("APC 5455.");
        break;
    case 5456:
        printf("APC 5456.");
        break;
    case 5461:
        printf("SILKMETER.");
        break;
    case 5462:
        printf("TTL Publisher.");
        break;
    case 5463:
        printf("TTL Price Proxy.");
        break;
    case 5464:
        printf("Quail Networks Object Broker.");
        break;
    case 5465:
        printf("NETOPS-BROKER.");
        break;
    case 5470:
        printf("The Apsolab company's data collection protocol (native api).");
        break;
    case 5471:
        printf("The Apsolab company's secure data collection protocol (native api).");
        break;
    case 5472:
        printf("The Apsolab company's dynamic tag protocol.");
        break;
    case 5473:
        printf("The Apsolab company's secure dynamic tag protocol.");
        break;
    case 5475:
        printf("The Apsolab company's data retrieval protocol.");
        break;
    case 5500:
        printf("fcp-addr-srvr1.");
        break;
    case 5501:
        printf("fcp-addr-srvr2.");
        break;
    case 5502:
        printf("fcp-srvr-inst1.");
        break;
    case 5503:
        printf("fcp-srvr-inst2.");
        break;
    case 5504:
        printf("fcp-cics-gw1.");
        break;
    case 5505:
        printf("Checkout Database.");
        break;
    case 5506:
        printf("Amcom Mobile Connect.");
        break;
    case 5507:
        printf("PowerSysLab Electrical Management.");
        break;
    case 5550:
        printf("Model Railway control using the CBUS message protocol.");
        break;
    case 5553:
        printf("SGI Eventmond Port.");
        break;
    case 5554:
        printf("SGI ESP HTTP.");
        break;
    case 5555:
        printf("Personal Agent.");
        break;
    case 5556:
        printf("Freeciv gameplay.");
        break;
    case 5557:
        printf("Sandlab FARENET.");
        break;
    case 5565:
        printf("HPE Advanced BURA.");
        break;
    case 5566:
        printf("Westec Connect.");
        break;
    case 5567:
        printf("DOF Protocol Stack Multicast/Secure Transport.");
        break;
    case 5568:
        printf("Session Data Transport Multicast.");
        break;
    case 5569:
        printf("PLASA E1.33, Remote Device Management (RDM) controller status notifications.");
        break;
    case 5573:
        printf("SAS Domain Management Messaging Protocol.");
        break;
    case 5574:
        printf("SAS IO Forwarding.");
        break;
    case 5575:
        printf("Oracle Access Protocol.");
        break;
    case 5579:
        printf("FleetDisplay Tracking Service.");
        break;
    case 5580:
        printf("T-Mobile SMS Protocol Message 0.");
        break;
    case 5581:
        printf("T-Mobile SMS Protocol Message 1.");
        break;
    case 5582:
        printf("T-Mobile SMS Protocol Message 3.");
        break;
    case 5583:
        printf("T-Mobile SMS Protocol Message 2.");
        break;
    case 5584:
        printf("BeInSync-Web.");
        break;
    case 5585:
        printf("BeInSync-sync.");
        break;
    case 5586:
        printf("Planning to send mobile terminated SMS to the specific port so that the SMS is not visible to the client.");
        break;
    case 5597:
        printf("inin secure messaging.");
        break;
    case 5598:
        printf("MCT Market Data Feed.");
        break;
    case 5599:
        printf("Enterprise Security Remote Install.");
        break;
    case 5600:
        printf("Enterprise Security Manager.");
        break;
    case 5601:
        printf("Enterprise Security Agent.");
        break;
    case 5602:
        printf("A1-MSC.");
        break;
    case 5603:
        printf("A1-BS.");
        break;
    case 5604:
        printf("A3-SDUNode.");
        break;
    case 5605:
        printf("A4-SDUNode.");
        break;
    case 5618:
        printf("Fiscal Registering Protocol.");
        break;
    case 5627:
        printf("Node Initiated Network Association Forma.");
        break;
    case 5628:
        printf("HTrust API.");
        break;
    case 5629:
        printf("Symantec Storage Foundation for Database.");
        break;
    case 5630:
        printf("PreciseCommunication.");
        break;
    case 5631:
        printf("pcANYWHEREdata.");
        break;
    case 5632:
        printf("pcANYWHEREstat.");
        break;
    case 5633:
        printf("BE Operations Request Listener.");
        break;
    case 5634:
        printf("SF Message Service.");
        break;
    case 5635:
        printf("SFM Authentication Subsystem.");
        break;
    case 5636:
        printf("SFMdb - SFM DB server.");
        break;
    case 5637:
        printf("Symantec CSSC.");
        break;
    case 5638:
        printf("Symantec Fingerprint Lookup and Container Reference Service.");
        break;
    case 5639:
        printf("Symantec Integrity Checking Service.");
        break;
    case 5646:
        printf("Ventureforth Mobile.");
        break;
    case 5666:
        printf("Nagios Remote Plugin Executor.");
        break;
    case 5670:
        printf("ZeroMQ file publish-subscribe protocol.");
        break;
    case 5671:
        printf("amqp protocol over TLS/SSL.");
        break;
    case 5672:
        printf("AMQP.");
        break;
    case 5673:
        printf("JACL Message Server.");
        break;
    case 5674:
        printf("HyperSCSI Port.");
        break;
    case 5675:
        printf("V5UA application port.");
        break;
    case 5676:
        printf("RA Administration.");
        break;
    case 5677:
        printf("Quest Central DB2 Launchr.");
        break;
    case 5678:
        printf("Remote Replication Agent Connection.");
        break;
    case 5679:
        printf("Direct Cable Connect Manager.");
        break;
    case 5680:
        printf("Auriga Router Service.");
        break;
    case 5681:
        printf("Net-coneX Control Protocol.");
        break;
    case 5683:
        printf("Constrained Application Protocol (CoAP).");
        break;
    case 5684:
        printf("Constrained Application Protocol (CoAP).");
        break;
    case 5688:
        printf("GGZ Gaming Zone.");
        break;
    case 5689:
        printf("QM video network management protocol.");
        break;
    case 5693:
        printf("Robert Bosch Data Transfer.");
        break;
    case 5696:
        printf("Key Management Interoperability Protocol.");
        break;
    case 5700:
        printf("Dell SupportAssist data center management.");
        break;
    case 5705:
        printf("StorageOS REST API.");
        break;
    case 5713:
        printf("proshare conf audio.");
        break;
    case 5714:
        printf("proshare conf video.");
        break;
    case 5715:
        printf("proshare conf data.");
        break;
    case 5716:
        printf("proshare conf request.");
        break;
    case 5717:
        printf("proshare conf notify.");
        break;
    case 5718:
        printf("DPM Communication Server.");
        break;
    case 5719:
        printf("DPM Agent Coordinator.");
        break;
    case 5720:
        printf("MS-Licensing.");
        break;
    case 5721:
        printf("Desktop Passthru Service.");
        break;
    case 5722:
        printf("Microsoft DFS Replication Service.");
        break;
    case 5723:
        printf("Operations Manager - Health Service.");
        break;
    case 5724:
        printf("Operations Manager - SDK Service.");
        break;
    case 5725:
        printf("Microsoft Identity Lifecycle Manager.");
        break;
    case 5726:
        printf("Microsoft Lifecycle Manager Secure Token Service.");
        break;
    case 5727:
        printf("ASG Event Notification Framework.");
        break;
    case 5728:
        printf("Dist. I/O Comm. Service Data and Control.");
        break;
    case 5729:
        printf("Openmail User Agent Layer.");
        break;
    case 5730:
        printf("Steltor's calendar access.");
        break;
    case 5741:
        printf("IDA Discover Port 1.");
        break;
    case 5742:
        printf("IDA Discover Port 2.");
        break;
    case 5743:
        printf("Watchdoc NetPOD Protocol.");
        break;
    case 5744:
        printf("Watchdoc Server.");
        break;
    case 5745:
        printf("fcopy-server.");
        break;
    case 5746:
        printf("fcopys-server.");
        break;
    case 5747:
        printf("Wildbits Tunatic.");
        break;
    case 5748:
        printf("Wildbits Tunalyzer.");
        break;
    case 5750:
        printf("Bladelogic Agent Service.");
        break;
    case 5755:
        printf("OpenMail Desk Gateway server.");
        break;
    case 5757:
        printf("OpenMail X.500 Directory Server.");
        break;
    case 5766:
        printf("OpenMail NewMail Server.");
        break;
    case 5767:
        printf("OpenMail Suer Agent Layer (Secure).");
        break;
    case 5768:
        printf("OpenMail CMTS Server.");
        break;
    case 5769:
        printf("x509solutions Internal CA.");
        break;
    case 5770:
        printf("x509solutions Secure Data.");
        break;
    case 5771:
        printf("NetAgent.");
        break;
    case 5777:
        printf("DALI Port.");
        break;
    case 5780:
        printf("Visual Tag System RPC.");
        break;
    case 5781:
        printf("3PAR Event Reporting Service.");
        break;
    case 5782:
        printf("3PAR Management Service.");
        break;
    case 5783:
        printf("3PAR Management Service with SSL.");
        break;
    case 5785:
        printf("3PAR Inform Remote Copy.");
        break;
    case 5793:
        printf("XtreamX Supervised Peer message.");
        break;
    case 5813:
        printf("ICMPD.");
        break;
    case 5814:
        printf("Support Automation.");
        break;
    case 5841:
        printf("Z-firm ShipRush interface for web access and bidirectional data.");
        break;
    case 5842:
        printf("Reversion Backup/Restore.");
        break;
    case 5859:
        printf("WHEREHOO.");
        break;
    case 5863:
        printf("PlanetPress Suite Messeng.");
        break;
    case 5868:
        printf("Diameter over TLS/TCP.");
        break;
    case 5883:
        printf("Javascript Unit Test Environment.");
        break;
    case 5900:
        printf("Remote Framebuffer.");
        break;
    case 5910:
        printf("Context Management.");
        break;
    case 5911:
        printf("Controller Pilot Data Link Communication.");
        break;
    case 5912:
        printf("Flight Information Services.");
        break;
    case 5913:
        printf("Automatic Dependent Surveillance.");
        break;
    case 5963:
        printf("Indy Application Server.");
        break;
    case 5968:
        printf("mppolicy-v5.");
        break;
    case 5969:
        printf("mppolicy-mgr.");
        break;
    case 5984:
        printf("CouchDB.");
        break;
    case 5985:
        printf("WBEM WS-Management HTTP.");
        break;
    case 5986:
        printf("WBEM WS-Management HTTP over TLS/SSL.");
        break;
    case 5987:
        printf("WBEM RMI.");
        break;
    case 5988:
        printf("WBEM CIM-XML (HTTP).");
        break;
    case 5989:
        printf("WBEM CIM-XML (HTTPS).");
        break;
    case 5990:
        printf("WBEM Export HTTPS.");
        break;
    case 5991:
        printf("NUXSL.");
        break;
    case 5992:
        printf("Consul InSight Security.");
        break;
    case 5993:
        printf("DMTF WBEM CIM REST.");
        break;
    case 5999:
        printf("CVSup.");
        break;
    case 6000:
        printf("X Window System.");
        break;
    case 6001:
        printf("X Window System.");
        break;
    case 6002:
        printf("X Window System.");
        break;
    case 6003:
        printf("X Window System.");
        break;
    case 6004:
        printf("X Window System.");
        break;
    case 6005:
        printf("X Window System.");
        break;
    case 6006:
        printf("X Window System.");
        break;
    case 6007:
        printf("X Window System.");
        break;
    case 6008:
        printf("X Window System.");
        break;
    case 6009:
        printf("X Window System.");
        break;
    case 6010:
        printf("X Window System.");
        break;
    case 6011:
        printf("X Window System.");
        break;
    case 6012:
        printf("X Window System.");
        break;
    case 6013:
        printf("X Window System.");
        break;
    case 6014:
        printf("X Window System.");
        break;
    case 6015:
        printf("X Window System.");
        break;
    case 6016:
        printf("X Window System.");
        break;
    case 6017:
        printf("X Window System.");
        break;
    case 6018:
        printf("X Window System.");
        break;
    case 6019:
        printf("X Window System.");
        break;
    case 6020:
        printf("X Window System.");
        break;
    case 6021:
        printf("X Window System.");
        break;
    case 6022:
        printf("X Window System.");
        break;
    case 6023:
        printf("X Window System.");
        break;
    case 6024:
        printf("X Window System.");
        break;
    case 6025:
        printf("X Window System.");
        break;
    case 6026:
        printf("X Window System.");
        break;
    case 6027:
        printf("X Window System.");
        break;
    case 6028:
        printf("X Window System.");
        break;
    case 6029:
        printf("X Window System.");
        break;
    case 6030:
        printf("X Window System.");
        break;
    case 6031:
        printf("X Window System.");
        break;
    case 6032:
        printf("X Window System.");
        break;
    case 6033:
        printf("X Window System.");
        break;
    case 6034:
        printf("X Window System.");
        break;
    case 6035:
        printf("X Window System.");
        break;
    case 6036:
        printf("X Window System.");
        break;
    case 6037:
        printf("X Window System.");
        break;
    case 6038:
        printf("X Window System.");
        break;
    case 6039:
        printf("X Window System.");
        break;
    case 6040:
        printf("X Window System.");
        break;
    case 6041:
        printf("X Window System.");
        break;
    case 6042:
        printf("X Window System.");
        break;
    case 6043:
        printf("X Window System.");
        break;
    case 6044:
        printf("X Window System.");
        break;
    case 6045:
        printf("X Window System.");
        break;
    case 6046:
        printf("X Window System.");
        break;
    case 6047:
        printf("X Window System.");
        break;
    case 6048:
        printf("X Window System.");
        break;
    case 6049:
        printf("X Window System.");
        break;
    case 6050:
        printf("X Window System.");
        break;
    case 6051:
        printf("X Window System.");
        break;
    case 6052:
        printf("X Window System.");
        break;
    case 6053:
        printf("X Window System.");
        break;
    case 6054:
        printf("X Window System.");
        break;
    case 6055:
        printf("X Window System.");
        break;
    case 6056:
        printf("X Window System.");
        break;
    case 6057:
        printf("X Window System.");
        break;
    case 6058:
        printf("X Window System.");
        break;
    case 6059:
        printf("X Window System.");
        break;
    case 6060:
        printf("X Window System.");
        break;
    case 6061:
        printf("X Window System.");
        break;
    case 6062:
        printf("X Window System.");
        break;
    case 6063:
        printf("X Window System.");
        break;
    case 6064:
        printf("NDL-AHP-SVC.");
        break;
    case 6065:
        printf("WinPharaoh.");
        break;
    case 6066:
        printf("EWCTSP.");
        break;
    case 6068:
        printf("GSMP/ANCP.");
        break;
    case 6069:
        printf("TRIP.");
        break;
    case 6070:
        printf("Messageasap.");
        break;
    case 6071:
        printf("SSDTP.");
        break;
    case 6072:
        printf("DIAGNOSE-PROC.");
        break;
    case 6073:
        printf("DirectPlay8.");
        break;
    case 6074:
        printf("Microsoft Max.");
        break;
    case 6075:
        printf("Microsoft DPM Access Control Manager.");
        break;
    case 6076:
        printf("Microsoft DPM WCF Certificates.");
        break;
    case 6077:
        printf("iConstruct Server.");
        break;
    case 6084:
        printf("Peer to Peer Infrastructure Configuration.");
        break;
    case 6085:
        printf("konspire2b p2p network.");
        break;
    case 6086:
        printf("PDTP P2P.");
        break;
    case 6087:
        printf("Local Download Sharing Service.");
        break;
    case 6088:
        printf("SuperDog License Manager.");
        break;
    case 6099:
        printf("RAXA Management.");
        break;
    case 6100:
        printf("SynchroNet-db.");
        break;
    case 6101:
        printf("SynchroNet-rtc.");
        break;
    case 6102:
        printf("SynchroNet-upd.");
        break;
    case 6103:
        printf("RETS.");
        break;
    case 6104:
        printf("DBDB.");
        break;
    case 6105:
        printf("Prima Server.");
        break;
    case 6106:
        printf("MPS Server.");
        break;
    case 6107:
        printf("ETC Control.");
        break;
    case 6108:
        printf("Sercomm-SCAdmin.");
        break;
    case 6109:
        printf("GLOBECAST-ID.");
        break;
    case 6110:
        printf("HP SoftBench CM.");
        break;
    case 6111:
        printf("HP SoftBench Sub-Process Control.");
        break;
    case 6112:
        printf("Desk-Top Sub-Process Control Daemon.");
        break;
    case 6113:
        printf("Daylite Server.");
        break;
    case 6114:
        printf("WRspice IPC Service.");
        break;
    case 6115:
        printf("Xic IPC Service.");
        break;
    case 6116:
        printf("XicTools License Manager Service.");
        break;
    case 6117:
        printf("Daylite Touch Sync.");
        break;
    case 6121:
        printf("SPDY for a faster web.");
        break;
    case 6122:
        printf("Backup Express Web Server.");
        break;
    case 6123:
        printf("Backup Express.");
        break;
    case 6124:
        printf("Phlexible Network Backup Service.");
        break;
    case 6130:
        printf("The DameWare Mobile Gateway Service.");
        break;
    case 6133:
        printf("New Boundary Tech WOL.");
        break;
    case 6140:
        printf("Pulsonix Network License Service.");
        break;
    case 6141:
        printf("Meta Corporation License Manager.");
        break;
    case 6142:
        printf("Aspen Technology License Manager.");
        break;
    case 6143:
        printf("Watershed License Manager.");
        break;
    case 6144:
        printf("StatSci License Manager - 1.");
        break;
    case 6145:
        printf("StatSci License Manager - 2.");
        break;
    case 6146:
        printf("Lone Wolf Systems License Manager.");
        break;
    case 6147:
        printf("Montage License Manager.");
        break;
    case 6148:
        printf("Ricardo North America License Manager.");
        break;
    case 6149:
        printf("tal-pod.");
        break;
    case 6159:
        printf("EFB Application Control Interface.");
        break;
    case 6160:
        printf("Emerson Extensible Control and Management Protocol.");
        break;
    case 6161:
        printf("PATROL Internet Srv Mgr.");
        break;
    case 6162:
        printf("PATROL Collector.");
        break;
    case 6163:
        printf("Precision Scribe Cnx Port.");
        break;
    case 6200:
        printf("LM-X License Manager by X-Formation.");
        break;
    case 6209:
        printf("QMTP over TLS.");
        break;
    case 6222:
        printf("Radmind Access Protocol.");
        break;
    case 6241:
        printf("JEOL Network Services Data Transport Protocol 1.");
        break;
    case 6242:
        printf("JEOL Network Services Data Transport Protocol 2.");
        break;
    case 6243:
        printf("JEOL Network Services Data Transport Protocol 3.");
        break;
    case 6244:
        printf("JEOL Network Services Data Transport Protocol 4.");
        break;
    case 6251:
        printf("TL1 Raw Over SSL/TLS.");
        break;
    case 6252:
        printf("TL1 over SSH.");
        break;
    case 6253:
        printf("CRIP.");
        break;
    case 6267:
        printf("GridLAB-D User Interface.");
        break;
    case 6268:
        printf("Grid Authentication.");
        break;
    case 6269:
        printf("Grid Authentication Alt.");
        break;
    case 6300:
        printf("BMC GRX.");
        break;
    case 6301:
        printf("BMC CONTROL-D LDAP SERVER.");
        break;
    case 6306:
        printf("Unified Fabric Management Protocol.");
        break;
    case 6315:
        printf("Sensor Control Unit Protocol.");
        break;
    case 6316:
        printf("Ethernet Sensor Communications Protocol.");
        break;
    case 6317:
        printf("Navtech Radar Sensor Data Command.");
        break;
    case 6320:
        printf("Double-Take Replication Service.");
        break;
    case 6321:
        printf("Empress Software Connectivity Server 1.");
        break;
    case 6322:
        printf("Empress Software Connectivity Server 2.");
        break;
    case 6324:
        printf("HR Device Network Configuration Service.");
        break;
    case 6325:
        printf("Double-Take Management Service.");
        break;
    case 6326:
        printf("Double-Take Virtual Recovery Assistant.");
        break;
    case 6343:
        printf("sFlow traffic monitoring.");
        break;
    case 6344:
        printf("Argus-Spectr security and fire-prevention systems service.");
        break;
    case 6346:
        printf("gnutella-svc.");
        break;
    case 6347:
        printf("gnutella-rtr.");
        break;
    case 6350:
        printf("App Discovery and Access Protocol.");
        break;
    case 6355:
        printf("PMCS applications.");
        break;
    case 6360:
        printf("MetaEdit+ Multi-User.");
        break;
    case 6370:
        printf("MetaEdit+ Server Administration.");
        break;
    case 6379:
        printf("An advanced key-value cache and store.");
        break;
    case 6382:
        printf("Metatude Dialogue Server.");
        break;
    case 6389:
        printf("clariion-evr01.");
        break;
    case 6390:
        printf("MetaEdit+ WebService API.");
        break;
    case 6417:
        printf("Faxcom Message Service.");
        break;
    case 6418:
        printf("SYserver remote commands.");
        break;
    case 6419:
        printf("Simple VDR Protocol.");
        break;
    case 6420:
        printf("NIM_VDRShell.");
        break;
    case 6421:
        printf("NIM_WAN.");
        break;
    case 6432:
        printf("PgBouncer.");
        break;
    case 6442:
        printf("Transitory Application Request Protocol.");
        break;
    case 6443:
        printf("Service Registry Default HTTPS Domain.");
        break;
    case 6444:
        printf("Grid Engine Qmaster Service.");
        break;
    case 6445:
        printf("Grid Engine Execution Service.");
        break;
    case 6446:
        printf("MySQL Proxy.");
        break;
    case 6455:
        printf("SKIP Certificate Receive.");
        break;
    case 6456:
        printf("SKIP Certificate Send.");
        break;
    case 6464:
        printf("Port assignment for medical device communication in accordance to IEEE 11073-20701.");
        break;
    case 6471:
        printf("LVision License Manager.");
        break;
    case 6480:
        printf("Service Registry Default HTTP Domain.");
        break;
    case 6481:
        printf("Service Tags.");
        break;
    case 6482:
        printf("Logical Domains Management Interface.");
        break;
    case 6483:
        printf("SunVTS RMI.");
        break;
    case 6484:
        printf("Service Registry Default JMS Domain.");
        break;
    case 6485:
        printf("Service Registry Default IIOP Domain.");
        break;
    case 6486:
        printf("Service Registry Default IIOPS Domain.");
        break;
    case 6487:
        printf("Service Registry Default IIOPAuth Domain.");
        break;
    case 6488:
        printf("Service Registry Default JMX Domain.");
        break;
    case 6489:
        printf("Service Registry Default Admin Domain.");
        break;
    case 6500:
        printf("BoKS Master.");
        break;
    case 6501:
        printf("BoKS Servc.");
        break;
    case 6502:
        printf("BoKS Servm.");
        break;
    case 6503:
        printf("BoKS Clntd.");
        break;
    case 6505:
        printf("BoKS Admin Private Port.");
        break;
    case 6506:
        printf("BoKS Admin Public Port.");
        break;
    case 6507:
        printf("BoKS Dir Server, Private Port.");
        break;
    case 6508:
        printf("BoKS Dir Server, Public Port.");
        break;
    case 6509:
        printf("MGCS-MFP Port.");
        break;
    case 6510:
        printf("MCER Port.");
        break;
    case 6513:
        printf("NETCONF over TLS.");
        break;
    case 6514:
        printf("Syslog over TLS.");
        break;
    case 6515:
        printf("Elipse RPC Protocol.");
        break;
    case 6543:
        printf("lds_distrib.");
        break;
    case 6544:
        printf("LDS Dump Service.");
        break;
    case 6547:
        printf("APC 6547.");
        break;
    case 6548:
        printf("APC 6548.");
        break;
    case 6549:
        printf("APC 6549.");
        break;
    case 6550:
        printf("fg-sysupdate.");
        break;
    case 6551:
        printf("Software Update Manager.");
        break;
    case 6566:
        printf("SANE Control Port.");
        break;
    case 6568:
        printf("CanIt Storage Manager.");
        break;
    case 6579:
        printf("Affiliate.");
        break;
    case 6580:
        printf("Parsec Masterserver.");
        break;
    case 6581:
        printf("Parsec Peer-to-Peer.");
        break;
    case 6582:
        printf("Parsec Gameserver.");
        break;
    case 6583:
        printf("JOA Jewel Suite.");
        break;
    case 6600:
        printf("Microsoft Hyper-V Live Migration.");
        break;
    case 6601:
        printf("Microsoft Threat Management Gateway SSTP.");
        break;
    case 6602:
        printf("Windows WSS Communication Framework.");
        break;
    case 6619:
        printf("ODETTE-FTP over TLS/SSL.");
        break;
    case 6620:
        printf("Kerberos V5 FTP Data.");
        break;
    case 6621:
        printf("Kerberos V5 FTP Control.");
        break;
    case 6622:
        printf("Multicast FTP.");
        break;
    case 6623:
        printf("Kerberos V5 Telnet.");
        break;
    case 6624:
        printf("DataScaler database.");
        break;
    case 6625:
        printf("DataScaler control.");
        break;
    case 6626:
        printf("WAGO Service and Update.");
        break;
    case 6627:
        printf("Allied Electronics NeXGen.");
        break;
    case 6628:
        printf("AFE Stock Channel M/C.");
        break;
    case 6629:
        printf("Secondary, (non ANDI) multi-protocol multi-function interface to the Allied ANDI-based family of forecourt controllers.");
        break;
    case 6632:
        printf("eGenix mxODBC Connect.");
        break;
    case 6640:
        printf("Open vSwitch Database protocol.");
        break;
    case 6653:
        printf("OpenFlow.");
        break;
    case 6655:
        printf("PC SOFT - Software factory UI/manager.");
        break;
    case 6656:
        printf("Emergency Message Control Service.");
        break;
    case 6665:
        printf("IRCU.");
        break;
    case 6666:
        printf("IRCU.");
        break;
    case 6667:
        printf("IRCU.");
        break;
    case 6668:
        printf("IRCU.");
        break;
    case 6669:
        printf("IRCU.");
        break;
    case 6670:
        printf("Vocaltec Global Online Directory.");
        break;
    case 6671:
        printf("P4P Portal Service.");
        break;
    case 6672:
        printf("vision_server.");
        break;
    case 6673:
        printf("vision_elmd.");
        break;
    case 6678:
        printf("Viscount Freedom Bridge Protocol.");
        break;
    case 6679:
        printf("Osorno Automation.");
        break;
    case 6687:
        printf("CleverView for cTrace Message Service.");
        break;
    case 6688:
        printf("CleverView for TCP/IP Message Service.");
        break;
    case 6689:
        printf("Tofino Security Appliance.");
        break;
    case 6690:
        printf("CLEVERDetect Message Service.");
        break;
    case 6697:
        printf("Internet Relay Chat via TLS/SSL.");
        break;
    case 6701:
        printf("KTI/ICAD Nameserver.");
        break;
    case 6702:
        printf("e-Design network.");
        break;
    case 6703:
        printf("e-Design web.");
        break;
    case 6714:
        printf("Internet Backplane Protocol.");
        break;
    case 6715:
        printf("Fibotrader Communications.");
        break;
    case 6716:
        printf("Princity Agent.");
        break;
    case 6767:
        printf("BMC PERFORM AGENT.");
        break;
    case 6768:
        printf("BMC PERFORM MGRD.");
        break;
    case 6769:
        printf("ADInstruments GxP Server.");
        break;
    case 6770:
        printf("PolyServe http.");
        break;
    case 6771:
        printf("PolyServe https.");
        break;
    case 6777:
        printf("netTsunami Tracker.");
        break;
    case 6778:
        printf("netTsunami p2p storage system.");
        break;
    case 6785:
        printf("DGPF Individual Exchange.");
        break;
    case 6786:
        printf("Sun Java Web Console JMX.");
        break;
    case 6787:
        printf("Sun Web Console Admin.");
        break;
    case 6788:
        printf("SMC-HTTP.");
        break;
    case 6789:
        printf("GSS-API for the Oracle Remote Administration Daemon.");
        break;
    case 6790:
        printf("HNMP.");
        break;
    case 6791:
        printf("Halcyon Network Manager.");
        break;
    case 6801:
        printf("ACNET Control System Protocol.");
        break;
    case 6817:
        printf("PenTBox Secure IM Protocol.");
        break;
    case 6831:
        printf("ambit-lm.");
        break;
    case 6841:
        printf("Netmo Default.");
        break;
    case 6842:
        printf("Netmo HTTP.");
        break;
    case 6850:
        printf("ICCRUSHMORE.");
        break;
    case 6868:
        printf("Acctopus Command Channel.");
        break;
    case 6888:
        printf("MUSE.");
        break;
    case 6900:
        printf("R*TIME Viewer Data Interface.");
        break;
    case 6901:
        printf("Novell Jetstream messaging protocol.");
        break;
    case 6935:
        printf("EthoScan Service.");
        break;
    case 6936:
        printf("XenSource Management Service.");
        break;
    case 6946:
        printf("Biometrics Server.");
        break;
    case 6951:
        printf("OTLP.");
        break;
    case 6961:
        printf("JMACT3.");
        break;
    case 6962:
        printf("jmevt2.");
        break;
    case 6963:
        printf("swismgr1.");
        break;
    case 6964:
        printf("swismgr2.");
        break;
    case 6965:
        printf("swistrap.");
        break;
    case 6966:
        printf("swispol.");
        break;
    case 6969:
        printf("acmsoda.");
        break;
    case 6970:
        printf("Conductor test coordination protocol.");
        break;
    case 6997:
        printf("Mobility XE Protocol.");
        break;
    case 6998:
        printf("IATP-highPri.");
        break;
    case 6999:
        printf("IATP-normalPri.");
        break;
    case 7000:
        printf("file server itself.");
        break;
    case 7001:
        printf("callbacks to cache managers.");
        break;
    case 7002:
        printf("users & groups database.");
        break;
    case 7003:
        printf("volume location database.");
        break;
    case 7004:
        printf("AFS/Kerberos authentication service.");
        break;
    case 7005:
        printf("volume managment server.");
        break;
    case 7006:
        printf("error interpretation service.");
        break;
    case 7007:
        printf("basic overseer process.");
        break;
    case 7008:
        printf("server-to-server updater.");
        break;
    case 7009:
        printf("remote cache manager service.");
        break;
    case 7010:
        printf("onlinet uninterruptable power supplies.");
        break;
    case 7011:
        printf("Talon Discovery Port.");
        break;
    case 7012:
        printf("Talon Engine.");
        break;
    case 7013:
        printf("Microtalon Discovery.");
        break;
    case 7014:
        printf("Microtalon Communications.");
        break;
    case 7015:
        printf("Talon Webserver.");
        break;
    case 7016:
        printf("SPG Controls Carrier.");
        break;
    case 7017:
        printf("GeneRic Autonomic Signaling Protocol.");
        break;
    case 7018:
        printf("FISA Service.");
        break;
    case 7019:
        printf("doceri drawing service control.");
        break;
    case 7020:
        printf("DP Serve.");
        break;
    case 7021:
        printf("DP Serve Admin.");
        break;
    case 7022:
        printf("CT Discovery Protocol.");
        break;
    case 7023:
        printf("Comtech T2 NMCS.");
        break;
    case 7024:
        printf("Vormetric service.");
        break;
    case 7025:
        printf("Vormetric Service II.");
        break;
    case 7026:
        printf("Loreji Webhosting Panel.");
        break;
    case 7030:
        printf("ObjectPlanet probe.");
        break;
    case 7031:
        printf("IPOSPLANET retailing multi devices protocol.");
        break;
    case 7070:
        printf("ARCP.");
        break;
    case 7071:
        printf("IWGADTS Aircraft Housekeeping Message.");
        break;
    case 7072:
        printf("iba Device Configuration Protocol.");
        break;
    case 7073:
        printf("MarTalk protocol.");
        break;
    case 7080:
        printf("EmpowerID Communication.");
        break;
    case 7099:
        printf("lazy-ptop.");
        break;
    case 7100:
        printf("X Font Service.");
        break;
    case 7101:
        printf("Embedded Light Control Network.");
        break;
    case 7117:
        printf("Encrypted chat and file transfer service.");
        break;
    case 7121:
        printf("Virtual Prototypes License Manager.");
        break;
    case 7128:
        printf("intelligent data manager.");
        break;
    case 7129:
        printf("Catalog Content Search.");
        break;
    case 7161:
        printf("CA BSM Comm.");
        break;
    case 7162:
        printf("CA Storage Manager.");
        break;
    case 7163:
        printf("CA Connection Broker.");
        break;
    case 7164:
        printf("File System Repository Agent.");
        break;
    case 7165:
        printf("Document WCF Server.");
        break;
    case 7166:
        printf("Aruba eDiscovery Server.");
        break;
    case 7167:
        printf("CA SRM Agent.");
        break;
    case 7168:
        printf("cncKadServer DB & Inventory Services.");
        break;
    case 7169:
        printf("Consequor Consulting Process Integration Bridge.");
        break;
    case 7170:
        printf("Adaptive Name/Service Resolution.");
        break;
    case 7171:
        printf("Discovery and Retention Mgt Production.");
        break;
    case 7172:
        printf("Port used for MetalBend programmable interface.");
        break;
    case 7173:
        printf("zSecure Server.");
        break;
    case 7174:
        printf("Clutild.");
        break;
    case 7200:
        printf("FODMS FLIP.");
        break;
    case 7201:
        printf("DLIP.");
        break;
    case 7202:
        printf("Inter-Channel Termination Protocol (ICTP) for multi-wavelength PON(Passive Optical Network) systems.");
        break;
    case 7215:
        printf("Communication ports for PaperStream Server services.");
        break;
    case 7216:
        printf("PaperStream Capture Professional.");
        break;
    case 7227:
        printf("Registry A & M Protocol.");
        break;
    case 7228:
        printf("Citrix Universal Printing Port.");
        break;
    case 7229:
        printf("Citrix UPP Gateway.");
        break;
    case 7236:
        printf("Wi-Fi Alliance Wi-Fi Display Protocol.");
        break;
    case 7237:
        printf("PADS (Public Area Display System) Server.");
        break;
    case 7244:
        printf("FrontRow Calypso Human Interface Control Protocol.");
        break;
    case 7262:
        printf("Calypso Network Access Protocol.");
        break;
    case 7272:
        printf("WatchMe Monitoring 7272.");
        break;
    case 7273:
        printf("OMA Roaming Location.");
        break;
    case 7274:
        printf("OMA Roaming Location SEC.");
        break;
    case 7275:
        printf("OMA UserPlane Location.");
        break;
    case 7276:
        printf("OMA Internal Location Protocol.");
        break;
    case 7277:
        printf("OMA Internal Location Secure Protocol.");
        break;
    case 7278:
        printf("OMA Dynamic Content Delivery over CBS.");
        break;
    case 7279:
        printf("Citrix Licensing.");
        break;
    case 7280:
        printf("ITACTIONSERVER 1.");
        break;
    case 7281:
        printf("ITACTIONSERVER 2.");
        break;
    case 7282:
        printf("eventACTION/ussACTION (MZCA) server.");
        break;
    case 7283:
        printf("General Statistics Rendezvous Protocol.");
        break;
    case 7365:
        printf("LifeKeeper Communications.");
        break;
    case 7391:
        printf("mind-file system server.");
        break;
    case 7392:
        printf("mrss-rendezvous server.");
        break;
    case 7393:
        printf("nFoldMan Remote Publish.");
        break;
    case 7394:
        printf("File system export of backup images.");
        break;
    case 7395:
        printf("winqedit.");
        break;
    case 7397:
        printf("Hexarc Command Language.");
        break;
    case 7400:
        printf("RTPS Discovery.");
        break;
    case 7401:
        printf("RTPS Data-Distribution User-Traffic.");
        break;
    case 7402:
        printf("RTPS Data-Distribution Meta-Traffic.");
        break;
    case 7410:
        printf("Ionix Network Monitor.");
        break;
    case 7411:
        printf("Streaming of measurement data.");
        break;
    case 7421:
        printf("Matisse Port Monitor.");
        break;
    case 7426:
        printf("OpenView DM Postmaster Manager.");
        break;
    case 7427:
        printf("OpenView DM Event Agent Manager.");
        break;
    case 7428:
        printf("OpenView DM Log Agent Manager.");
        break;
    case 7429:
        printf("OpenView DM rqt communication.");
        break;
    case 7430:
        printf("OpenView DM xmpv7 api pipe.");
        break;
    case 7431:
        printf("OpenView DM ovc/xmpv3 api pipe.");
        break;
    case 7437:
        printf("Faximum.");
        break;
    case 7443:
        printf("Oracle Application Server HTTPS.");
        break;
    case 7471:
        printf("Stateless Transport Tunneling Protocol.");
        break;
    case 7473:
        printf("Rise: The Vieneo Province.");
        break;
    case 7474:
        printf("Neo4j Graph Database.");
        break;
    case 7478:
        printf("IT Asset Management.");
        break;
    case 7491:
        printf("telops-lmd.");
        break;
    case 7500:
        printf("Silhouette User.");
        break;
    case 7501:
        printf("HP OpenView Bus Daemon.");
        break;
    case 7508:
        printf("Automation Device Configuration Protocol.");
        break;
    case 7509:
        printf("ACPLT - process automation service.");
        break;
    case 7510:
        printf("HP OpenView Application Server.");
        break;
    case 7511:
        printf("pafec-lm.");
        break;
    case 7542:
        printf("Saratoga Transfer Protocol.");
        break;
    case 7543:
        printf("atul server.");
        break;
    case 7544:
        printf("FlowAnalyzer DisplayServer.");
        break;
    case 7545:
        printf("FlowAnalyzer UtilityServer.");
        break;
    case 7546:
        printf("Cisco Fabric service.");
        break;
    case 7547:
        printf("DSL Forum CWMP.");
        break;
    case 7548:
        printf("Threat Information Distribution Protocol.");
        break;
    case 7549:
        printf("Network Layer Signaling Transport Layer.");
        break;
    case 7551:
        printf("ControlONE Console signaling.");
        break;
    case 7560:
        printf("Sniffer Command Protocol.");
        break;
    case 7563:
        printf("Control Framework.");
        break;
    case 7566:
        printf("VSI Omega.");
        break;
    case 7569:
        printf("Dell EqualLogic Host Group Management.");
        break;
    case 7570:
        printf("Aries Kfinder.");
        break;
    case 7574:
        printf("Oracle Coherence Cluster Service.");
        break;
    case 7588:
        printf("Sun License Manager.");
        break;
    case 7606:
        printf("MIPI Alliance Debug.");
        break;
    case 7624:
        printf("Instrument Neutral Distributed Interface.");
        break;
    case 7626:
        printf("SImple Middlebox COnfiguration (SIMCO) Server.");
        break;
    case 7627:
        printf("SOAP Service Port.");
        break;
    case 7628:
        printf("Primary Agent Work Notification.");
        break;
    case 7629:
        printf("OpenXDAS Wire Protocol.");
        break;
    case 7630:
        printf("HA Web Konsole.");
        break;
    case 7631:
        printf("TESLA System Messaging.");
        break;
    case 7633:
        printf("PMDF Management.");
        break;
    case 7648:
        printf("bonjour-cuseeme.");
        break;
    case 7663:
        printf("Proprietary immutable distributed data storage.");
        break;
    case 7672:
        printf("iMQ STOMP Server.");
        break;
    case 7673:
        printf("iMQ STOMP Server over SSL.");
        break;
    case 7674:
        printf("iMQ SSL tunnel.");
        break;
    case 7675:
        printf("iMQ Tunnel.");
        break;
    case 7676:
        printf("iMQ Broker Rendezvous.");
        break;
    case 7677:
        printf("Sun App Server - HTTPS.");
        break;
    case 7680:
        printf("Pando Media Public Distribution.");
        break;
    case 7683:
        printf("Cleondris DMT.");
        break;
    case 7687:
        printf("Bolt database connection.");
        break;
    case 7689:
        printf("Collaber Network Service.");
        break;
    case 7697:
        printf("KLIO communications.");
        break;
    case 7700:
        printf("EM7 Secure Communications.");
        break;
    case 7707:
        printf("EM7 Dynamic Updates.");
        break;
    case 7708:
        printf("scientia.net.");
        break;
    case 7720:
        printf("MedImage Portal.");
        break;
    case 7724:
        printf("Novell Snap-in Deep Freeze Control.");
        break;
    case 7725:
        printf("Nitrogen Service.");
        break;
    case 7726:
        printf("FreezeX Console Service.");
        break;
    case 7727:
        printf("Trident Systems Data.");
        break;
    case 7728:
        printf("Open-Source Virtual Reality.");
        break;
    case 7734:
        printf("Smith Protocol over IP.");
        break;
    case 7738:
        printf("HP Enterprise Discovery Agent.");
        break;
    case 7741:
        printf("ScriptView Network.");
        break;
    case 7742:
        printf("Mugginsoft Script Server Service.");
        break;
    case 7743:
        printf("Sakura Script Transfer Protocol.");
        break;
    case 7744:
        printf("RAQMON PDU.");
        break;
    case 7747:
        printf("Put/Run/Get Protocol.");
        break;
    case 7775:
        printf("A File System using TLS over a wide area network.");
        break;
    case 7777:
        printf("cbt.");
        break;
    case 7778:
        printf("Interwise.");
        break;
    case 7779:
        printf("VSTAT.");
        break;
    case 7781:
        printf("accu-lmgr.");
        break;
    case 7786:
        printf("MINIVEND.");
        break;
    case 7787:
        printf("Popup Reminders Receive.");
        break;
    case 7789:
        printf("Office Tools Pro Receive.");
        break;
    case 7794:
        printf("Q3ADE Cluster Service.");
        break;
    case 7797:
        printf("Propel Connector port.");
        break;
    case 7798:
        printf("Propel Encoder port.");
        break;
    case 7799:
        printf("Alternate BSDP Service.");
        break;
    case 7800:
        printf("Apple Software Restore.");
        break;
    case 7801:
        printf("Secure Server Protocol - client.");
        break;
    case 7810:
        printf("Riverbed WAN Optimization Protocol.");
        break;
    case 7845:
        printf("APC 7845.");
        break;
    case 7846:
        printf("APC 7846.");
        break;
    case 7847:
        printf("A product key authentication protocol made by CSO.");
        break;
    case 7869:
        printf("MobileAnalyzer& MobileMonitor.");
        break;
    case 7870:
        printf("Riverbed Steelhead Mobile Service.");
        break;
    case 7871:
        printf("Mobile Device Management.");
        break;
    case 7878:
        printf("Opswise Message Service.");
        break;
    case 7880:
        printf("Pearson.");
        break;
    case 7887:
        printf("Universal Broker.");
        break;
    case 7900:
        printf("Multicast Event.");
        break;
    case 7901:
        printf("TNOS Service Protocol.");
        break;
    case 7902:
        printf("TNOS shell Protocol.");
        break;
    case 7903:
        printf("TNOS Secure DiaguardProtocol.");
        break;
    case 7913:
        printf("QuickObjects secure port.");
        break;
    case 7932:
        printf("Tier 2 Data Resource Manager.");
        break;
    case 7933:
        printf("Tier 2 Business Rules Manager.");
        break;
    case 7962:
        printf("Encrypted, extendable, general-purpose synchronization protocol.");
        break;
    case 7967:
        printf("Supercell.");
        break;
    case 7979:
        printf("Micromuse-ncps.");
        break;
    case 7980:
        printf("Quest Vista.");
        break;
    case 7981:
        printf("Spotlight on SQL Server Desktop Collect.");
        break;
    case 7982:
        printf("Spotlight on SQL Server Desktop Agent.");
        break;
    case 7997:
        printf("PUSH Notification Service.");
        break;
    case 7999:
        printf("iRDMI2.");
        break;
    case 8000:
        printf("iRDMI.");
        break;
    case 8001:
        printf("VCOM Tunnel.");
        break;
    case 8002:
        printf("Teradata ORDBMS.");
        break;
    case 8003:
        printf("Mulberry Connect Reporting Service.");
        break;
    case 8004:
        printf("Opensource Evolv Enterprise Platform P2P Network Node Connection Protocol.");
        break;
    case 8005:
        printf("MXI Generation II for z/OS.");
        break;
    case 8006:
        printf("World Programming analytics.");
        break;
    case 8007:
        printf("I/O oriented cluster computing software.");
        break;
    case 8008:
        printf("HTTP Alternate.");
        break;
    case 8009:
        printf("NVMe over Fabrics Discovery Service.");
        break;
    case 8019:
        printf("QB DB Dynamic Port.");
        break;
    case 8020:
        printf("Intuit Entitlement Service and Discovery.");
        break;
    case 8021:
        printf("Intuit Entitlement Client.");
        break;
    case 8022:
        printf("oa-system.");
        break;
    case 8025:
        printf("CA Audit Distribution Agent.");
        break;
    case 8026:
        printf("CA Audit Distribution Server.");
        break;
    case 8032:
        printf("ProEd.");
        break;
    case 8033:
        printf("MindPrint.");
        break;
    case 8034:
        printf(".vantronix Management.");
        break;
    case 8040:
        printf("Ampify Messaging Protocol.");
        break;
    case 8041:
        printf("Xcorpeon ASIC Carrier Ethernet Transport.");
        break;
    case 8042:
        printf("FireScope Agent.");
        break;
    case 8043:
        printf("FireScope Server.");
        break;
    case 8044:
        printf("FireScope Management Interface.");
        break;
    case 8051:
        printf("Rocrail Client Service.");
        break;
    case 8052:
        printf("Senomix Timesheets Server.");
        break;
    case 8053:
        printf("Senomix Timesheets Client [1 year assignment].");
        break;
    case 8054:
        printf("Senomix Timesheets Server [1 year assignment].");
        break;
    case 8055:
        printf("Senomix Timesheets Server [1 year assignment].");
        break;
    case 8056:
        printf("Senomix Timesheets Server [1 year assignment].");
        break;
    case 8057:
        printf("Senomix Timesheets Client [1 year assignment].");
        break;
    case 8058:
        printf("Senomix Timesheets Client [1 year assignment].");
        break;
    case 8059:
        printf("Senomix Timesheets Client [1 year assignment].");
        break;
    case 8066:
        printf("Toad BI Application Server.");
        break;
    case 8067:
        printf("Infinidat async replication.");
        break;
    case 8070:
        printf("Oracle Unified Communication Suite's Indexed Search Converter.");
        break;
    case 8074:
        printf("Gadu-Gadu.");
        break;
    case 8077:
        printf("Mles.");
        break;
    case 8080:
        printf("HTTP Alternate (see port 80).");
        break;
    case 8081:
        printf("Sun Proxy Admin Service.");
        break;
    case 8082:
        printf("Utilistor (Client).");
        break;
    case 8083:
        printf("Utilistor (Server).");
        break;
    case 8086:
        printf("Distributed SCADA Networking Rendezvous Port.");
        break;
    case 8087:
        printf("Simplify Media SPP Protocol.");
        break;
    case 8088:
        printf("Radan HTTP.");
        break;
    case 8090:
        printf("Vehicle to station messaging.");
        break;
    case 8091:
        printf("Jam Link Framework.");
        break;
    case 8097:
        printf("SAC Port Id.");
        break;
    case 8100:
        printf("Xprint Server.");
        break;
    case 8101:
        printf("Logical Domains Migration.");
        break;
    case 8102:
        printf("Oracle Kernel zones migration server.");
        break;
    case 8115:
        printf("MTL8000 Matrix.");
        break;
    case 8116:
        printf("Check Point Clustering.");
        break;
    case 8117:
        printf("Purity replication clustering and remote management.");
        break;
    case 8118:
        printf("Privoxy HTTP proxy.");
        break;
    case 8121:
        printf("Apollo Data Port.");
        break;
    case 8122:
        printf("Apollo Admin Port.");
        break;
    case 8128:
        printf("PayCash Online Protocol.");
        break;
    case 8129:
        printf("PayCash Wallet-Browser.");
        break;
    case 8130:
        printf("INDIGO-VRMI.");
        break;
    case 8131:
        printf("INDIGO-VBCP.");
        break;
    case 8132:
        printf("dbabble.");
        break;
    case 8140:
        printf("The Puppet master service.");
        break;
    case 8148:
        printf("i-SDD file transfer.");
        break;
    case 8153:
        printf("QuantaStor Management Interface.");
        break;
    case 8160:
        printf("Patrol.");
        break;
    case 8161:
        printf("Patrol SNMP.");
        break;
    case 8162:
        printf("LPAR2RRD client server communication.");
        break;
    case 8181:
        printf("Intermapper network management system.");
        break;
    case 8182:
        printf("VMware Fault Domain Manager.");
        break;
    case 8183:
        printf("ProRemote.");
        break;
    case 8184:
        printf("Remote iTach Connection.");
        break;
    case 8190:
        printf("Generic control plane for RPHY.");
        break;
    case 8191:
        printf("Limner Pressure.");
        break;
    case 8192:
        printf("SpyTech Phone Service.");
        break;
    case 8194:
        printf("Bloomberg data API.");
        break;
    case 8195:
        printf("Bloomberg feed.");
        break;
    case 8199:
        printf("VVR DATA.");
        break;
    case 8200:
        printf("TRIVNET.");
        break;
    case 8201:
        printf("TRIVNET.");
        break;
    case 8204:
        printf("LM Perfworks.");
        break;
    case 8205:
        printf("LM Instmgr.");
        break;
    case 8206:
        printf("LM Dta.");
        break;
    case 8207:
        printf("LM SServer.");
        break;
    case 8208:
        printf("LM Webwatcher.");
        break;
    case 8230:
        printf("RexecJ Server.");
        break;
    case 8243:
        printf("Synapse Non Blocking HTTPS.");
        break;
    case 8270:
        printf("Robot Framework Remote Library Interface.");
        break;
    case 8276:
        printf("Pando Media Controlled Distribution.");
        break;
    case 8280:
        printf("Synapse Non Blocking HTTP.");
        break;
    case 8282:
        printf("Libelle EnterpriseBus.");
        break;
    case 8292:
        printf("Bloomberg professional.");
        break;
    case 8293:
        printf("Hiperscan Identification Service.");
        break;
    case 8294:
        printf("Bloomberg intelligent client.");
        break;
    case 8300:
        printf("Transport Management Interface.");
        break;
    case 8301:
        printf("Amberon PPC/PPS.");
        break;
    case 8313:
        printf("Hub Open Network.");
        break;
    case 8320:
        printf("Thin(ium) Network Protocol.");
        break;
    case 8321:
        printf("Thin(ium) Network Protocol.");
        break;
    case 8322:
        printf("Garmin Marine.");
        break;
    case 8351:
        printf("Server Find.");
        break;
    case 8376:
        printf("Cruise ENUM.");
        break;
    case 8377:
        printf("Cruise SWROUTE.");
        break;
    case 8378:
        printf("Cruise CONFIG.");
        break;
    case 8379:
        printf("Cruise DIAGS.");
        break;
    case 8380:
        printf("Cruise UPDATE.");
        break;
    case 8383:
        printf("M2m Services.");
        break;
    case 8400:
        printf("cvd.");
        break;
    case 8401:
        printf("sabarsd.");
        break;
    case 8402:
        printf("abarsd.");
        break;
    case 8403:
        printf("admind.");
        break;
    case 8404:
        printf("SuperVault Cloud.");
        break;
    case 8405:
        printf("SuperVault Backup.");
        break;
    case 8415:
        printf("Delphix Session Protocol.");
        break;
    case 8416:
        printf("eSpeech Session Protocol.");
        break;
    case 8417:
        printf("eSpeech RTP Protocol.");
        break;
    case 8423:
        printf("Aristech text-to-speech server.");
        break;
    case 8442:
        printf("CyBro A-bus Protocol.");
        break;
    case 8443:
        printf("PCsync HTTPS.");
        break;
    case 8444:
        printf("PCsync HTTP.");
        break;
    case 8445:
        printf("Port for copy peer sync feature.");
        break;
    case 8450:
        printf("npmp.");
        break;
    case 8457:
        printf("Nexenta Management GUI.");
        break;
    case 8470:
        printf("Cisco Address Validation Protocol.");
        break;
    case 8471:
        printf("PIM over Reliable Transport.");
        break;
    case 8472:
        printf("Overlay Transport Virtualization (OTV).");
        break;
    case 8473:
        printf("Virtual Point to Point.");
        break;
    case 8474:
        printf("AquaMinds NoteShare.");
        break;
    case 8500:
        printf("Flight Message Transfer Protocol.");
        break;
    case 8501:
        printf("CYTEL Message Transfer Management.");
        break;
    case 8502:
        printf("FTN Message Transfer Protocol.");
        break;
    case 8554:
        printf("RTSP Alternate (see port 554).");
        break;
    case 8555:
        printf("SYMAX D-FENCE.");
        break;
    case 8567:
        printf("DOF Tunneling Protocol.");
        break;
    case 8600:
        printf("Surveillance Data.");
        break;
    case 8610:
        printf("Canon MFNP Service.");
        break;
    case 8611:
        printf("Canon BJNP Port 1.");
        break;
    case 8612:
        printf("Canon BJNP Port 2.");
        break;
    case 8613:
        printf("Canon BJNP Port 3.");
        break;
    case 8614:
        printf("Canon BJNP Port 4.");
        break;
    case 8615:
        printf("Imink Service Control.");
        break;
    case 8665:
        printf("Monetra.");
        break;
    case 8666:
        printf("Monetra Administrative Access.");
        break;
    case 8675:
        printf("Motorola Solutions Customer Programming Software for Radio Management.");
        break;
    case 8686:
        printf("Sun App Server - JMX/RMI.");
        break;
    case 8688:
        printf("OpenRemote Controller HTTP/REST.");
        break;
    case 8699:
        printf("VNYX Primary Port.");
        break;
    case 8711:
        printf("Nuance Voice Control.");
        break;
    case 8733:
        printf("iBus.");
        break;
    case 8750:
        printf("DEY Storage Key Negotiation.");
        break;
    case 8763:
        printf("MC-APPSERVER.");
        break;
    case 8764:
        printf("OPENQUEUE.");
        break;
    case 8765:
        printf("Ultraseek HTTP.");
        break;
    case 8766:
        printf("Agilent Connectivity Service.");
        break;
    case 8770:
        printf("Digital Photo Access Protocol (iPhoto).");
        break;
    case 8778:
        printf("Stonebranch Universal Enterprise Controller.");
        break;
    case 8786:
        printf("Message Client.");
        break;
    case 8787:
        printf("Message Server.");
        break;
    case 8793:
        printf("Accedian Performance Measurement.");
        break;
    case 8800:
        printf("Sun Web Server Admin Service.");
        break;
    case 8804:
        printf("truecm.");
        break;
    case 8873:
        printf("dxspider linking protocol.");
        break;
    case 8880:
        printf("CDDBP.");
        break;
    case 8881:
        printf("Galaxy4D Online Game Engine.");
        break;
    case 8883:
        printf("Secure MQTT.");
        break;
    case 8888:
        printf("NewsEDGE server TCP (TCP 1).");
        break;
    case 8889:
        printf("Desktop Data TCP 1.");
        break;
    case 8890:
        printf("Desktop Data TCP 2.");
        break;
    case 8891:
        printf("Desktop Data TCP 3: NESS application.");
        break;
    case 8892:
        printf("Desktop Data TCP 4: FARM product.");
        break;
    case 8893:
        printf("Desktop Data TCP 5: NewsEDGE/Web application.");
        break;
    case 8894:
        printf("Desktop Data TCP 6: COAL application.");
        break;
    case 8899:
        printf("ospf-lite.");
        break;
    case 8900:
        printf("JMB-CDS 1.");
        break;
    case 8901:
        printf("JMB-CDS 2.");
        break;
    case 8910:
        printf("manyone-http.");
        break;
    case 8911:
        printf("manyone-xml.");
        break;
    case 8912:
        printf("Windows Client Backup.");
        break;
    case 8913:
        printf("Dragonfly System Service.");
        break;
    case 8937:
        printf("Transaction Warehouse Data Service.");
        break;
    case 8953:
        printf("unbound dns nameserver control.");
        break;
    case 8954:
        printf("Cumulus Admin Port.");
        break;
    case 8980:
        printf("Network of Devices Provider.");
        break;
    case 8989:
        printf("Sun Web Server SSL Admin Service.");
        break;
    case 8990:
        printf("webmail HTTP service.");
        break;
    case 8991:
        printf("webmail HTTPS service.");
        break;
    case 8997:
        printf("Oracle Messaging Server Event Notification Service.");
        break;
    case 8998:
        printf("Canto RoboFlow Control.");
        break;
    case 8999:
        printf("Brodos Crypto Trade Protocol.");
        break;
    case 9000:
        printf("CSlistener.");
        break;
    case 9001:
        printf("ETL Service Manager.");
        break;
    case 9002:
        printf("DynamID authentication.");
        break;
    case 9005:
        printf("Golem Inter-System RPC.");
        break;
    case 9008:
        printf("Open Grid Services Server.");
        break;
    case 9009:
        printf("Pichat Server.");
        break;
    case 9010:
        printf("Secure Data Replicator Protocol.");
        break;
    case 9020:
        printf("TAMBORA.");
        break;
    case 9021:
        printf("Pangolin Identification.");
        break;
    case 9022:
        printf("PrivateArk Remote Agent.");
        break;
    case 9023:
        printf("Secure Web Access - 1.");
        break;
    case 9024:
        printf("Secure Web Access - 2.");
        break;
    case 9025:
        printf("Secure Web Access - 3.");
        break;
    case 9026:
        printf("Secure Web Access - 4.");
        break;
    case 9050:
        printf("Versiera Agent Listener.");
        break;
    case 9051:
        printf("Fusion-io Central Manager Service.");
        break;
    case 9060:
        printf("CardWeb request-response I/O exchange.");
        break;
    case 9080:
        printf("Groove GLRPC.");
        break;
    case 9083:
        printf("EMC PowerPath Mgmt Service.");
        break;
    case 9084:
        printf("IBM AURORA Performance Visualizer.");
        break;
    case 9085:
        printf("IBM Remote System Console.");
        break;
    case 9086:
        printf("Vesa Net2Display.");
        break;
    case 9087:
        printf("Classic Data Server.");
        break;
    case 9088:
        printf("IBM Informix SQL Interface.");
        break;
    case 9089:
        printf("IBM Informix SQL Interface - Encrypted.");
        break;
    case 9090:
        printf("WebSM.");
        break;
    case 9091:
        printf("xmltec-xmlmail.");
        break;
    case 9092:
        printf("Xml-Ipc Server Reg.");
        break;
    case 9093:
        printf("Copycat database replication service.");
        break;
    case 9100:
        printf("PDL Data Streaming Port.");
        break;
    case 9101:
        printf("Bacula Director.");
        break;
    case 9102:
        printf("Bacula File Daemon.");
        break;
    case 9103:
        printf("Bacula Storage Daemon.");
        break;
    case 9104:
        printf("PeerWire.");
        break;
    case 9105:
        printf("Xadmin Control Service.");
        break;
    case 9106:
        printf("Astergate Control Service.");
        break;
    case 9107:
        printf("AstergateFax Control Service.");
        break;
    case 9119:
        printf("MXit Instant Messaging.");
        break;
    case 9122:
        printf("Global Relay compliant mobile instant messaging protocol.");
        break;
    case 9123:
        printf("Global Relay compliant instant messaging protocol.");
        break;
    case 9131:
        printf("Dynamic Device Discovery.");
        break;
    case 9160:
        printf("apani1.");
        break;
    case 9161:
        printf("apani2.");
        break;
    case 9162:
        printf("apani3.");
        break;
    case 9163:
        printf("apani4.");
        break;
    case 9164:
        printf("apani5.");
        break;
    case 9191:
        printf("Sun AppSvr JPDA.");
        break;
    case 9200:
        printf("WAP connectionless session service.");
        break;
    case 9201:
        printf("WAP session service.");
        break;
    case 9202:
        printf("WAP secure connectionless session service.");
        break;
    case 9203:
        printf("WAP secure session service.");
        break;
    case 9204:
        printf("WAP vCard.");
        break;
    case 9205:
        printf("WAP vCal.");
        break;
    case 9206:
        printf("WAP vCard Secure.");
        break;
    case 9207:
        printf("WAP vCal Secure.");
        break;
    case 9208:
        printf("rjcdb vCard.");
        break;
    case 9209:
        printf("ALMobile System Service.");
        break;
    case 9210:
        printf("OMA Mobile Location Protocol.");
        break;
    case 9211:
        printf("OMA Mobile Location Protocol Secure.");
        break;
    case 9212:
        printf("Server View dbms access.");
        break;
    case 9213:
        printf("ServerStart RemoteControl.");
        break;
    case 9214:
        printf("IPDC ESG BootstrapService.");
        break;
    case 9215:
        printf("Integrated Setup and Install Service.");
        break;
    case 9216:
        printf("Aionex Communication Management Engine.");
        break;
    case 9217:
        printf("FSC Communication Port.");
        break;
    case 9222:
        printf("QSC Team Coherence.");
        break;
    case 9255:
        printf("Manager On Network.");
        break;
    case 9278:
        printf("Pegasus GPS Platform.");
        break;
    case 9279:
        printf("Pegaus GPS System Control Interface.");
        break;
    case 9280:
        printf("Predicted GPS.");
        break;
    case 9281:
        printf("SofaWare transport port 1.");
        break;
    case 9282:
        printf("SofaWare transport port 2.");
        break;
    case 9283:
        printf("CallWaveIAM.");
        break;
    case 9284:
        printf("VERITAS Information Serve.");
        break;
    case 9285:
        printf("N2H2 Filter Service Port.");
        break;
    case 9287:
        printf("Cumulus.");
        break;
    case 9292:
        printf("ArmTech Daemon.");
        break;
    case 9293:
        printf("StorView Client.");
        break;
    case 9294:
        printf("ARMCenter http Service.");
        break;
    case 9295:
        printf("ARMCenter https Service.");
        break;
    case 9300:
        printf("Virtual Racing Service.");
        break;
    case 9306:
        printf("Sphinx search server (MySQL listener).");
        break;
    case 9312:
        printf("Sphinx search server.");
        break;
    case 9318:
        printf("PKIX TimeStamp over TLS.");
        break;
    case 9321:
        printf("guibase.");
        break;
    case 9343:
        printf("MpIdcMgr.");
        break;
    case 9344:
        printf("Mphlpdmc.");
        break;
    case 9345:
        printf("Rancher Agent.");
        break;
    case 9346:
        printf("C Tech Licensing.");
        break;
    case 9374:
        printf("fjdmimgr.");
        break;
    case 9380:
        printf("Brivs! Open Extensible Protocol.");
        break;
    case 9387:
        printf("D2D Configuration Service.");
        break;
    case 9388:
        printf("D2D Data Transfer Service.");
        break;
    case 9389:
        printf("Active Directory Web Services.");
        break;
    case 9390:
        printf("OpenVAS Transfer Protocol.");
        break;
    case 9396:
        printf("fjinvmgr.");
        break;
    case 9397:
        printf("MpIdcAgt.");
        break;
    case 9400:
        printf("Samsung Twain for Network Server.");
        break;
    case 9401:
        printf("Samsung Twain for Network Client.");
        break;
    case 9402:
        printf("Samsung PC2FAX for Network Server.");
        break;
    case 9418:
        printf("git pack transfer service.");
        break;
    case 9443:
        printf("WSO2 Tungsten HTTPS.");
        break;
    case 9444:
        printf("WSO2 ESB Administration Console HTTPS.");
        break;
    case 9445:
        printf("MindArray Systems Console Agent.");
        break;
    case 9450:
        printf("Sentinel Keys Server.");
        break;
    case 9500:
        printf("ismserver.");
        break;
    case 9535:
        printf("Management Suite Remote Control.");
        break;
    case 9536:
        printf("Surveillance buffering function.");
        break;
    case 9555:
        printf("Trispen Secure Remote Access.");
        break;
    case 9592:
        printf("LANDesk Gateway.");
        break;
    case 9593:
        printf("LANDesk Management Agent (cba8).");
        break;
    case 9594:
        printf("Message System.");
        break;
    case 9595:
        printf("Ping Discovery Service.");
        break;
    case 9596:
        printf("Mercury Discovery.");
        break;
    case 9597:
        printf("PD Administration.");
        break;
    case 9598:
        printf("Very Simple Ctrl Protocol.");
        break;
    case 9599:
        printf("Robix.");
        break;
    case 9600:
        printf("MICROMUSE-NCPW.");
        break;
    case 9612:
        printf("StreamComm User Directory.");
        break;
    case 9614:
        printf("iADT Protocol over TLS.");
        break;
    case 9616:
        printf("eRunbook Agent.");
        break;
    case 9617:
        printf("eRunbook Server.");
        break;
    case 9618:
        printf("Condor Collector Service.");
        break;
    case 9628:
        printf("ODBC Pathway Service.");
        break;
    case 9629:
        printf("UniPort SSO Controller.");
        break;
    case 9630:
        printf("Peovica Controller.");
        break;
    case 9631:
        printf("Peovica Collector.");
        break;
    case 9640:
        printf("ProQueSys Flows Service.");
        break;
    case 9666:
        printf("Zoom Control Panel Game Server Management.");
        break;
    case 9667:
        printf("Cross-platform Music Multiplexing System.");
        break;
    case 9668:
        printf("tec5 Spectral Device Control Protocol.");
        break;
    case 9694:
        printf("T-Mobile Client Wakeup Message.");
        break;
    case 9695:
        printf("Content Centric Networking.");
        break;
    case 9700:
        printf("Board M.I.T. Service.");
        break;
    case 9747:
        printf("L5NAS Parallel Channel.");
        break;
    case 9750:
        printf("Board M.I.T. Synchronous Collaboration.");
        break;
    case 9753:
        printf("rasadv.");
        break;
    case 9762:
        printf("WSO2 Tungsten HTTP.");
        break;
    case 9800:
        printf("WebDav Source Port.");
        break;
    case 9801:
        printf("Sakura Script Transfer Protocol-2.");
        break;
    case 9802:
        printf("WebDAV Source TLS/SSL.");
        break;
    case 9875:
        printf("Session Announcement v1.");
        break;
    case 9876:
        printf("Session Director.");
        break;
    case 9888:
        printf("CYBORG Systems.");
        break;
    case 9889:
        printf("Port for Cable network related data proxy or repeater.");
        break;
    case 9898:
        printf("MonkeyCom.");
        break;
    case 9900:
        printf("IUA.");
        break;
    case 9909:
        printf("domaintime.");
        break;
    case 9911:
        printf("SYPECom Transport Protocol.");
        break;
    case 9925:
        printf("XYBRID Cloud.");
        break;
    case 9950:
        printf("APC 9950.");
        break;
    case 9951:
        printf("APC 9951.");
        break;
    case 9952:
        printf("APC 9952.");
        break;
    case 9953:
        printf("9953.");
        break;
    case 9954:
        printf("HaloteC Instrument Network Protocol.");
        break;
    case 9955:
        printf("Contact Port for AllJoyn standard messaging.");
        break;
    case 9966:
        printf("OKI Data Network Setting Protocol.");
        break;
    case 9978:
        printf("XYBRID RT Server.");
        break;
    case 9979:
        printf("Valley Information Systems Weather station data.");
        break;
    case 9981:
        printf("Event sourcing database engine with a built-in programming language.");
        break;
    case 9987:
        printf("DSM/SCM Target Interface.");
        break;
    case 9988:
        printf("Software Essentials Secure HTTP server.");
        break;
    case 9990:
        printf("OSM Applet Server.");
        break;
    case 9991:
        printf("OSM Event Server.");
        break;
    case 9992:
        printf("OnLive-1.");
        break;
    case 9993:
        printf("OnLive-2.");
        break;
    case 9994:
        printf("OnLive-3.");
        break;
    case 9995:
        printf("Palace-4.");
        break;
    case 9996:
        printf("Palace-5.");
        break;
    case 9997:
        printf("Palace-6.");
        break;
    case 9998:
        printf("Distinct32.");
        break;
    case 9999:
        printf("distinct.");
        break;
    case 10000:
        printf("Network Data Management Protocol.");
        break;
    case 10001:
        printf("SCP Configuration.");
        break;
    case 10002:
        printf("EMC-Documentum Content Server Product.");
        break;
    case 10003:
        printf("EMC-Documentum Content Server Product.");
        break;
    case 10004:
        printf("EMC Replication Manager Client.");
        break;
    case 10005:
        printf("EMC Replication Manager Server.");
        break;
    case 10006:
        printf("Sync replication protocol among different NetApp platforms.");
        break;
    case 10007:
        printf("MVS Capacity.");
        break;
    case 10008:
        printf("Octopus Multiplexer.");
        break;
    case 10009:
        printf("Systemwalker Desktop Patrol.");
        break;
    case 10010:
        printf("ooRexx rxapi services.");
        break;
    case 10020:
        printf("Hardware configuration and maintenance.");
        break;
    case 10050:
        printf("Zabbix Agent.");
        break;
    case 10051:
        printf("Zabbix Trapper.");
        break;
    case 10055:
        printf("Quantapoint FLEXlm Licensing Service.");
        break;
    case 10080:
        printf("Amanda.");
        break;
    case 10081:
        printf("FAM Archive Server.");
        break;
    case 10100:
        printf("VERITAS ITAP DDTP.");
        break;
    case 10101:
        printf("eZmeeting.");
        break;
    case 10102:
        printf("eZproxy.");
        break;
    case 10103:
        printf("eZrelay.");
        break;
    case 10104:
        printf("Systemwalker Desktop Patrol.");
        break;
    case 10107:
        printf("VERITAS BCTP, server.");
        break;
    case 10110:
        printf("NMEA-0183 Navigational Data.");
        break;
    case 10113:
        printf("NetIQ Endpoint.");
        break;
    case 10114:
        printf("NetIQ Qcheck.");
        break;
    case 10115:
        printf("NetIQ Endpoint.");
        break;
    case 10116:
        printf("NetIQ VoIP Assessor.");
        break;
    case 10117:
        printf("NetIQ IQCResource Managament Svc.");
        break;
    case 10125:
        printf("HotLink CIMple REST API.");
        break;
    case 10128:
        printf("BMC-PERFORM-SERVICE DAEMON.");
        break;
    case 10129:
        printf("BMC General Manager Server.");
        break;
    case 10160:
        printf("QB Database Server.");
        break;
    case 10161:
        printf("SNMP-TLS.");
        break;
    case 10162:
        printf("SNMP-Trap-TLS.");
        break;
    case 10200:
        printf("Trigence AE Soap Service.");
        break;
    case 10201:
        printf("Remote Server Management Service.");
        break;
    case 10252:
        printf("Apollo Relay Port.");
        break;
    case 10260:
        printf("Axis WIMP Port.");
        break;
    case 10261:
        printf("Tile remote machine learning.");
        break;
    case 10288:
        printf("Blocks.");
        break;
    case 10321:
        printf("Computer Op System Information Report.");
        break;
    case 10540:
        printf("MOS Media Object Metadata Port.");
        break;
    case 10541:
        printf("MOS Running Order Port.");
        break;
    case 10542:
        printf("MOS Low Priority Port.");
        break;
    case 10543:
        printf("MOS SOAP Default Port.");
        break;
    case 10544:
        printf("MOS SOAP Optional Port.");
        break;
    case 10548:
        printf("Apple Document Sharing Service.");
        break;
    case 10631:
        printf("Printopia Serve.");
        break;
    case 10800:
        printf("Gestor de Acaparamiento para Pocket PCs.");
        break;
    case 10805:
        printf("LUCIA Pareja Data Group.");
        break;
    case 10809:
        printf("Linux Network Block Device.");
        break;
    case 10860:
        printf("Helix Client/Server.");
        break;
    case 10880:
        printf("BVEssentials HTTP API.");
        break;
    case 10933:
        printf("Listen port used by the Octopus Deploy Tentacle deployment agent.");
        break;
    case 10990:
        printf("Auxiliary RMI Port.");
        break;
    case 11000:
        printf("IRISA.");
        break;
    case 11001:
        printf("Metasys.");
        break;
    case 11095:
        printf("Nest device-to-device and device-to-service application protocol.");
        break;
    case 11103:
        printf("OrigoDB Server Sync Interface.");
        break;
    case 11104:
        printf("NetApp Intercluster Management.");
        break;
    case 11105:
        printf("NetApp Intercluster Data.");
        break;
    case 11106:
        printf("SGI LK Licensing service.");
        break;
    case 11109:
        printf("Data migration facility Manager (DMF) is a browser based interface to DMF.");
        break;
    case 11110:
        printf("Data migration facility (DMF) SOAP is a web server protocol to support remote access to DMF.");
        break;
    case 11111:
        printf("Viral Computing Environment (VCE).");
        break;
    case 11112:
        printf("DICOM.");
        break;
    case 11161:
        printf("sun cacao snmp access point.");
        break;
    case 11162:
        printf("sun cacao JMX-remoting access point.");
        break;
    case 11163:
        printf("sun cacao rmi registry access point.");
        break;
    case 11164:
        printf("sun cacao command-streaming access point.");
        break;
    case 11165:
        printf("sun cacao web service access point.");
        break;
    case 11172:
        printf("OEM cacao JMX-remoting access point.");
        break;
    case 11173:
        printf("Straton Runtime Programing.");
        break;
    case 11174:
        printf("OEM cacao rmi registry access point.");
        break;
    case 11175:
        printf("OEM cacao web service access point.");
        break;
    case 11201:
        printf("smsqp.");
        break;
    case 11202:
        printf("DCSL Network Backup Services.");
        break;
    case 11208:
        printf("WiFree Service.");
        break;
    case 11211:
        printf("Memory cache service.");
        break;
    case 11319:
        printf("IMIP.");
        break;
    case 11320:
        printf("IMIP Channels Port.");
        break;
    case 11321:
        printf("Arena Server Listen.");
        break;
    case 11367:
        printf("ATM UHAS.");
        break;
    case 11371:
        printf("OpenPGP HTTP Keyserver.");
        break;
    case 11489:
        printf("ASG Cypress Secure Only.");
        break;
    case 11600:
        printf("Tempest Protocol Port.");
        break;
    case 11623:
        printf("EMC XtremSW distributed config.");
        break;
    case 11720:
        printf("H.323 Call Control Signalling Alternate.");
        break;
    case 11723:
        printf("EMC XtremSW distributed cache.");
        break;
    case 11751:
        printf("Intrepid SSL.");
        break;
    case 11796:
        printf("LanSchool.");
        break;
    case 11876:
        printf("X2E Xoraya Multichannel protocol.");
        break;
    case 11967:
        printf("SysInfo Service Protocol.");
        break;
    case 12000:
        printf("IBM Enterprise Extender SNA XID Exchange.");
        break;
    case 12001:
        printf("IBM Enterprise Extender SNA COS Network Priority.");
        break;
    case 12002:
        printf("IBM Enterprise Extender SNA COS High Priority.");
        break;
    case 12003:
        printf("IBM Enterprise Extender SNA COS Medium Priority.");
        break;
    case 12004:
        printf("IBM Enterprise Extender SNA COS Low Priority.");
        break;
    case 12005:
        printf("DBISAM Database Server - Regular.");
        break;
    case 12006:
        printf("DBISAM Database Server - Admin.");
        break;
    case 12007:
        printf("Accuracer Database System Server.");
        break;
    case 12008:
        printf("Accuracer Database System Admin.");
        break;
    case 12010:
        printf("ElevateDB Server.");
        break;
    case 12012:
        printf("Vipera Messaging Service.");
        break;
    case 12013:
        printf("Vipera Messaging Service over SSL Communication.");
        break;
    case 12109:
        printf("RETS over SSL.");
        break;
    case 12121:
        printf("NuPaper Session Service.");
        break;
    case 12168:
        printf("CA Web Access Service.");
        break;
    case 12172:
        printf("HiveP.");
        break;
    case 12300:
        printf("LinoGrid Engine.");
        break;
    case 12302:
        printf("Remote Administration Daemon (RAD) is a system service that offers secure, remote, programmatic access to Solaris system configuration and run-time state.");
        break;
    case 12321:
        printf("Warehouse Monitoring Syst SSS.");
        break;
    case 12322:
        printf("Warehouse Monitoring Syst.");
        break;
    case 12345:
        printf("Italk Chat System.");
        break;
    case 12753:
        printf("tsaf port.");
        break;
    case 12865:
        printf("control port for the netperf benchmark.");
        break;
    case 13160:
        printf("I-ZIPQD.");
        break;
    case 13216:
        printf("Black Crow Software application logging.");
        break;
    case 13217:
        printf("R&S Proxy Installation Assistant Service.");
        break;
    case 13218:
        printf("EMC Virtual CAS Service.");
        break;
    case 13223:
        printf("PowWow Client.");
        break;
    case 13224:
        printf("PowWow Server.");
        break;
    case 13400:
        printf("DoIP Data.");
        break;
    case 13720:
        printf("BPRD Protocol (VERITAS NetBackup).");
        break;
    case 13721:
        printf("BPDBM Protocol (VERITAS NetBackup).");
        break;
    case 13722:
        printf("BP Java MSVC Protocol.");
        break;
    case 13724:
        printf("Veritas Network Utility.");
        break;
    case 13782:
        printf("VERITAS NetBackup.");
        break;
    case 13783:
        printf("VOPIED Protocol.");
        break;
    case 13785:
        printf("NetBackup Database.");
        break;
    case 13786:
        printf("Veritas-nomdb.");
        break;
    case 13818:
        printf("DSMCC Config.");
        break;
    case 13819:
        printf("DSMCC Session Messages.");
        break;
    case 13820:
        printf("DSMCC Pass-Thru Messages.");
        break;
    case 13821:
        printf("DSMCC Download Protocol.");
        break;
    case 13822:
        printf("DSMCC Channel Change Protocol.");
        break;
    case 13823:
        printf("Blackmagic Design Streaming Server.");
        break;
    case 13894:
        printf("Ultimate Control communication protocol.");
        break;
    case 13929:
        printf("D-TA SYSTEMS.");
        break;
    case 13930:
        printf("MedEvolve Port Requester.");
        break;
    case 14000:
        printf("SCOTTY High-Speed Filetransfer.");
        break;
    case 14001:
        printf("SUA.");
        break;
    case 14033:
        printf("sage Best! Config Server 1.");
        break;
    case 14034:
        printf("sage Best! Config Server 2.");
        break;
    case 14141:
        printf("VCS Application.");
        break;
    case 14142:
        printf("IceWall Cert Protocol.");
        break;
    case 14143:
        printf("IceWall Cert Protocol over TLS.");
        break;
    case 14145:
        printf("GCM Application.");
        break;
    case 14149:
        printf("Veritas Traffic Director.");
        break;
    case 14150:
        printf("Veritas Cluster Server Command Server.");
        break;
    case 14154:
        printf("Veritas Application Director.");
        break;
    case 14250:
        printf("Fencing Server.");
        break;
    case 14414:
        printf("CA eTrust Web Update Service.");
        break;
    case 14500:
        printf("xpra network protocol.");
        break;
    case 14936:
        printf("hde-lcesrvr-1.");
        break;
    case 14937:
        printf("hde-lcesrvr-2.");
        break;
    case 15000:
        printf("Hypack Data Aquisition.");
        break;
    case 15002:
        printf("Open Network Environment TLS.");
        break;
    case 15345:
        printf("XPilot Contact Port.");
        break;
    case 15363:
        printf("3Link Negotiation.");
        break;
    case 15555:
        printf("Cisco Stateful NAT.");
        break;
    case 15660:
        printf("Backup Express Restore Server.");
        break;
    case 15740:
        printf("Picture Transfer Protocol.");
        break;
    case 15999:
        printf("ProGrammar Enterprise.");
        break;
    case 16000:
        printf("Administration Server Access.");
        break;
    case 16001:
        printf("Administration Server Connector.");
        break;
    case 16002:
        printf("GoodSync Mediation Service.");
        break;
    case 16020:
        printf("Filemaker Java Web Publishing Core.");
        break;
    case 16021:
        printf("Filemaker Java Web Publishing Core Binary.");
        break;
    case 16161:
        printf("Solaris SEA Port.");
        break;
    case 16162:
        printf("Solaris Audit - secure remote audit log.");
        break;
    case 16309:
        printf("etb4j.");
        break;
    case 16310:
        printf("Policy Distribute, Update Notification.");
        break;
    case 16311:
        printf("Policy definition and update management.");
        break;
    case 16360:
        printf("Network Serial Extension Ports One.");
        break;
    case 16361:
        printf("Network Serial Extension Ports Two.");
        break;
    case 16367:
        printf("Network Serial Extension Ports Three.");
        break;
    case 16368:
        printf("Network Serial Extension Ports Four.");
        break;
    case 16384:
        printf("Connected Corp.");
        break;
    case 16385:
        printf("Reliable Datagram Sockets.");
        break;
    case 16619:
        printf("X509 Objects Management Service.");
        break;
    case 16665:
        printf("Reliable multipath data transport for high latencies.");
        break;
    case 16789:
        printf("This server provides callable services to mainframe External Security Managers from any TCP/IP platform.");
        break;
    case 16900:
        printf("Newbay Mobile Client Update Service.");
        break;
    case 16950:
        printf("Simple Generic Client Interface Protocol.");
        break;
    case 16991:
        printf("INTEL-RCI-MP.");
        break;
    case 16992:
        printf("Intel(R) AMT SOAP/HTTP.");
        break;
    case 16993:
        printf("Intel(R) AMT SOAP/HTTPS.");
        break;
    case 16994:
        printf("Intel(R) AMT Redirection/TCP.");
        break;
    case 16995:
        printf("Intel(R) AMT Redirection/TLS.");
        break;
    case 17184:
        printf("Vestas Data Layer Protocol.");
        break;
    case 17185:
        printf("Sounds Virtual.");
        break;
    case 17219:
        printf("Chipper.");
        break;
    case 17220:
        printf("IEEE 1722 Transport Protocol for Time Sensitive Applications.");
        break;
    case 17221:
        printf("IEEE 1722.1 AVB Discovery, Enumeration, Connection management, and Control.");
        break;
    case 17223:
        printf("ISA100 GCI is a service utilizing a common interface between an ISA100 Wireless gateway and a client application.");
        break;
    case 17225:
        printf("Train Realtime Data Protocol (TRDP) Message Data.");
        break;
    case 17234:
        printf("Integrius Secure Tunnel Protocol.");
        break;
    case 17235:
        printf("SSH Tectia Manager.");
        break;
    case 17500:
        printf("Dropbox LanSync Protocol.");
        break;
    case 17555:
        printf("Ailith management of routers.");
        break;
    case 17729:
        printf("Eclipse Aviation.");
        break;
    case 17754:
        printf("Encap. ZigBee Packets.");
        break;
    case 17755:
        printf("ZigBee IP Transport Service.");
        break;
    case 17756:
        printf("ZigBee IP Transport Secure Service.");
        break;
    case 17777:
        printf("SolarWinds Orion.");
        break;
    case 18000:
        printf("Beckman Instruments, Inc..");
        break;
    case 18104:
        printf("RAD PDF Service.");
        break;
    case 18136:
        printf("z/OS Resource Access Control Facility.");
        break;
    case 18181:
        printf("OPSEC CVP.");
        break;
    case 18182:
        printf("OPSEC UFP.");
        break;
    case 18183:
        printf("OPSEC SAM.");
        break;
    case 18184:
        printf("OPSEC LEA.");
        break;
    case 18185:
        printf("OPSEC OMI.");
        break;
    case 18186:
        printf("Occupational Health SC.");
        break;
    case 18187:
        printf("OPSEC ELA.");
        break;
    case 18241:
        printf("Check Point RTM.");
        break;
    case 18242:
        printf("Checkpoint router monitoring.");
        break;
    case 18243:
        printf("Checkpoint router state backup.");
        break;
    case 18262:
        printf("GV NetConfig Service.");
        break;
    case 18463:
        printf("AC Cluster.");
        break;
    case 18634:
        printf("Reliable Datagram Service.");
        break;
    case 18635:
        printf("Reliable Datagram Service over IP.");
        break;
    case 18668:
        printf("Manufacturing Execution Systems Mesh Communication.");
        break;
    case 18769:
        printf("IQue Protocol.");
        break;
    case 18881:
        printf("Infotos.");
        break;
    case 18888:
        printf("APCNECMP.");
        break;
    case 19000:
        printf("iGrid Server.");
        break;
    case 19007:
        printf("Scintilla protocol for device services.");
        break;
    case 19020:
        printf("J-Link TCP/IP Protocol.");
        break;
    case 19191:
        printf("OPSEC UAA.");
        break;
    case 19194:
        printf("UserAuthority SecureAgent.");
        break;
    case 19220:
        printf("Client Connection Management and Data Exchange Service.");
        break;
    case 19283:
        printf("Key Server for SASSAFRAS.");
        break;
    case 19315:
        printf("Key Shadow for SASSAFRAS.");
        break;
    case 19398:
        printf("mtrgtrans.");
        break;
    case 19410:
        printf("hp-sco.");
        break;
    case 19411:
        printf("hp-sca.");
        break;
    case 19412:
        printf("HP-SESSMON.");
        break;
    case 19539:
        printf("FXUPTP.");
        break;
    case 19540:
        printf("SXUPTP.");
        break;
    case 19541:
        printf("JCP Client.");
        break;
    case 19998:
        printf("IEC 60870-5-104 process control - secure.");
        break;
    case 19999:
        printf("Distributed Network Protocol - Secure.");
        break;
    case 20000:
        printf("DNP.");
        break;
    case 20001:
        printf("MicroSAN.");
        break;
    case 20002:
        printf("Commtact HTTP.");
        break;
    case 20003:
        printf("Commtact HTTPS.");
        break;
    case 20005:
        printf("OpenWebNet protocol for electric network.");
        break;
    case 20013:
        printf("Samsung Interdevice Interaction.");
        break;
    case 20014:
        printf("OpenDeploy Listener.");
        break;
    case 20034:
        printf("NetBurner ID Port.");
        break;
    case 20046:
        printf("TMOP HL7 Message Transfer Service.");
        break;
    case 20048:
        printf("NFS mount protocol.");
        break;
    case 20049:
        printf("Network File System (NFS) over RDMA.");
        break;
    case 20057:
        printf("AvesTerra Hypergraph Transfer Protocol (HGTP).");
        break;
    case 20167:
        printf("TOLfab Data Change.");
        break;
    case 20202:
        printf("IPD Tunneling Port.");
        break;
    case 20222:
        printf("iPulse-ICS.");
        break;
    case 20480:
        printf("emWave Message Service.");
        break;
    case 20670:
        printf("Track.");
        break;
    case 20999:
        printf("At Hand MMP.");
        break;
    case 21000:
        printf("IRTrans Control.");
        break;
    case 21010:
        printf("Notezilla.Lan Server.");
        break;
    case 21212:
        printf("Distributed artificial intelligence.");
        break;
    case 21221:
        printf("Services for Air Server.");
        break;
    case 21553:
        printf("Raima RDM TFS.");
        break;
    case 21554:
        printf("MineScape Design File Server.");
        break;
    case 21590:
        printf("VoFR Gateway.");
        break;
    case 21800:
        printf("TVNC Pro Multiplexing.");
        break;
    case 21845:
        printf("webphone.");
        break;
    case 21846:
        printf("NetSpeak Corp. Directory Services.");
        break;
    case 21847:
        printf("NetSpeak Corp. Connection Services.");
        break;
    case 21848:
        printf("NetSpeak Corp. Automatic Call Distribution.");
        break;
    case 21849:
        printf("NetSpeak Corp. Credit Processing System.");
        break;
    case 22000:
        printf("SNAPenetIO.");
        break;
    case 22001:
        printf("OptoControl.");
        break;
    case 22002:
        printf("Opto Host Port 2.");
        break;
    case 22003:
        printf("Opto Host Port 3.");
        break;
    case 22004:
        printf("Opto Host Port 4.");
        break;
    case 22005:
        printf("Opto Host Port 5.");
        break;
    case 22125:
        printf("dCache Access Protocol.");
        break;
    case 22128:
        printf("GSI dCache Access Protocol.");
        break;
    case 22222:
        printf("EasyEngine is CLI tool to manage WordPress Sites on Nginx server.");
        break;
    case 22273:
        printf("wnn6.");
        break;
    case 22305:
        printf("CompactIS Tunnel.");
        break;
    case 22335:
        printf("Initium Labs Security and Automation Control.");
        break;
    case 22343:
        printf("CompactIS Secure Tunnel.");
        break;
    case 22347:
        printf("WibuKey Standard WkLan.");
        break;
    case 22350:
        printf("CodeMeter Standard.");
        break;
    case 22351:
        printf("TPC/IP requests of copy protection software to a server.");
        break;
    case 22537:
        printf("CaldSoft Backup server file transfer.");
        break;
    case 22555:
        printf("Vocaltec Web Conference.");
        break;
    case 22763:
        printf("Talika Main Server.");
        break;
    case 22800:
        printf("Telerate Information Platform LAN.");
        break;
    case 22951:
        printf("Telerate Information Platform WAN.");
        break;
    case 23000:
        printf("Inova LightLink Server Type 1.");
        break;
    case 23001:
        printf("Inova LightLink Server Type 2.");
        break;
    case 23002:
        printf("Inova LightLink Server Type 3.");
        break;
    case 23003:
        printf("Inova LightLink Server Type 4.");
        break;
    case 23004:
        printf("Inova LightLink Server Type 5.");
        break;
    case 23005:
        printf("Inova LightLink Server Type 6.");
        break;
    case 23053:
        printf("Generic Notification Transport Protocol.");
        break;
    case 23294:
        printf("5AFE SDN Directory.");
        break;
    case 23333:
        printf("Emulex HBAnyware Remote Management.");
        break;
    case 23400:
        printf("Novar Data.");
        break;
    case 23401:
        printf("Novar Alarm.");
        break;
    case 23402:
        printf("Novar Global.");
        break;
    case 23456:
        printf("Aequus Service.");
        break;
    case 23457:
        printf("Aequus Service Mgmt.");
        break;
    case 23546:
        printf("AreaGuard Neo - WebServer.");
        break;
    case 24000:
        printf("med-ltp.");
        break;
    case 24001:
        printf("med-fsp-rx.");
        break;
    case 24002:
        printf("med-fsp-tx.");
        break;
    case 24003:
        printf("med-supp.");
        break;
    case 24004:
        printf("med-ovw.");
        break;
    case 24005:
        printf("med-ci.");
        break;
    case 24006:
        printf("med-net-svc.");
        break;
    case 24242:
        printf("fileSphere.");
        break;
    case 24249:
        printf("Vista 4GL.");
        break;
    case 24321:
        printf("Isolv Local Directory.");
        break;
    case 24386:
        printf("Intel RCI.");
        break;
    case 24465:
        printf("Tonido Domain Server.");
        break;
    case 24554:
        printf("BINKP.");
        break;
    case 24577:
        printf("bilobit Service.");
        break;
    case 24666:
        printf("Service used by SmarDTV to communicate between a CAM and a second screen application.");
        break;
    case 24676:
        printf("Canditv Message Service.");
        break;
    case 24677:
        printf("FlashFiler.");
        break;
    case 24678:
        printf("Turbopower Proactivate.");
        break;
    case 24680:
        printf("TCC User HTTP Service.");
        break;
    case 24754:
        printf("Citrix StorageLink Gateway.");
        break;
    case 24922:
        printf("Find Identification of Network Devices.");
        break;
    case 25000:
        printf("icl-twobase1.");
        break;
    case 25001:
        printf("icl-twobase2.");
        break;
    case 25002:
        printf("icl-twobase3.");
        break;
    case 25003:
        printf("icl-twobase4.");
        break;
    case 25004:
        printf("icl-twobase5.");
        break;
    case 25005:
        printf("icl-twobase6.");
        break;
    case 25006:
        printf("icl-twobase7.");
        break;
    case 25007:
        printf("icl-twobase8.");
        break;
    case 25008:
        printf("icl-twobase9.");
        break;
    case 25009:
        printf("icl-twobase10.");
        break;
    case 25576:
        printf("Sauter Dongle.");
        break;
    case 25604:
        printf("Identifier Tracing Protocol.");
        break;
    case 25793:
        printf("Vocaltec Address Server.");
        break;
    case 25900:
        printf("TASP Network Comm.");
        break;
    case 25901:
        printf("NIObserver.");
        break;
    case 25902:
        printf("NILinkAnalyst.");
        break;
    case 25903:
        printf("NIProbe.");
        break;
    case 26000:
        printf("quake.");
        break;
    case 26133:
        printf("Symbolic Computation Software Composability Protocol.");
        break;
    case 26208:
        printf("wnn6-ds.");
        break;
    case 26257:
        printf("CockroachDB.");
        break;
    case 26260:
        printf("eZproxy.");
        break;
    case 26261:
        printf("eZmeeting.");
        break;
    case 26262:
        printf("K3 Software-Server.");
        break;
    case 26263:
        printf("K3 Software-Client.");
        break;
    case 26486:
        printf("EXOline-TCP.");
        break;
    case 26487:
        printf("EXOconfig.");
        break;
    case 26489:
        printf("EXOnet.");
        break;
    case 27345:
        printf("ImagePump.");
        break;
    case 27442:
        printf("Job controller service.");
        break;
    case 27504:
        printf("Kopek HTTP Head Port.");
        break;
    case 27782:
        printf("ARS VISTA Application.");
        break;
    case 27876:
        printf("Astrolink Protocol.");
        break;
    case 27999:
        printf("TW Authentication/Key Distribution and.");
        break;
    case 28000:
        printf("NX License Manager.");
        break;
    case 28001:
        printf("PQ Service.");
        break;
    case 28200:
        printf("VoxelStorm game server.");
        break;
    case 28240:
        printf("Siemens GSM.");
        break;
    case 28589:
        printf("Building operating system services wide area verified exchange.");
        break;
    case 29167:
        printf("ObTools Message Protocol.");
        break;
    case 29999:
        printf("data exchange protocol for IEC61850 in wind power plants.");
        break;
    case 30000:
        printf("Secure Network Data Management Protocol.");
        break;
    case 30001:
        printf("Pago Services 1.");
        break;
    case 30002:
        printf("Pago Services 2.");
        break;
    case 30003:
        printf("Amicon FPSU-IP Remote Administration.");
        break;
    case 30100:
        printf("Remote Window Protocol.");
        break;
    case 30260:
        printf("Kingdoms Online (CraigAvenue).");
        break;
    case 30400:
        printf("GroundStar RealTime System.");
        break;
    case 30999:
        printf("OpenView Service Desk Client.");
        break;
    case 31016:
        printf("Kollective Agent Secure Distributed Delivery Protocol.");
        break;
    case 31020:
        printf("Autotrac ACP 245.");
        break;
    case 31400:
        printf("PACE license server.");
        break;
    case 31416:
        printf("XQoS network monitor.");
        break;
    case 31457:
        printf("TetriNET Protocol.");
        break;
    case 31620:
        printf("lm mon.");
        break;
    case 31685:
        printf("DS Expert Monitor.");
        break;
    case 31765:
        printf("GameSmith Port.");
        break;
    case 31948:
        printf("Embedded Device Configuration Protocol TX.");
        break;
    case 31949:
        printf("Embedded Device Configuration Protocol RX.");
        break;
    case 32034:
        printf("iRacing helper service.");
        break;
    case 32249:
        printf("T1 Distributed Processor.");
        break;
    case 32400:
        printf("Plex multimedia.");
        break;
    case 32483:
        printf("Access Point Manager Link.");
        break;
    case 32635:
        printf("SecureNotebook-CLNT.");
        break;
    case 32636:
        printf("DMExpress.");
        break;
    case 32767:
        printf("FileNet BPM WS-ReliableMessaging Client.");
        break;
    case 32768:
        printf("Filenet TMS.");
        break;
    case 32769:
        printf("Filenet RPC.");
        break;
    case 32770:
        printf("Filenet NCH.");
        break;
    case 32771:
        printf("FileNET RMI.");
        break;
    case 32772:
        printf("FileNET Process Analyzer.");
        break;
    case 32773:
        printf("FileNET Component Manager.");
        break;
    case 32774:
        printf("FileNET Rules Engine.");
        break;
    case 32775:
        printf("Performance Clearinghouse.");
        break;
    case 32776:
        printf("FileNET BPM IOR.");
        break;
    case 32777:
        printf("FileNet BPM CORBA.");
        break;
    case 32801:
        printf("Multiple Listing Service Network.");
        break;
    case 32811:
        printf("Real Estate Transport Protocol.");
        break;
    case 32896:
        printf("Attachmate ID Manager.");
        break;
    case 33060:
        printf("MySQL Database Extended Interface.");
        break;
    case 33123:
        printf("Aurora (Balaena Ltd).");
        break;
    case 33331:
        printf("DiamondCentral Interface.");
        break;
    case 33333:
        printf("Digital Gaslight Service.");
        break;
    case 33334:
        printf("SpeedTrace TraceAgent.");
        break;
    case 33434:
        printf("traceroute use.");
        break;
    case 33656:
        printf("SNIP Slave.");
        break;
    case 34249:
        printf("TurboNote Relay Server Default Port.");
        break;
    case 34378:
        printf("P-Net on IP local.");
        break;
    case 34379:
        printf("P-Net on IP remote.");
        break;
    case 34567:
        printf("dhanalakshmi.org EDI Service.");
        break;
    case 34962:
        printf("PROFInet RT Unicast.");
        break;
    case 34963:
        printf("PROFInet RT Multicast.");
        break;
    case 34964:
        printf("PROFInet Context Manager.");
        break;
    case 34980:
        printf("EtherCAT Port.");
        break;
    case 35000:
        printf("HeathView.");
        break;
    case 35001:
        printf("ReadyTech Viewer.");
        break;
    case 35002:
        printf("ReadyTech Sound Server.");
        break;
    case 35003:
        printf("ReadyTech DeviceMapper Server.");
        break;
    case 35004:
        printf("ReadyTech ClassManager.");
        break;
    case 35005:
        printf("ReadyTech LabTracker.");
        break;
    case 35006:
        printf("ReadyTech Helper Service.");
        break;
    case 35100:
        printf("Axiomatic discovery protocol.");
        break;
    case 35354:
        printf("KIT Messenger.");
        break;
    case 35355:
        printf("Altova License Management.");
        break;
    case 35356:
        printf("Gutters Note Exchange.");
        break;
    case 35357:
        printf("OpenStack ID Service.");
        break;
    case 36001:
        printf("AllPeers Network.");
        break;
    case 36524:
        printf("Febooti Automation Workshop.");
        break;
    case 36602:
        printf("Observium statistics collection agent.");
        break;
    case 36700:
        printf("MapX communication.");
        break;
    case 36865:
        printf("KastenX Pipe.");
        break;
    case 37475:
        printf("science + computing's Venus Administration Port.");
        break;
    case 37483:
        printf("Google Drive Sync.");
        break;
    case 37601:
        printf("Epipole File Transfer Protocol.");
        break;
    case 37654:
        printf("Unisys ClearPath ePortal.");
        break;
    case 38000:
        printf("InfoVista Server Database.");
        break;
    case 38001:
        printf("InfoVista Server Insertion.");
        break;
    case 38002:
        printf("Cresco Controller.");
        break;
    case 38201:
        printf("Galaxy7 Data Tunnel.");
        break;
    case 38202:
        printf("Fairview Message Service.");
        break;
    case 38203:
        printf("AppGate Policy Server.");
        break;
    case 38800:
        printf("Sruth.");
        break;
    case 38865:
        printf("Security approval process for use of the secRMM SafeCopy program.");
        break;
    case 39681:
        printf("TurboNote Default Port.");
        break;
    case 40000:
        printf("SafetyNET p.");
        break;
    case 40404:
        printf("Simplify Printing TX.");
        break;
    case 40841:
        printf("CSCP.");
        break;
    case 40842:
        printf("CSCCREDIR.");
        break;
    case 40843:
        printf("CSCCFIREWALL.");
        break;
    case 41111:
        printf("Foursticks QoS Protocol.");
        break;
    case 41121:
        printf("Tentacle Server.");
        break;
    case 41230:
        printf("Z-Wave Protocol over SSL/TLS.");
        break;
    case 41794:
        printf("Crestron Control Port.");
        break;
    case 41795:
        printf("Crestron Terminal Port.");
        break;
    case 41796:
        printf("Crestron Secure Control Port.");
        break;
    case 41797:
        printf("Crestron Secure Terminal Port.");
        break;
    case 42508:
        printf("Computer Associates network discovery protocol.");
        break;
    case 42509:
        printf("CA discovery response.");
        break;
    case 42510:
        printf("CA eTrust RPC.");
        break;
    case 43000:
        printf("Receiver Remote Control.");
        break;
    case 43188:
        printf("REACHOUT.");
        break;
    case 43189:
        printf("NDM-AGENT-PORT.");
        break;
    case 43190:
        printf("IP-PROVISION.");
        break;
    case 43191:
        printf("Reconnoiter Agent Data Transport.");
        break;
    case 43210:
        printf("Shaper Automation Server Management.");
        break;
    case 43439:
        printf("EQ3 firmware update.");
        break;
    case 43440:
        printf("Cisco EnergyWise Management.");
        break;
    case 43441:
        printf("Cisco NetMgmt DB Ports.");
        break;
    case 44123:
        printf("Z-Wave Secure Tunnel.");
        break;
    case 44321:
        printf("PCP server (pmcd).");
        break;
    case 44322:
        printf("PCP server (pmcd) proxy.");
        break;
    case 44323:
        printf("HTTP binding for Performance Co-Pilot client API.");
        break;
    case 44444:
        printf("Cognex DataMan Management Protocol.");
        break;
    case 44553:
        printf("REALbasic Remote Debug.");
        break;
    case 44818:
        printf("EtherNet/IP messaging.");
        break;
    case 44900:
        printf("M3DA is used for efficient machine-to-machine communications.");
        break;
    case 45000:
        printf("Nuance AutoStore Status Monitoring Protocol (data transfer).");
        break;
    case 45001:
        printf("Nuance AutoStore Status Monitoring Protocol (secure data transfer).");
        break;
    case 45002:
        printf("Redspeed Status Monitor.");
        break;
    case 45045:
        printf("Remote application control protocol.");
        break;
    case 45054:
        printf("InVision AG.");
        break;
    case 45514:
        printf("ASSIA CloudCheck WiFi Management System.");
        break;
    case 45678:
        printf("EBA PRISE.");
        break;
    case 45824:
        printf("Server for the DAI family of client-server products.");
        break;
    case 45825:
        printf("Qpuncture Data Access Service.");
        break;
    case 45966:
        printf("SSRServerMgr.");
        break;
    case 46336:
        printf("Listen port used for Inedo agent communication.");
        break;
    case 46998:
        printf("Connection between a desktop computer or server and a signature tablet to capture handwritten signatures.");
        break;
    case 46999:
        printf("MediaBox Server.");
        break;
    case 47000:
        printf("Message Bus.");
        break;
    case 47001:
        printf("Windows Remote Management Service.");
        break;
    case 47557:
        printf("Databeam Corporation.");
        break;
    case 47624:
        printf("Direct Play Server.");
        break;
    case 47806:
        printf("ALC Protocol.");
        break;
    case 47808:
        printf("Building Automation and Control Networks.");
        break;
    case 48000:
        printf("Nimbus Controller.");
        break;
    case 48001:
        printf("Nimbus Spooler.");
        break;
    case 48002:
        printf("Nimbus Hub.");
        break;
    case 48003:
        printf("Nimbus Gateway.");
        break;
    case 48004:
        printf("NimbusDB Connector.");
        break;
    case 48005:
        printf("NimbusDB Control.");
        break;
    case 48048:
        printf("Juliar Programming Language Protocol.");
        break;
    case 48049:
        printf("3GPP Cell Broadcast Service Protocol.");
        break;
    case 48050:
        printf("WeFi Access Network Discovery and Selection Function.");
        break;
    case 48128:
        printf("Image Systems Network Services.");
        break;
    case 48129:
        printf("Bloomberg locator.");
        break;
    case 48556:
        printf("com-bardac-dw.");
        break;
    case 48619:
        printf("iqobject.");
        break;
    case 48653:
        printf("Robot Raconteur transport.");
        break;
    case 49000:
        printf("Matahari Broker.");
        break;
    case 49001:
        printf("Nuance Unity Service Request Protocol.");
        break;
    case 49150:
        printf("InSpider System.");
        break;

    default:
        printf("Unknown service");
        break;
    }
}

void task(std::string ip, int port)
{
    // std::future<void> fn = std::async(std::launch::deferred, ShowPortNumberInfo, port);
    if (port_is_open(ip, port))
    {
        // std::cout << port << " : OPEN"<< std::endl;
        std::cout << port << " : OPEN : ";
        ShowPortNumberInfo(port);
        std::cout << std::endl;
    }
}

void scanPorts(std::string ip, int portInit, int portEnd)
{
    std::vector<std::thread *> tasks;

    for (int i = portInit; i < portEnd; i++)
    {
        tasks.push_back(new std::thread(task, ip, i));
    }
    for (int i = 0; i < portEnd - portInit; i++)
    {
        tasks[i]->join();
        delete tasks[i];
    }
}

int main()
{

    std::string address;
    int option;
    int port;
    int portStart;
    int portEnd;

    // check option
    std::cout << "--------------Menu--------------" << std::endl;
    std::cout << "1. Scan specifical TCP port" << std::endl;
    std::cout << "2. Scan range TCP port" << std::endl;
    std::cout << "3. Scan all TCP port" << std::endl;
    std::cin >> option;

    switch (option)
    {
    case 1:
        /* code */
        {
            std::cout << "Address: " << std::flush;
            std::cin >> address;
            std::cout << "Port: " << std::flush;
            std::cin >> port;

            std::cout << "Showing open ports on " << address << "...\n";
            std::cout << "PORT : STATUS : SERVICE" << std::endl;

            if (port_is_open(address, port))
            {
                std::cout << port << " : OPEN : ";
                ShowPortNumberInfo(port);
                std::cout << std::endl;
            }
            else
            {
                std::cout << "Currently do not have ports openned!" << std::endl;
            }
        }
        break;
    case 2:
    {
        std::cout << "Address: " << std::flush;
        std::cin >> address;
        std::cout << "Port start:  " << std::flush;
        std::cin >> portStart;
        std::cout << "Port end: " << std::flush;
        std::cin >> portEnd;
        std::cout << "Showing open ports on " << address << "...\n";
        std::cout << "PORT : STATUS : SERVICE" << std::endl;

        scanPorts(address, portStart, portEnd);
    }
    break;
    case 3:
    {
        std::cout << "Address: " << std::flush;
        std::cin >> address;
        std::cout << "Showing open ports on " << address << "...\n";
        std::cout << "PORT : STATUS : SERVICE" << std::endl;

        scanPorts(address, 0, 65535);
    }
    default:
        break;
    }

    std::cout << std::flush;
    return 0;
}