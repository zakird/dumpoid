#include <openssl/objects.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "microsoft.h"

void dump_oid(int n, ASN1_OBJECT *obj)
{
    const int buflen = 4096;
    char name[buflen];
    char oid[buflen];
    assert(OBJ_obj2txt(name, buflen, obj, 0) < buflen);
    assert(OBJ_obj2txt(oid, buflen, obj, 1) < buflen);
    if (strlen(oid)) {
        printf("%s,%s,%s\n", oid, OBJ_nid2sn(n), OBJ_nid2ln(n));
    }
}

int main(int argc, char **argv)
{

    int max_nid;
    for (int i=0; i < sizeof(custom_oids)/sizeof(c_oid_t); i++) {
        max_nid = OBJ_create(custom_oids[i].oid,
                custom_oids[i].sn,
                custom_oids[i].ln);
    }

    // dump oids
    for(int i=0; i<max_nid; i++) {
        ASN1_OBJECT *obj = OBJ_nid2obj(i);
        if (obj) {
            dump_oid(i, obj);
        }
    }
}
