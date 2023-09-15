#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <getopt.h>

const char *strerror_version_string = "0.1.3";

static const struct option long_options[] = {
	{"help", no_argument, NULL, 'h'},
	{"version", no_argument, NULL, 'V'},
	{"list", no_argument, NULL, 'l'},
	{NULL, 0, NULL, 0}
};
static const char *short_options = "hVl";

char errno_str[64];

void Help (void) {
	printf ("Usage: strerror { ERRNUM | ERRNAME }\nexample: 'strerror 4; strerror ENOSYS; strerror $?;'\n"
		"strerror { -h | --help } shows this usage/help message.\n"
		"strerror { -l | --list } shows all error numbers with their associated system descriptions.\n");
}

char *Errno2Varname (int errnum);
int Varname2Int (char *varname);

int main (int argc, char **argv) {
	int c, cnt, errnum;
	while (1) {
		c = getopt_long (argc, argv, short_options, long_options, NULL);
		if (c == -1) break;
		switch (c) {
		case 'h':
			Help ();
			exit (1);
		case 'V':
			printf("strerror %s\n", strerror_version_string);
			exit(0);
			break;
		case 'l':
			for (cnt = 0; cnt <= 134; cnt++) {
				printf ("%d (%s): %s\n", cnt, Errno2Varname(cnt), strerror(cnt));
			}
			exit (0);
		default:
			printf ("strerror error: Unbranched argument:#%d:%c:\n", c, (char)c);
		}
	}

	for (cnt = 1; cnt < argc; cnt++) {
		if (isdigit(argv[cnt][0]))
			errnum = atoi (argv[cnt]);
		else if (argv[cnt][0] == 'E' || argv[cnt][0] == 'e')
			errnum = Varname2Int (argv[cnt]);
		printf ("%d (%s): %s\n", errnum, Errno2Varname(errnum), strerror(errnum));
	}

	return 0;
}

char *Errno2Varname (int errnum) {
	switch (errnum) {
	case EPERM: // 1
		sprintf (errno_str, "EPERM");
		break;
	case ENOENT: // 2	
		sprintf (errno_str, "ENOENT");
		break;
	case ESRCH: // 3	
		sprintf (errno_str, "ESRCH");
		break;
	case EINTR: // 4	
		sprintf (errno_str, "EINTR");
		break;
	case EIO: // 5	
		sprintf (errno_str, "EIO");
		break;
	case ENXIO: // 6	
		sprintf (errno_str, "ENXIO");
		break;
	case E2BIG: // 7	
		sprintf (errno_str, "E2BIG");
		break;
	case ENOEXEC: // 8	
		sprintf (errno_str, "ENOEXEC");
		break;
	case EBADF: // 9	
		sprintf (errno_str, "EBADF");
		break;
	case ECHILD: // 10	
		sprintf (errno_str, "ECHILD");
		break;
	case EAGAIN: // 11	
		sprintf (errno_str, "EAGAIN");
		break;
	case ENOMEM: // 12	
		sprintf (errno_str, "ENOMEM");
		break;
	case EACCES: // 13	
		sprintf (errno_str, "EACCES");
		break;
	case EFAULT: // 14	
		sprintf (errno_str, "EFAULT");
		break;
	case ENOTBLK: // 15	
		sprintf (errno_str, "ENOTBLK");
		break;
	case EBUSY: // 16	
		sprintf (errno_str, "EBUSY");
		break;
	case EEXIST: // 17	
		sprintf (errno_str, "EEXIST");
		break;
	case EXDEV: // 18	
		sprintf (errno_str, "EXDEV");
		break;
	case ENODEV: // 19	
		sprintf (errno_str, "ENODEV");
		break;
	case ENOTDIR: // 20	
		sprintf (errno_str, "ENOTDIR");
		break;
	case EISDIR: // 21	
		sprintf (errno_str, "EISDIR");
		break;
	case EINVAL: // 22	
		sprintf (errno_str, "EINVAL");
		break;
	case ENFILE: // 23	
		sprintf (errno_str, "ENFILE");
		break;
	case EMFILE: // 24	
		sprintf (errno_str, "EMFILE");
		break;
	case ENOTTY: // 25	
		sprintf (errno_str, "ENOTTY");
		break;
	case ETXTBSY: // 26	
		sprintf (errno_str, "ETXTBSY");
		break;
	case EFBIG: // 27	
		sprintf (errno_str, "EFBIG");
		break;
	case ENOSPC: // 28	
		sprintf (errno_str, "ENOSPC");
		break;
	case ESPIPE: // 29	
		sprintf (errno_str, "ESPIPE");
		break;
	case EROFS: // 30	
		sprintf (errno_str, "EROFS");
		break;
	case EMLINK: // 31	
		sprintf (errno_str, "EMLINK");
		break;
	case EPIPE: // 32	
		sprintf (errno_str, "EPIPE");
		break;
	case EDOM: // 33	
		sprintf (errno_str, "EDOM");
		break;
	case ERANGE: // 34	
		sprintf (errno_str, "ERANGE");
		break;
	case EDEADLK: // 35	
		sprintf (errno_str, "EDEADLK");
		break;
	case ENAMETOOLONG: // 36	
		sprintf (errno_str, "ENAMETOOLONG");
		break;
	case ENOLCK: // 37	
		sprintf (errno_str, "ENOLCK");
		break;
	case ENOSYS: // 38	
		sprintf (errno_str, "ENOSYS");
		break;
	case ENOTEMPTY: // 39	
		sprintf (errno_str, "ENOEMPTY");
		break;
	case ELOOP: // 40	
		sprintf (errno_str, "ELOOP");
		break;
//	case EWOULDBLOCK	EAGAIN	
//		sprintf (errno_str, "");
//		break;
	case ENOMSG: // 42
		sprintf (errno_str, "ENOMSG");
		break;
	case EIDRM: // 43	
		sprintf (errno_str, "EIDRM");
		break;
	case ECHRNG: // 44	
		sprintf (errno_str, "ECHRNG");
		break;
	case EL2NSYNC: // 45	
		sprintf (errno_str, "EL2NSYNC");
		break;
	case EL3HLT: // 46	
		sprintf (errno_str, "EL3HLT");
		break;
	case EL3RST: // 47	
		sprintf (errno_str, "EL3RST");
		break;
	case ELNRNG: // 48	
		sprintf (errno_str, "ELNRNG");
		break;
	case EUNATCH: // 49	
		sprintf (errno_str, "EUNATCH");
		break;
	case ENOCSI: // 50	
		sprintf (errno_str, "ENOCSI");
		break;
	case EL2HLT: // 51	
		sprintf (errno_str, "EL2HLT");
		break;
	case EBADE: // 52	
		sprintf (errno_str, "EBADE");
		break;
	case EBADR: // 53	
		sprintf (errno_str, "EBADR");
		break;
	case EXFULL: // 54	
		sprintf (errno_str, "EXFULL");
		break;
	case ENOANO: // 55	
		sprintf (errno_str, "ENOANO");
		break;
	case EBADRQC: // 56	
		sprintf (errno_str, "EBADRQC");
		break;
	case EBADSLT: // 57	
		sprintf (errno_str, "EBADSLT");
		break;
	case EBFONT: // 59	
		sprintf (errno_str, "EBFONT");
		break;
	case ENOSTR: // 60	
		sprintf (errno_str, "ENOSTR");
		break;
	case ENODATA: // 61	
		sprintf (errno_str, "ENODATA");
		break;
	case ETIME: // 62	
		sprintf (errno_str, "ETIME");
		break;
	case ENOSR: // 63	
		sprintf (errno_str, "ENOSR");
		break;
	case ENONET: // 64	
		sprintf (errno_str, "ENONET");
		break;
	case ENOPKG: // 65	
		sprintf (errno_str, "ENOPKG");
		break;
	case EREMOTE: // 66	
		sprintf (errno_str, "EREMOTE");
		break;
	case ENOLINK: // 67	
		sprintf (errno_str, "ENOLINK");
		break;
	case EADV: // 68	
		sprintf (errno_str, "EADV");
		break;
	case ESRMNT: // 69	
		sprintf (errno_str, "ESRMNT");
		break;
	case ECOMM: //70	
		sprintf (errno_str, "ECOMM");
		break;
	case EPROTO: // 71	
		sprintf (errno_str, "EPROTO");
		break;
	case EMULTIHOP: // 72	
		sprintf (errno_str, "EMULTIHOP");
		break;
	case EDOTDOT: // 73	
		sprintf (errno_str, "EDOTDOT");
		break;
	case EBADMSG: // 74	
		sprintf (errno_str, "EBADMSG");
		break;
	case EOVERFLOW: // 75	
		sprintf (errno_str, "EOVERFLOW");
		break;
	case ENOTUNIQ: // 76	
		sprintf (errno_str, "ENOTUNIQ");
		break;
	case EBADFD: // 77	
		sprintf (errno_str, "EBADFD");
		break;
	case EREMCHG: // 78	
		sprintf (errno_str, "EREMCHG");
		break;
	case ELIBACC: // 79	
		sprintf (errno_str, "ELIBACC");
		break;
	case ELIBBAD: // 80	
		sprintf (errno_str, "ELIBBAD");
		break;
	case ELIBSCN: // 81	
		sprintf (errno_str, "ELIBSCN");
		break;
	case ELIBMAX: // 82	
		sprintf (errno_str, "ELIBMAX");
		break;
	case ELIBEXEC: // 83	
		sprintf (errno_str, "ELIBEXEC");
		break;
	case EILSEQ: // 84	
		sprintf (errno_str, "EILSEQ");
		break;
	case ERESTART: // 85	
		sprintf (errno_str, "ERESTART");
		break;
	case ESTRPIPE: // 86	
		sprintf (errno_str, "ESTRPIPE");
		break;
	case EUSERS: // 87	
		sprintf (errno_str, "EUSERS");
		break;
	case ENOTSOCK: // 88	
		sprintf (errno_str, "ENOTSOCK");
		break;
	case EDESTADDRREQ: // 89	
		sprintf (errno_str, "EDESTADDRREQ");
		break;
	case EMSGSIZE: // 90	
		sprintf (errno_str, "EMSGSIZE");
		break;
	case EPROTOTYPE: // 91	
		sprintf (errno_str, "EPROTOTYPE");
		break;
	case ENOPROTOOPT: // 92	
		sprintf (errno_str, "ENOPROTOOPT");
		break;
	case EPROTONOSUPPORT: // 93	
		sprintf (errno_str, "EPROTONOSUPPORT");
		break;
	case ESOCKTNOSUPPORT: // 94	
		sprintf (errno_str, "ESOCKTNOSUPPORT");
		break;
	case EOPNOTSUPP: // 95	
		sprintf (errno_str, "EOPNOTSUPP");
		break;
	case EPFNOSUPPORT: // 96	
		sprintf (errno_str, "EPFNOSUPPORT");
		break;
	case EAFNOSUPPORT: // 97	
		sprintf (errno_str, "EAFNOSUPPORT");
		break;
	case EADDRINUSE: // 98	
		sprintf (errno_str, "EADDRINUSE");
		break;
	case EADDRNOTAVAIL: // 99	
		sprintf (errno_str, "EADDRNOTAVAIL");
		break;
	case ENETDOWN: // 100	
		sprintf (errno_str, "ENETDOWN");
		break;
	case ENETUNREACH: // 101	
		sprintf (errno_str, "ENETUNREACH");
		break;
	case ENETRESET: // 102	
		sprintf (errno_str, "ENETRESET");
		break;
	case ECONNABORTED: // 103	
		sprintf (errno_str, "ECONNABORTED");
		break;
	case ECONNRESET: // 104	
		sprintf (errno_str, "ECONNRESET");
		break;
	case ENOBUFS: // 105	
		sprintf (errno_str, "ENOBUFS");
		break;
	case EISCONN: // 106	
		sprintf (errno_str, "EISCONN");
		break;
	case ENOTCONN: // 107	
		sprintf (errno_str, "ENOTCONN");
		break;
	case ESHUTDOWN: // 108	
		sprintf (errno_str, "ESHUTDOWN");
		break;
	case ETOOMANYREFS: // 109	
		sprintf (errno_str, "ETOOMANYREFS");
		break;
	case ETIMEDOUT: // 110	
		sprintf (errno_str, "ETIMEDOUT");
		break;
	case ECONNREFUSED: // 111	
		sprintf (errno_str, "ECONNREFUSED");
		break;
	case EHOSTDOWN: // 112	
		sprintf (errno_str, "EHOSTDOWN");
		break;
	case EHOSTUNREACH: // 113	
		sprintf (errno_str, "EHOSTUNREACH");
		break;
	case EALREADY: // 114	
		sprintf (errno_str, "EALREADY");
		break;
	case EINPROGRESS: // 115	
		sprintf (errno_str, "EINPROGRESS");
		break;
	case ESTALE: // 116	
		sprintf (errno_str, "ESTALE");
		break;
	case EUCLEAN: // 117	
		sprintf (errno_str, "EUCLEAN");
		break;
	case ENOTNAM: // 118	
		sprintf (errno_str, "ENOTNAM");
		break;
	case ENAVAIL: // 119	
		sprintf (errno_str, "ENAVAIL");
		break;
	case EISNAM: // 120	
		sprintf (errno_str, "EISNAM");
		break;
	case EREMOTEIO: // 121	
		sprintf (errno_str, "EREMOTEIO");
		break;
	case EDQUOT: // 122	
		sprintf (errno_str, "EDQUOT");
		break;
	case ENOMEDIUM: // 123	
		sprintf (errno_str, "ENOMEDIUM");
		break;
	case EMEDIUMTYPE: // 124	
		sprintf (errno_str, "EMEDIUMTYPE");
		break;
	case ECANCELED: // 125	
		sprintf (errno_str, "ECANCELED");
		break;
	case ENOKEY: // 126	
		sprintf (errno_str, "ENOKEY");
		break;
	case EKEYEXPIRED: // 127	
		sprintf (errno_str, "EKEYEXPIRED");
		break;
	case EKEYREVOKED: // 128	
		sprintf (errno_str, "EKEYREVOKED");
		break;
	case EKEYREJECTED: // 129	
		sprintf (errno_str, "EKEYREJECTED");
		break;
	case EOWNERDEAD: // 130	
		sprintf (errno_str, "EOWNERDEAD");
		break;
	case ENOTRECOVERABLE: //131	
		sprintf (errno_str, "ENOTRECOVERABLE");
		break;
	case ERFKILL: // 132	
		sprintf (errno_str, "ERFKILL");
		break;
	case EHWPOISON: // 133	
		sprintf (errno_str, "EHWPOISON");
		break;
	default:
		sprintf (errno_str, "errno_to_varname():wrong_errno: %d", errnum);
		break;
	}
	return errno_str;
}

int Varname2Int (char *varname) {
	if (strcmp(varname,"EPERM")==0) return 1;
	else if (strcmp(varname,"ENOENT")==0) return 2;
	else if (strcmp(varname,"ESRCH")==0) return 3;
	else if (strcmp(varname,"EINTR")==0) return 4;
	else if (strcmp(varname,"EIO")==0) return 5;
	else if (strcmp(varname,"ENXIO")==0) return 6;
	else if (strcmp(varname,"E2BIG")==0) return 7;
	else if (strcmp(varname,"ENOEXEC")==0) return 8;
	else if (strcmp(varname,"EBADF")==0) return 9;
	else if (strcmp(varname,"ECHILD")==0) return 10;
	else if (strcmp(varname,"EAGAIN")==0) return 11;
	else if (strcmp(varname,"ENOMEM")==0) return 12;
	else if (strcmp(varname,"EACCES")==0) return 13;
	else if (strcmp(varname,"EFAULT")==0) return 14;
	else if (strcmp(varname,"ENOTBLK")==0) return 15;
	else if (strcmp(varname,"EBUSY")==0) return 16;
	else if (strcmp(varname,"EEXIST")==0) return 17;
	else if (strcmp(varname,"EXDEV")==0) return 18;
	else if (strcmp(varname,"ENODEV")==0) return 19;
	else if (strcmp(varname,"ENOTDIR")==0) return 20;
	else if (strcmp(varname,"EISDIR")==0) return 21;
	else if (strcmp(varname,"EINVAL")==0) return 22;
	else if (strcmp(varname,"ENFILE")==0) return 23;
	else if (strcmp(varname,"EMFILE")==0) return 24;
	else if (strcmp(varname,"ENOTTY")==0) return 25;
	else if (strcmp(varname,"ETXTBSY")==0) return 26;
	else if (strcmp(varname,"EFBIG")==0) return 27;
	else if (strcmp(varname,"ENOSPC")==0) return 28;
	else if (strcmp(varname,"ESPIPE")==0) return 29;
	else if (strcmp(varname,"EROFS")==0) return 30;
	else if (strcmp(varname,"EMLINK")==0) return 31;
	else if (strcmp(varname,"EPIPE")==0) return 32;
	else if (strcmp(varname,"EDOM")==0) return 33;
	else if (strcmp(varname,"ERANGE")==0) return 34;
	else if (strcmp(varname,"EDEADLK")==0) return 35;
	else if (strcmp(varname,"ENAMETOOLONG")==0) return 36;
	else if (strcmp(varname,"ENOLCK")==0) return 37;
	else if (strcmp(varname,"ENOSYS")==0) return 38;
	else if (strcmp(varname,"ENOEMPTY")==0) return 39;
	else if (strcmp(varname,"ELOOP")==0) return 40;
	else if (strcmp(varname,"ENOMSG")==0) return 42;
	else if (strcmp(varname,"EIDRM")==0) return 43;
	else if (strcmp(varname,"ECHRNG")==0) return 44;
	else if (strcmp(varname,"EL2NSYNC")==0) return 45;
	else if (strcmp(varname,"EL3HLT")==0) return 46;
	else if (strcmp(varname,"EL3RST")==0) return 47;
	else if (strcmp(varname,"ELNRNG")==0) return 48;
	else if (strcmp(varname,"EUNATCH")==0) return 49;
	else if (strcmp(varname,"ENOCSI")==0) return 50;
	else if (strcmp(varname,"EL2HLT")==0) return 51;
	else if (strcmp(varname,"EBADE")==0) return 52;
	else if (strcmp(varname,"EBADR")==0) return 53;
	else if (strcmp(varname,"EXFULL")==0) return 54;
	else if (strcmp(varname,"ENOANO")==0) return 55;
	else if (strcmp(varname,"EBADRQC")==0) return 56;
	else if (strcmp(varname,"EBADSLT")==0) return 57;
	else if (strcmp(varname,"EBFONT")==0) return 59;
	else if (strcmp(varname,"ENOSTR")==0) return 60;
	else if (strcmp(varname,"ENODATA")==0) return 61;
	else if (strcmp(varname,"ETIME")==0) return 62;
	else if (strcmp(varname,"ENOSR")==0) return 63;
	else if (strcmp(varname,"ENONET")==0) return 64;
	else if (strcmp(varname,"ENOPKG")==0) return 65;
	else if (strcmp(varname,"EREMOTE")==0) return 66;
	else if (strcmp(varname,"ENOLINK")==0) return 67;
	else if (strcmp(varname,"EADV")==0) return 68;
	else if (strcmp(varname,"ESRMNT")==0) return 69;
	else if (strcmp(varname,"ECOMM")==0) return 70;
	else if (strcmp(varname,"EPROTO")==0) return 71;
	else if (strcmp(varname,"EMULTIHOP")==0) return 72;
	else if (strcmp(varname,"EDOTDOT")==0) return 73;
	else if (strcmp(varname,"EBADMSG")==0) return 74;
	else if (strcmp(varname,"EOVERFLOW")==0) return 75;
	else if (strcmp(varname,"ENOTUNIQ")==0) return 76;
	else if (strcmp(varname,"EBADFD")==0) return 77;
	else if (strcmp(varname,"EREMCHG")==0) return 78;
	else if (strcmp(varname,"ELIBACC")==0) return 79;
	else if (strcmp(varname,"ELIBBAD")==0) return 80;
	else if (strcmp(varname,"ELIBSCN")==0) return 81;
	else if (strcmp(varname,"ELIBMAX")==0) return 82;
	else if (strcmp(varname,"ELIBEXEC")==0) return 83;
	else if (strcmp(varname,"EILSEQ")==0) return 84;
	else if (strcmp(varname,"ERESTART")==0) return 85;
	else if (strcmp(varname,"ESTRPIPE")==0) return 86;
	else if (strcmp(varname,"EUSERS")==0) return 87;
	else if (strcmp(varname,"ENOTSOCK")==0) return 88;
	else if (strcmp(varname,"EDESTADDRREQ")==0) return 89;
	else if (strcmp(varname,"EMSGSIZE")==0) return 90;
	else if (strcmp(varname,"EPROTOTYPE")==0) return 91;
	else if (strcmp(varname,"ENOPROTOOPT")==0) return 92;
	else if (strcmp(varname,"EPROTONOSUPPORT")==0) return 93;
	else if (strcmp(varname,"ESOCKTNOSUPPORT")==0) return 94;
	else if (strcmp(varname,"EOPNOTSUPP")==0) return 95;
	else if (strcmp(varname,"EPFNOSUPPORT")==0) return 96;
	else if (strcmp(varname,"EAFNOSUPPORT")==0) return 97;
	else if (strcmp(varname,"EADDRINUSE")==0) return 98;
	else if (strcmp(varname,"EADDRNOTAVAIL")==0) return 99;
	else if (strcmp(varname,"ENETDOWN")==0) return 100;
	else if (strcmp(varname,"ENETUNREACH")==0) return 101;
	else if (strcmp(varname,"ENETRESET")==0) return 102;
	else if (strcmp(varname,"ECONNABORTED")==0) return 103;
	else if (strcmp(varname,"ECONNRESET")==0) return 104;
	else if (strcmp(varname,"ENOBUFS")==0) return 105;
	else if (strcmp(varname,"EISCONN")==0) return 106;
	else if (strcmp(varname,"ENOTCONN")==0) return 107;
	else if (strcmp(varname,"ESHUTDOWN")==0) return 108;
	else if (strcmp(varname,"ETOOMANYREFS")==0) return 109;
	else if (strcmp(varname,"ETIMEDOUT")==0) return 110;
	else if (strcmp(varname,"ECONNREFUSED")==0) return 111;
	else if (strcmp(varname,"EHOSTDOWN")==0) return 112;
	else if (strcmp(varname,"EHOSTUNREACH")==0) return 113;
	else if (strcmp(varname,"EALREADY")==0) return 114;
	else if (strcmp(varname,"EINPROGRESS")==0) return 115;
	else if (strcmp(varname,"ESTALE")==0) return 116;
	else if (strcmp(varname,"EUCLEAN")==0) return 117;
	else if (strcmp(varname,"ENOTNAM")==0) return 118;
	else if (strcmp(varname,"ENAVAIL")==0) return 119;
	else if (strcmp(varname,"EISNAM")==0) return 120;
	else if (strcmp(varname,"EREMOTEIO")==0) return 121;
	else if (strcmp(varname,"EDQUOT")==0) return 122;
	else if (strcmp(varname,"ENOMEDIUM")==0) return 123;
	else if (strcmp(varname,"EMEDIUMTYPE")==0) return 124;
	else if (strcmp(varname,"ECANCELED")==0) return 125;
	else if (strcmp(varname,"ENOKEY")==0) return 126;
	else if (strcmp(varname,"EKEYEXPIRED")==0) return 127;
	else if (strcmp(varname,"EKEYREVOKED")==0) return 128;
	else if (strcmp(varname,"EKEYREJECTED")==0) return 129;
	else if (strcmp(varname,"EOWNERDEAD")==0) return 130;
	else if (strcmp(varname,"ENOTRECOVERABLE")==0) return 131;
	else if (strcmp(varname,"ERFKILL")==0) return 132;
	else if (strcmp(varname,"EHWPOISON")==0) return 133;
	else {
		fprintf (stderr, "strerror error: Varname2Int(): wrong varname: %s", varname);
		return -256;
	}
}

