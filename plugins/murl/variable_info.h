typedef struct
{
	int isNonZero;
	int isCyclic;
	int isDiscrete;
	double min;
	double max;
} ExportVariableInfo;

APO_EXPORT int PluginVarQueryVariableInfo(int index, void* result)
{
	int numVars = PluginVarGetNrVariables();

    if (index < 0 || index >= numVars)
	{
		return FALSE;
	}

	ExportVariableInfo* info = (ExportVariableInfo*)result;

	info->min = VarInfo[index].min;
	info->max = VarInfo[index].max;

	switch (VarInfo[index].type)
	{
		case REAL:
			info->isNonZero = false;
			info->isCyclic = false;
			info->isDiscrete = false;
			break;
		case REAL_CYCLIC:
			info->isNonZero = false;
			info->isCyclic = true;
			info->isDiscrete = false;
			break;
		case INTEGER:
			info->isNonZero = false;
			info->isCyclic = false;
			info->isDiscrete = true;
			break;
		case INTEGER_NONZERO:
			info->isNonZero = true;
			info->isCyclic = false;
			info->isDiscrete = true;
			break;
		default:
			info->isNonZero = false;
			info->isCyclic = false;
			info->isDiscrete = false;
	}

	return TRUE;
}
