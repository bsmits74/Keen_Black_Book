GETNEWBLOCK;
mmhead = mmnew;			// this will allways be the first node
mmnew->start = 0;
mmnew->length = segstart;
mmnew->attributes = LOCKBIT;
