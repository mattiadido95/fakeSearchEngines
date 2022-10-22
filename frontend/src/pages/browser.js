import Head from "next/head";
import { useState, useEffect } from "react";
import {
  Container,
  Avatar,
  Box,
  Card,
  Checkbox,
  Table,
  TableBody,
  TableCell,
  TableHead,
  TablePagination,
  TableRow,
  Button,
  CardContent,
  TextField,
  InputAdornment,
  SvgIcon,
  IconButton,
} from "@mui/material";
import { DashboardLayout } from "../components/dashboard-layout";
import { customers } from "../__mocks__/customers";
import { Search as SearchIcon } from "../icons/search";
import documents from "../../../backend/server/data.json";
import ArrowForwardIcon from "@mui/icons-material/ArrowForward";
import axios from "axios";

const Page = () => {
  const [documentsList, setDocumentsList] = useState([]);

  useEffect(() => {}, []);

  const endpoint = "http://localhost:9080/list";

  const loadDocuments = () => {
    fetch(endpoint, {
      mode: "no-cors",
      method: "POST",
      headers: {
        "content-type": "application/json",
      },
    })
      .then((res) => res.json())
      .then((data) => {
        console.log(data);
        setDocumentsList(data);
      })
      .catch((err) => {
        console.log(err.message);
      });
  };

  /* const loadDocuments = () => {
    axios.post(endpoint).then((response) => {
      setDocumentsList(data);
    });
  }; */

  return (
    <>
      <Head>
        <title>Browser</title>
      </Head>
      <Box
        component="main"
        sx={{
          flexGrow: 1,
          py: 8,
        }}
      >
        <Container maxWidth={false}>
          <Box sx={{ mt: 3 }}>
            <Card>
              <CardContent>
                <Box sx={{ display: "flex", flexDirection: "row" }}>
                  <TextField
                    fullWidth
                    InputProps={{
                      startAdornment: (
                        <InputAdornment position="start">
                          <SvgIcon color="action" fontSize="small">
                            <SearchIcon />
                          </SvgIcon>
                        </InputAdornment>
                      ),
                    }}
                    placeholder="Search Documents"
                    variant="outlined"
                  />
                  <Button
                    size="small"
                    variant="text"
                    startIcon={<SearchIcon />}
                    onClick={() => loadDocuments()}
                  >
                    SEARCH
                  </Button>
                </Box>
              </CardContent>
            </Card>
          </Box>

          <Box sx={{ mt: 3 }}>
            <Card>
              <Box sx={{ minWidth: 1050 }}>
                <Table>
                  <TableHead>
                    <TableRow>
                      {/* <TableCell padding="checkbox">
                        <Checkbox
                          checked={selectedCustomerIds.length === customers.length}
                          color="primary"
                          indeterminate={
                            selectedCustomerIds.length > 0 &&
                            selectedCustomerIds.length < customers.length
                          }
                          onChange={handleSelectAll}
                        />
                      </TableCell> */}
                      <TableCell>Doc ID</TableCell>
                      <TableCell>Document Title</TableCell>
                      <TableCell>Preview</TableCell>
                      <TableCell>Action</TableCell>
                    </TableRow>
                  </TableHead>
                  <TableBody>
                    {documentsList.map((document) => (
                      <TableRow
                        hover
                        key={document?.doc_id}
                        /* selected={selectedCustomerIds.indexOf(customer.id) !== -1} */
                      >
                        {/* <TableCell padding="checkbox">
                          <Checkbox
                           checked={selectedCustomerIds.indexOf(customer.id) !== -1}
                            onChange={(event) => handleSelectOne(event, customer.id)}
                            value="true"
                          />
                        </TableCell> */}

                        <TableCell>{document?.doc_id}</TableCell>
                        <TableCell>{document?.document_title}</TableCell>
                        <TableCell>{document?.about}</TableCell>
                        <TableCell>
                          <IconButton color="primary" aria-label="upload picture" component="label">
                            <ArrowForwardIcon />
                          </IconButton>
                        </TableCell>
                      </TableRow>
                    ))}
                  </TableBody>
                </Table>
              </Box>

              <TablePagination
                component="div"
                count={100}
                /* onPageChange={handlePageChange} */
                /* onRowsPerPageChange={handleLimitChange} */
                page={10}
                rowsPerPage={10}
                rowsPerPageOptions={[5, 10, 25]}
              />
            </Card>
          </Box>
        </Container>
      </Box>
    </>
  );
};

Page.getLayout = (page) => <DashboardLayout>{page}</DashboardLayout>;

export default Page;
