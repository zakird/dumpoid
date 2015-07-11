dumpoids
########

Utility that will dump out the OIDs from OpenSSL and Microsoft into a CSV file.


Building
########

Compile the one .c file::

    gcc dumpoids.c -lssl -lcrypto -o dumpoids
