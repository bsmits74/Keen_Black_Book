GETNEWBLOCK;
mmhead = mmnew;			// this will always be the first node
mmnew->start = 0;
mmnew->length = segstart;
mmnew->attributes = LOCKBIT;
