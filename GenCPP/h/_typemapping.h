/* 
 * This auto-generated file contains typemapping conversion fn
 * declarations for the data types found in Fabric2Arnold codegen file
 *  - Do not modify this file, it will be overwritten
 */


#pragma once

inline bool KLString_to_CPAtString(const Fabric::EDK::KL::String & from, AtString & to);
inline bool CPAtString_to_KLString(const AtString & from, Fabric::EDK::KL::String & to);
inline bool AtParamValue_to_KLParamValue(const AtParamValue* const & from, Fabric::EDK::KL::AtParamValue & to);

inline bool StringArr_to_AtEnum(const Fabric::EDK::KL::VariableArray< Fabric::EDK::KL::String > & from, AtEnum & to) { 
  #pragma message("Implement Me")
	return false;
}

inline bool AtEnum_to_StringArr(const AtEnum & from, Fabric::EDK::KL::VariableArray< Fabric::EDK::KL::String > & to) {
  #pragma message("Implement Me")
	return false;
}

inline bool KlAtLicenseInfo_to_AtLicenseInfo(const Fabric::EDK::KL::AtLicenseInfo & from, AtLicenseInfo* & to) { 
  // This function cannot be implemented.  We never convert _to_ AtLicenseInfo, it is a class
  // that should be returned from Arnold
  return false;
}

inline bool AtLicenseInfo_to_KLAtLicenseInfo(const AtLicenseInfo* const & from, Fabric::EDK::KL::AtLicenseInfo & to) {
	if (from != nullptr)
	{
		to.used = from->used;
		to.name = from->name;
		to.ver = from->ver;
		to.exp = from->exp;
		to.options = from->options;
		to.count = from->count;
		to.current_inuse = from->current_inuse;
		to.current_resuse = from->current_resuse;
		to.hbased = from->hbased;
		to.hold = from->hold;
		to.max_roam = from->max_roam;
		to.max_share = from->max_share;
		to.min_remove = from->min_remove;
		to.min_checkout = from->min_checkout;
		to.min_timeout = from->min_timeout;
		to.nres = from->nres;
		to.num_roam_allowed = from->num_roam_allowed;
		to.roaming = from->roaming;
		to.share = from->share;
		to.soft_limit = from->soft_limit;
		to.thisroam = from->thisroam;
		to.timeout = from->timeout;
		to.tz = from->tz;
		to.tokens = from->tokens;
		to.type = from->type;
		to.ubased = from->ubased;
	}
  return true; 
}

inline bool KLAtCameraOutput_to_CPAtCameraOutput(const Fabric::EDK::KL::AtCameraOutput & from, AtCameraOutput & to) { 
  #pragma message("Implement Me")
  return true;
}

inline bool CPAtCameraOutput_to_KLAtCameraOutput(const AtCameraOutput & from, Fabric::EDK::KL::AtCameraOutput & to) {
  #pragma message("Implement Me")
  return true; 
}

inline bool String_to_char(const Fabric::EDK::KL::String & from, char* & to) { 
	to = const_cast<char*>(from.c_str());
  return true;
}

inline bool char_to_String(const char* const & from, Fabric::EDK::KL::String & to) {
	to = from;
  return true; 
}

inline bool KlParamValue_to_AtParamValue(const Fabric::EDK::KL::AtParamValue & from, AtParamValue* & to) { 
    to = reinterpret_cast<AtParamValue*>(from.param_handle);
  return true;
}

inline bool AtParamValue_to_KLParamValue(const AtParamValue* const & from, Fabric::EDK::KL::AtParamValue & to) {
    to.param_handle = const_cast<AtParamValue*>(from);
  return true; 
}

inline bool Vec2_to_AtPoint2(const Fabric::EDK::KL::Vec2 & from, AtPoint2 & to) { 
    to.x = from.x;
    to.y = from.y;
  return true;
}

inline bool AtPoint2_to_Vec2(const AtPoint2 & from, Fabric::EDK::KL::Vec2 & to) {
    to.x = from.x;
    to.y = from.y;
  return true; 
}

inline bool Vec3_to_AtPoint(const Fabric::EDK::KL::Vec3 & from, AtPoint & to) { 
    to.x = from.x;
    to.y = from.y;
    to.z = from.z;
  return true;
}

inline bool AtPoint_to_Vec3(const AtPoint & from, Fabric::EDK::KL::Vec3 & to) {
    to.x = from.x;
    to.y = from.y;
    to.z = from.z;
  return true; 
}

inline bool KLColor_to_CPAtColor(const Fabric::EDK::KL::AtColor & from, AtColor & to) { 
    to.r = from.r;
    to.g = from.g;
    to.b = from.b;
  return true;
}

inline bool CPAtColor_to_KLColor(const AtColor & from, Fabric::EDK::KL::AtColor & to) {
    to.r = from.r;
    to.g = from.g;
    to.b = from.b;
    to.a = 1.0f;
  return true; 
}

inline bool Color_to_AtRGB(const Fabric::EDK::KL::Color & from, AtRGB & to) { 
    return KLColor_to_CPAtColor(from, to);
}
inline bool AtRGB_to_Color(const AtRGB & from, Fabric::EDK::KL::Color & to) {
    return CPAtColor_to_KLColor(from, to);
}

inline bool KLColor_to_CPAtRGBA(const Fabric::EDK::KL::AtRGBA & from, AtRGBA & to) { 
    to.a = from.a;
    to.r = from.r;
    to.g = from.g;
    to.b = from.b;
  return true;
}

inline bool CPAtRGBA_to_KLColor(const AtRGBA & from, Fabric::EDK::KL::AtRGBA & to) {
    to.a = from.a;
    to.r = from.r;
    to.g = from.g;
    to.b = from.b;
  return true;
}

inline bool Mat44_to_AtMatrix(const Fabric::EDK::KL::Mat44 & from, AtMatrix & to) { 
    to[0][0] = from.row0.x;
    to[1][0] = from.row0.y;
    to[2][0] = from.row0.z;
    to[3][0] = from.row0.t;

    to[0][1] = from.row1.x;
    to[1][1] = from.row1.y;
    to[2][1] = from.row1.z;
    to[3][1] = from.row1.t;

    to[0][2] = from.row2.x;
    to[1][2] = from.row2.y;
    to[2][2] = from.row2.z;
    to[3][2] = from.row2.t;

    to[0][3] = from.row3.x;
    to[1][3] = from.row3.y;
    to[2][3] = from.row3.z;
    to[3][3] = from.row3.t;
  return true;
}

inline bool AtMatrix_to_Mat44(const AtMatrix & from, Fabric::EDK::KL::Mat44 & to) {
    to.row0.x = from[0][0];
    to.row0.y = from[1][0];
    to.row0.z = from[2][0];
    to.row0.t = from[3][0];

    to.row1.x = from[0][1];
    to.row1.y = from[1][1];
    to.row1.z = from[2][1];
    to.row1.t = from[3][1];

    to.row2.x = from[0][2];
    to.row2.y = from[1][2];
    to.row2.z = from[2][2];
    to.row2.t = from[3][2];
    
    to.row3.x = from[0][3];
    to.row3.y = from[1][3];
    to.row3.z = from[2][3];
    to.row3.t = from[3][3];
  return true; 
}

inline bool KlAtShaderGlobals_to_AtShaderGlobals(const Fabric::EDK::KL::AtShaderGlobals & from, AtShaderGlobals* & to) { 

    to = reinterpret_cast<AtShaderGlobals*>(from._handle);
    // Sync any changed parameters
    to->x = from.x;                 
    to->y = from.y;                 
    to->sx = from.sx;                
    to->sy = from.sy;                
    to->si = from.si;                
    to->i = from.i;                 
    to->n = from.n;                 
    to->Rt = from.rt;                
    to->we = from.we;                
    to->transp_index = from.transp_index;      
    Vec3_to_AtPoint(from.ro, to->Ro);                
    Vec3_to_AtPoint(from.rd, to->Rd);
    to->Rl = from.rl;                
    to->tid = from.tid;               
    to->Rr = from.rr;                
    to->Rr_refl = from.rr_refl;           
    to->Rr_refr = from.rr_refr;           
    to->Rr_diff = from.rr_diff;           
    to->Rr_gloss = from.rr_gloss;          
    to->fhemi = from.fhemi;             
    to->time = from.time;              
    to->fi = from.fi;                
    KLAtNode_to_CPAtNode(from.op, to->Op);                
    KLAtNode_to_CPAtNode(from.proc, to->proc);              
    KLAtNode_to_CPAtNode(from.shader, to->shader);            
    //KLAtNode_to_CPAtNode(from.psg, to->psg);         
    KLAtBucket_to_CPAtBucket(from.bkt, to->bkt);               
    Vec3_to_AtPoint(from.po, to->Po);                
    Vec3_to_AtPoint(from.p, to->P);                 
    Vec3_to_AtPoint(from.dPdx, to->dPdx);              
    Vec3_to_AtPoint(from.dPdy, to->dPdy);              
    Vec3_to_AtPoint(from.N, to->N);                 
    Vec3_to_AtPoint(from.nf, to->Nf);                
    Vec3_to_AtPoint(from.ng, to->Ng);                
    Vec3_to_AtPoint(from.ngf, to->Ngf);               
    Vec3_to_AtPoint(from.ns, to->Ns);                
    to->bu = from.bu;                
    to->bv = from.bv;                
    to->u = from.u;                 
    to->v = from.v;                 
    Mat44_to_AtMatrix(from.m, to->M);                 
    Mat44_to_AtMatrix(from.minv, to->Minv);
    // We assume that we are returning an IO parameter
    // here, because we can't malloc a new lights array
    // In that case, most of this conversion is probably
    // moot, as this data shoudln't change anyway, but
    // for completeness we'll do what we can.
    if (to->nlights == from.lights.size())
    {
        for (int i = 0; i < to->nlights; i++)
        {
            KLAtNode_to_CPAtNode(from.lights[i], to->lights[i]);
        }
    }
    else
        return false; // Something is terribly wrong here.

    KLAtNode_to_CPAtNode(from.lp, to->Lp);                
    to->Ldist = from.ldist;             
    Vec3_to_AtPoint(from.ld, to->Ld);
    KLColor_to_CPAtColor(from.li, to->Li);
    KLColor_to_CPAtColor(from.liu, to->Liu);
    KLColor_to_CPAtColor(from.lo, to->Lo);
    KLColor_to_CPAtColor(from.ci, to->Ci);
    KLColor_to_CPAtColor(from.vo, to->Vo);                
    to->area = from.area;              
            
    Vec3_to_AtPoint(from.dPdu, to->dPdu);              
    Vec3_to_AtPoint(from.dPdv, to->dPdv);              
    Vec3_to_AtPoint(from.dDdx, to->dDdx);              
    Vec3_to_AtPoint(from.dDdy, to->dDdy);              
    Vec3_to_AtPoint(from.dNdx, to->dNdx);              
    Vec3_to_AtPoint(from.dNdy, to->dNdy);              
    to->dudx = from.dudx;              
    to->dudy = from.dudy;              
    to->dvdx = from.dvdx;              
    to->dvdy = from.dvdy;              

    AtParamValue *value;
    KlParamValue_to_AtParamValue(from.out, value);
    to->out = *value;

    KLColor_to_CPAtColor(from.out_opacity, to->out_opacity);
    to->inclusive_traceset = from.inclusive_traceset;
    to->skip_shadow = from.skip_shadow;       
    to->sc = from.sc;                
    KLString_to_CPAtString(from.traceset, to->traceset);

    return true;
}

inline bool AtShaderGlobals_to_KLAtShaderGlobals(const AtShaderGlobals* const & from, Fabric::EDK::KL::AtShaderGlobals & to) {

    to._handle = const_cast<AtShaderGlobals*>(from);
    // Sync parameters so we can view them from KL
    to.x = from->x;                 
    to.y = from->y;                 
    to.sx = from->sx;                
    to.sy = from->sy;                
    to.si = from->si;                
    to.i = from->i;                 
    to.n = from->n;                 
    to.rt = from->Rt;                
    to.we = from->we;                
    to.transp_index = from->transp_index;      
    AtPoint_to_Vec3(from->Ro, to.ro);                
    AtPoint_to_Vec3(from->Rd, to.rd);
    to.rl = from->Rl;                
    to.tid = from->tid;               
    to.rr = from->Rr;                
    to.rr_refl = from->Rr_refl;           
    to.rr_refr = from->Rr_refr;           
    to.rr_diff = from->Rr_diff;           
    to.rr_gloss = from->Rr_gloss;          
    to.fhemi = from->fhemi;             
    to.time = from->time;              
    to.fi = from->fi;                
    CPAtNode_to_KLAtNode(from->Op, to.op);                
    CPAtNode_to_KLAtNode(from->proc, to.proc);              
    CPAtNode_to_KLAtNode(from->shader, to.shader);            
    //CPAtNode_to_KLAtNode(from->psg, to.psg);         
    CPAtBucket_to_KLAtBucket(from->bkt, to.bkt);               
    AtPoint_to_Vec3(from->Po, to.po);                
    AtPoint_to_Vec3(from->P, to.p);                 
    AtPoint_to_Vec3(from->dPdx, to.dPdx);              
    AtPoint_to_Vec3(from->dPdy, to.dPdy);              
    AtPoint_to_Vec3(from->N, to.N);                 
    AtPoint_to_Vec3(from->Nf, to.nf);                
    AtPoint_to_Vec3(from->Ng, to.ng);                
    AtPoint_to_Vec3(from->Ngf, to.ngf);               
    AtPoint_to_Vec3(from->Ns, to.ns);                
    to.bu = from->bu;                
    to.bv = from->bv;                
    to.u = from->u;                 
    to.v = from->v;                 
    AtMatrix_to_Mat44(from->M, to.m);                 
    AtMatrix_to_Mat44(from->Minv, to.minv);

    to.lights.resize(from->nlights);
    for (int i = 0; i < from->nlights; i++)
    {
        CPAtNode_to_KLAtNode(from->lights[i], to.lights[i]);
    }

    CPAtNode_to_KLAtNode(from->Lp, to.lp);                
    to.ldist = from->Ldist;             
    AtPoint_to_Vec3(from->Ld, to.ld);
    CPAtColor_to_KLColor(from->Li, to.li);
    CPAtColor_to_KLColor(from->Liu, to.liu);
    CPAtColor_to_KLColor(from->Lo, to.lo);
    CPAtColor_to_KLColor(from->Ci, to.ci);
    CPAtColor_to_KLColor(from->Vo, to.vo);                
    to.area = from->area;              
            
    AtPoint_to_Vec3(from->dPdu, to.dPdu);              
    AtPoint_to_Vec3(from->dPdv, to.dPdv);              
    AtPoint_to_Vec3(from->dDdx, to.dDdx);              
    AtPoint_to_Vec3(from->dDdy, to.dDdy);              
    AtPoint_to_Vec3(from->dNdx, to.dNdx);              
    AtPoint_to_Vec3(from->dNdy, to.dNdy);              
    to.dudx = from->dudx;              
    to.dudy = from->dudy;              
    to.dvdx = from->dvdx;              
    to.dvdy = from->dvdy;              

    AtParamValue_to_KLParamValue(&from->out, to.out);

    CPAtColor_to_KLColor(from->out_opacity, to.out_opacity);
    to.inclusive_traceset = from->inclusive_traceset;
    to.skip_shadow = from->skip_shadow;       
    to.sc = from->sc;                
    CPAtString_to_KLString(from->traceset, to.traceset);

    return true;
}


inline bool KlAtRay_to_AtRay(const Fabric::EDK::KL::AtRay & from, AtRay & to) {
	to.type = from.type;
	to.tid = from.tid;
	to.level = from.level;
	to.diff_bounces = from.diff_bounces;
	to.gloss_bounces = from.gloss_bounces;
	to.refl_bounces = from.refl_bounces;
	to.refr_bounces = from.refr_bounces;
	to.x = from.x;
	to.y = from.y;
	to.sx = from.sx;
	to.sy = from.sy;
	to.px = from.px;
	to.py = from.py;
	Vec3_to_AtPoint(from.origin, to.origin);
	Vec3_to_AtPoint(from.dir, to.dir);

	to.mindist = from.mindist;
	to.maxdist = from.maxdist;

	// The ShaderGlobals struct is declared as const *
	// but we need a reference to the pointer that is non-const
	void* data = &to.psg;
	AtShaderGlobals *& topsg = reinterpret_cast<AtShaderGlobals *&>(data);
	KlAtShaderGlobals_to_AtShaderGlobals(from.psg, topsg);
	
	to.light_source = from.light_source;
	KLAtBucket_to_CPAtBucket(from.bucket, to.bucket);
	to.weight = from.weight;
	to.time = from.time;
	Vec3_to_AtPoint(from.dOdx, to.dOdx);
	Vec3_to_AtPoint(from.dOdy, to.dOdy);
	Vec3_to_AtPoint(from.dDdx, to.dDdx);
	Vec3_to_AtPoint(from.dDdy, to.dDdy);

	KLString_to_CPAtString(from.traceset, to.traceset);
	to.inclusive_traceset = from.inclusive_traceset;
	to.sindex = from.sindex;

  return true;
}

inline bool AtRay_to_KLAtRay(const AtRay & from, Fabric::EDK::KL::AtRay & to) {
  to.type = from.type;
  to.tid = from.tid;
  to.level = from.level;
  to.diff_bounces = from.diff_bounces;
  to.gloss_bounces = from.gloss_bounces;
  to.refl_bounces = from.refl_bounces;
  to.refr_bounces = from.refr_bounces;
  to.x = from.x;
  to.y = from.y;
  to.sx = from.sx;
  to.sy = from.sy;
  to.px = from.px;
  to.py = from.py;
  AtPoint_to_Vec3(from.origin, to.origin);
  AtPoint_to_Vec3(from.dir, to.dir);

  to.mindist = from.mindist;
  to.maxdist = from.maxdist;

  AtShaderGlobals_to_KLAtShaderGlobals(from.psg, to.psg);
  
  to.light_source = from.light_source;
  CPAtBucket_to_KLAtBucket(from.bucket, to.bucket);
  to.weight = from.weight;
  to.time = from.time;
  AtPoint_to_Vec3(from.dOdx, to.dOdx);
  AtPoint_to_Vec3(from.dOdy, to.dOdy);
  AtPoint_to_Vec3(from.dDdx, to.dDdx);
  AtPoint_to_Vec3(from.dDdy, to.dDdy);

  CPAtString_to_KLString(from.traceset, to.traceset);
  to.inclusive_traceset = from.inclusive_traceset;
  to.sindex = from.sindex;

  return true; 
}

inline bool KlAtMetaDataEntry_to_AtMetaDataEntry(const Fabric::EDK::KL::AtMetaDataEntry & from, AtMetaDataEntry* & to) { 
	// We should never need to construct our own entries.
	return false;
}

inline bool AtMetaDataEntry_to_KLAtMetaDataEntry(const AtMetaDataEntry* const & from, Fabric::EDK::KL::AtMetaDataEntry & to) {
	char_to_String(from->name, to.name);
	char_to_String(from->param, to.param);
	to.type = from->type;

	AtParamValue_to_KLParamValue(&from->value, to.value);
  return true; 
}

inline bool Box3_to_AtBBox(const Fabric::EDK::KL::Box3 & from, AtBBox & to) { 
	Vec3_to_AtPoint(from.max, to.max);
	Vec3_to_AtPoint(from.min, to.min);
  return true;
}

inline bool AtBBox_to_Box3(const AtBBox & from, Fabric::EDK::KL::Box3 & to) {
	AtPoint_to_Vec3(from.max, to.max);
	AtPoint_to_Vec3(from.min, to.min);
  return true; 
}

inline bool KLString_to_CPAtString(const Fabric::EDK::KL::String & from, AtString & to) { 
  to = AtString(from.c_str());
  return true;
}

inline bool CPAtString_to_KLString(const AtString & from, Fabric::EDK::KL::String & to) {
  to = from.c_str();
  return true; 
}

inline bool KlAtTextureParams_to_AtTextureParams(const Fabric::EDK::KL::AtTextureParams & from, AtTextureParams& to) { 
  to.filter = from.filter;
  to.mipmap_mode = from.mipmap_mode;
  to.mipmap_bias = from.mipmap_bias;
  to.single_channel = from.single_channel;
  to.start_channel = from.start_channel;
  to.fill = from.fill;
  to.flip_s = from.flip_s;
  to.flip_t = from.flip_t;
  to.swap_st = from.swap_st;
  to.scale_s = from.scale_s;
  to.scale_t = from.scale_t;
  to.wrap_s = from.wrap_s;
  to.wrap_t = from.wrap_t;
  to.width_s = from.width_s;
  to.width_t = from.width_t;
  to.blur_s = from.blur_s;
  to.blur_t = from.blur_t;
  return true;
}

inline bool AtTextureParams_to_KLAtTextureParams(const AtTextureParams & from, Fabric::EDK::KL::AtTextureParams & to) {
	to.filter = from.filter;
	to.mipmap_mode = from.mipmap_mode;
	to.mipmap_bias = from.mipmap_bias;
	to.single_channel = from.single_channel;
	to.start_channel = from.start_channel;
	to.fill = from.fill;
	to.flip_s = from.flip_s;
	to.flip_t = from.flip_t;
	to.swap_st = from.swap_st;
	to.scale_s = from.scale_s;
	to.scale_t = from.scale_t;
	to.wrap_s = from.wrap_s;
	to.wrap_t = from.wrap_t;
	to.width_s = from.width_s;
	to.width_t = from.width_t;
	to.blur_s = from.blur_s;
	to.blur_t = from.blur_t;
  return true; 
}

inline bool KLAtCameraInput_to_CPAtCameraInput(const Fabric::EDK::KL::AtCameraInput & from, AtCameraInput & to) { 
  #pragma message("Implement Me")
  return true;
}

inline bool CPAtCameraInput_to_KLAtCameraInput(const AtCameraInput & from, Fabric::EDK::KL::AtCameraInput & to) {
  #pragma message("Implement Me")
  return true; 
}

inline bool KLAtNodeLib_to_CPAtNodeLib(const Fabric::EDK::KL::AtNodeLib & from, AtNodeLib & to) { 
  #pragma message("Implement Me")
  return true;
}

inline bool CPAtNodeLib_to_KLAtNodeLib(const AtNodeLib & from, Fabric::EDK::KL::AtNodeLib & to) {
  #pragma message("Implement Me")
  return true; 
}

inline bool KlArray_to_AtArray(const Fabric::EDK::KL::AtArray & from, AtArray* & to) { 
	to = reinterpret_cast<AtArray*>(from.data);
  return true;
}

inline bool AtArray_to_KLArray(const AtArray* const & from, Fabric::EDK::KL::AtArray & to) {
	if (from != nullptr)
	{
		to.data = const_cast<AtArray*>(from);
		to.nelements = from->nelements;
		to.nkeys = from->nkeys;
		to.type = from->type;
	}
  return true; 
}

inline bool KlAtAOVEntry_to_AtAOVEntry(const Fabric::EDK::KL::AtAOVEntry & from, AtAOVEntry* & to) { 
	// We should never construct our own AOVEntries
  return false;
}

inline bool AtAOVEntry_to_KLAtAOVEntry(const AtAOVEntry* const & from, Fabric::EDK::KL::AtAOVEntry & to) {
	to.blend_mode = from->blend_mode;
	to.name = from->name;
	to.type = from->type;
  return true; 
}

