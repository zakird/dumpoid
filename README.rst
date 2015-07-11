dumpoids
########

Utility that will dump out the OIDs from OpenSSL and Microsoft into a CSV file.


Building
########

Compile the one .c file::

    gcc dumpoid.c -lssl -lcrypto -o dumpoids
