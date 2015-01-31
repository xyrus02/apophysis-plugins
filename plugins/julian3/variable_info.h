typedef struct
{
	int isNonZero;
	int isCyclic;
	int isDiscrete;
	double min;
	double max;
} ExportVariableInfo;

#ifdef APO_NOVARIABLES
__declspec (dllexport) int PluginVarQueryVariableInfo(int index, void* result) 
{ 
	return 0;
}
#else
__declspec (dllexport) int PluginVarQueryVariableInfo(int index, void* result)
{
	int numVars;

	numVars	= PluginVarGetNrVariables();

    if (index < 0 || index >= numVars)
	{
		return 0;
	}

	ExportVariableInfo* info = (ExportVariableInfo*)result;

	switch (VarInfo[index].type)
	{
		case REAL:
			info->isNonZero = 0;
			info->isCyclic = 0;
			info->isDiscrete = 0;
			#ifdef _APOMSVC
				info->min = VarInfo[index].min;
				info->max = VarInfo[index].max;
			#else
				info->min = VarInfo[index].min.d;
				info->max = VarInfo[index].max.d;
			#endif
			
			break;
		case REAL_CYCLIC:
			info->isNonZero = 0;
			info->isCyclic = 1;
			info->isDiscrete = 0;
			#ifdef _APOMSVC
				info->min = VarInfo[index].min;
				info->max = VarInfo[index].max;
			#else
				info->min = VarInfo[index].min.d;
				info->max = VarInfo[index].max.d;
			#endif
			break;
		case INTEGER:
			info->isNonZero = 0;
			info->isCyclic = 0;
			info->isDiscrete = 1;
			#ifdef _APOMSVC
				info->min = VarInfo[index].min;
				info->max = VarInfo[index].max;
			#else
				info->min = VarInfo[index].min.i;
				info->max = VarInfo[index].max.i;
			#endif
			break;
		case INTEGER_NONZERO:
			info->isNonZero = 1;
			info->isCyclic = 0;
			info->isDiscrete = 1;
			#ifdef _APOMSVC
				info->min = VarInfo[index].min;
				info->max = VarInfo[index].max;
			#else
				info->min = VarInfo[index].min.i;
				info->max = VarInfo[index].max.i;
			#endif
			break;
		default:
			info->isNonZero = 0;
			info->isCyclic = 0;
			info->isDiscrete = 0;
			#ifdef _APOMSVC
				info->min = VarInfo[index].min;
				info->max = VarInfo[index].max;
			#else
				info->min = VarInfo[index].min.d;
				info->max = VarInfo[index].max.d;
			#endif
	}

	return 1;
}
#endif
