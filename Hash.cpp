#include "Hash.h"

HashTable* OAHT_CreateHashTable( int TableSize )
{
    HashTable* HT = (HashTable*)malloc( sizeof(HashTable) );
    HT->Table     = (ElementType*)malloc( sizeof(ElementType) * TableSize);
    
    memset(HT->Table, 0, sizeof(ElementType) * TableSize );
    
    HT->TableSize = TableSize;
    HT->OccupiedCount = 0;
    
    return HT;
}

void OAHT_Set( HashTable** HT, KeyType Key, ValueType Value )
{
    int    KeyLen, Address, StepSize;
    
    KeyLen    = strlen(Key);
    Address   = OAHT_Hash( Key, KeyLen, (*HT)->TableSize );
    StepSize  = OAHT_Hash2( Key, KeyLen, (*HT)->TableSize );
    
    while ( (*HT)->Table[Address].Status != EMPTY &&
           strcmp((*HT)->Table[Address].Key, Key) != 0 )
    {
        
        Address = (Address + StepSize) % (*HT)->TableSize;
    }
    
    (*HT)->Table[Address].Key = (char*)malloc( sizeof(char) * (KeyLen + 1) );
    strcpy( (*HT)->Table[Address].Key, Key );
    
    (*HT)->Table[Address].Value = Value;
    
    (*HT)->Table[Address].Status = OCCUPIED;
    
    (*HT)->OccupiedCount++;
    
}

ValueType OAHT_Get( HashTable* HT, KeyType Key )
{
    int KeyLen    = strlen(Key);
    
    int Address   = OAHT_Hash( Key, KeyLen, HT->TableSize );
    int StepSize  = OAHT_Hash2( Key, KeyLen, HT->TableSize );
    
    while ( HT->Table[Address].Status != EMPTY &&
           strcmp(HT->Table[Address].Key, Key) != 0 )
    {
        Address = (Address + StepSize) % HT->TableSize;
    }
    
    return HT->Table[Address].Value;
}

void OAHT_ClearElement( ElementType* Element )
{
    if ( Element->Status == EMPTY)
        return;

    free(Element->Key);
}

void OAHT_DestroyHashTable( HashTable* HT)
{
    
    int i = 0;
    for ( i=0; i<HT->TableSize; i++ )
    {
        OAHT_ClearElement( &(HT->Table[i]) );
    }
    
    
    free ( HT->Table );
    free ( HT );
}

int OAHT_Hash( KeyType Key, int KeyLength, int TableSize )
{
    int i=0;
    long long HashValue = 0;
    
    for ( i=0; i<KeyLength; i++ )
    {
        int Abs = (Key[i] > 0) ? Key[i] : -Key[i];
        HashValue = (HashValue << 3) + Abs;
        HashValue = HashValue % TableSize;
    }
    
    
    return (int)HashValue;
}

int OAHT_Hash2( KeyType Key, int KeyLength, int TableSize )
{
    int i=0;
    long long HashValue = 0;
    
    for ( i=0; i<KeyLength; i++ )
    {
        int Abs = (Key[i] > 0) ? Key[i] : -Key[i];
        HashValue = (HashValue << 2) + Abs;
        HashValue = HashValue % ( TableSize - 3 );
    }
    
    return (int)HashValue + 1;
}