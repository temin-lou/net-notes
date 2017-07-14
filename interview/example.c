int CatImag_getNextSearchResults( 
        void *search_handle,
        FILE_ENTRY **fentries,
        size_t max_entries,
        size_t& num_entries )
{
    NBE_ErrorHandler::NBE_SetLastError(NULL, NULL, 0, 0);
    try
    {
        SearchHandle *sh = (SearchHandle *) search_handle;
        if ( !fentries || !sh || !(sh->m_fp) || !(sh->m_analyzed_pattern) )
            throw NBE_ErrorHandler(__FILE__, "CatImag_getNextSearchResults", __LINE__, NBE_ERROR_NULL_);
        NBE_CatFile *catfile = NBE_CatFile_Factory::getNBE_CatFileFromCatImg_FILE(sh->m_fp);
        int result = catfile->getNextSearchResults(sh, fentries, max_entries, num_entries);
        return result;
    }
    catch (const NBE_ErrorHandler &e)
    {
        NBE_ErrorHandler::NBE_SetLastError(e);
        return -1;
    }
}
