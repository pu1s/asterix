

typedef struct sexagesimal_format_tag
{
	wchar_t			sign[2];
	wchar_t			deg_hrs[4];
	wchar_t			deg_hrs_symbol[10];
	wchar_t			min[3];
	wchar_t			min_symbol[10];
	wchar_t			sec[14];
	wchar_t			sec_symbol[10];
	wchar_t			suff[2];
	bool			space_enabled;
	unsigned short	sec_precision;
	bool			null_placeholder;
} asx_sexagesimal_format_tag;