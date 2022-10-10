import Head from "next/head";
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
  PerfectScrollbar,
} from "@mui/material";
import { DashboardLayout } from "../components/dashboard-layout";
import { customers } from "../__mocks__/customers";
import { Search as SearchIcon } from "../icons/search";

const Page = () => (
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
              <Box sx={{ flexDirection: "row"}}>
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
                  placeholder="Search documents"
                  variant="outlined"
                />
                <Button variant="contained" startIcon={<SearchIcon />}>
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
                  {/* {customers.slice(0, limit).map((customer) => (
                      <TableRow
                        hover
                        key={customer.id}
                        selected={selectedCustomerIds.indexOf(customer.id) !== -1}
                      >
                        <TableCell padding="checkbox">
                          <Checkbox
                            checked={selectedCustomerIds.indexOf(customer.id) !== -1}
                            onChange={(event) => handleSelectOne(event, customer.id)}
                            value="true"
                          />
                        </TableCell>
                        <TableCell>
                          <Box
                            sx={{
                              alignItems: "center",
                              display: "flex",
                            }}
                          >
                            <Avatar src={customer.avatarUrl} sx={{ mr: 2 }}>
                              {getInitials(customer.name)}
                            </Avatar>
                            <Typography color="textPrimary" variant="body1">
                              {customer.name}
                            </Typography>
                          </Box>
                        </TableCell>
                        <TableCell>{customer.email}</TableCell>
                        <TableCell>
                          {`${customer.address.city}, ${customer.address.state}, ${customer.address.country}`}
                        </TableCell>
                        <TableCell>{customer.phone}</TableCell>
                        <TableCell>{format(customer.createdAt, "dd/MM/yyyy")}</TableCell>
                      </TableRow>
                    ))} */}
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

Page.getLayout = (page) => <DashboardLayout>{page}</DashboardLayout>;

export default Page;
