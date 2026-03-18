// ----------------------------------------------------------------------------
// func forward declarations
// ----------------------------------------------------------------------------
unique_ptr<Compound> parseCompound() ;
unique_ptr<Statement> parseStatement() ;
unique_ptr<Write> parseWrite() ;
unique_ptr<Block> parseBlock() ;